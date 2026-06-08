/*
    TileableBoard.cpp

    Implementation for a minesweeper board scene that is composed of tileable objects, allowing for arbitrary board sizes.
*/

#include "Minesweeper/Game/Scenes/TileableBoard.hpp"
#include "Minesweeper/Generators/RandomGenerator.hpp"
#include <Resources/Types/Texture.hpp>
#include <Geometry/Size.hpp>
#include <Core/Services.hpp>
#include <format>

namespace {
    constexpr int TILE_SIZE = 16;
    const Size COUNTER_SIZE(16, 32);
}

void TileableBoard::onInit() {
    // Set window size
    auto window_size = TILE_SIZE * Size(WALL_SIZE_.width(), WALL_SIZE_.height());
    Services::renderer()->setLogicalSize(window_size.width(), window_size.height());
    Services::window()->setSize(1.5 * window_size);

    // Connect input events
    connections_.push_back(Services::input()->onMousePressed().connect([this](MouseButton button, const Vector2& mouse_pos) {
        if (button == MouseButton::RIGHT && !board_.isCleared() && !board_.isLost())
            onRightClick_(mouse_pos);
    }));

    connections_.push_back(Services::input()->onMouseReleased().connect([this](MouseButton button, const Vector2& mouse_pos) {
        if (button == MouseButton::LEFT) {
            if (!board_.isCleared() && !board_.isLost())
                onLeftClick_(mouse_pos);

            // Reset board if the smile is clicked
            auto world_pos = camera().screenToWorld(mouse_pos);
            if (smile_->getComponent<BoxCollider2D>()->contains(world_pos))
                reset_();
        }
    }));

    // Initialize mine counter
    int count = std::min(static_cast<int>(MINE_COUNT_), 999);
    counter_[0]->setValue(CounterValue((MINE_COUNT_ % 1000) / 100));
    counter_[1]->setValue(CounterValue((MINE_COUNT_ % 100) / 10));
    counter_[2]->setValue(CounterValue((MINE_COUNT_ % 10) / 1));

    // Bind update events
    bindUpdate();
}

void TileableBoard::onUpdate(double dt) {
    // Update timer if still playing
    if (!board_.isCleared() && !board_.isLost())
        updateTimer_(dt);
}

TileObject* TileableBoard::tileAt_(const Vector2& screen_pos) {
    auto world_pos = camera().screenToWorld(screen_pos);
    for (auto& tile : tiles_) {
        if (tile->getComponent<BoxCollider2D>()->contains(world_pos)) {
            return tile;
        }
    }
    return nullptr;
}

void TileableBoard::onLeftClick_(const Vector2i& mouse_pos) {
    auto tile = tileAt_(mouse_pos);
    
    if (!tile)
        return;

    // Get tile index
    auto index = tile->index();

    // Generate board if required
    if (board_.isEmpty()) {
        RandomGenerator generator;
        board_.generateAt(generator, index);
    }
        
    // Reveal hidden tile
    if (!board_.isRevealed(index) && !board_.isFlagged(index))
        board_.reveal(index);

    // Reveal neighbors if total flags == value
    else if (board_.isRevealed(index) && (board_.adjacentFlagCount(index) == board_.revealedNumber(index))) {
        for (auto& neighbor : board_.neighbors(tile->index())) {
            if (!board_.isFlagged(neighbor))
                board_.reveal(neighbor);
        }
    }
    
    // Check board state
    if (board_.isCleared()){
        // Player won
        smile_->setState(SmileState::WIN);
    }
    else if (board_.isLost()) {
        // Player lost
        smile_->setState(SmileState::LOSE);
    }

    // Update mine count
    updateMineCount_();
}

void TileableBoard::onRightClick_(const Vector2i& mouse_pos) {
    auto tile = tileAt_(mouse_pos);

    if (!tile)
        return;

    // Flag appropriate tile
    auto index = tile->index();
    if (board_.isFlagged(index))
        board_.unflag(index);
    else if (!board_.isRevealed(index))
        board_.flag(index);

    // Update mine count
    updateMineCount_();
}

void TileableBoard::updateMineCount_() {
    int flag_count = static_cast<int>(board_.flagCount());
    int mine_count = static_cast<int>(board_.mineCount());
    int count = mine_count - flag_count;
    auto count_mag = std::abs(count);

    if (count < -99)
        count = -99;
    else if (count > 999)
        count = 999;

    counter_[0]->setValue(CounterValue((count_mag % 1000) / 100));
    counter_[1]->setValue(CounterValue((count_mag % 100) / 10));
    counter_[2]->setValue(CounterValue((count_mag % 10) / 1));

    if (count_mag != count)
        counter_[0]->setValue(CounterValue::DASH);
}

void TileableBoard::updateTimer_(double dt) {
    elapsed_time_ += dt;
    int time = elapsed_time_;

    if (time > 999)
        time = 999;
    
    timer_[0]->setValue(CounterValue((time % 1000) / 100));
    timer_[1]->setValue(CounterValue((time % 100) / 10));
    timer_[2]->setValue(CounterValue((time % 10) / 1));
}

void TileableBoard::resetTimer_() {
    elapsed_time_ = 0.0;
    updateTimer_(0.0);
}

void TileableBoard::reset_() {
    // Reset the board
    board_.reset();
    
    // Reset counters
    updateMineCount_();
    resetTimer_();
}

void TileableBoard::generateWalls_() {
    // Destroy old walls
    for (auto& wall : walls_)
        destroy(wall);

    // Create all of the walls
    int width = WALL_SIZE_.width();
    int height = WALL_SIZE_.height();

    auto load_walls = [this](const std::string& name, size_t count) {
        auto texture_name = std::format("textures/walls/wall{}.png", name);
        auto texture = Services::resources()->load<Texture>(texture_name);
        for (size_t i = 0; i < count; ++i)
            walls_.push_back(create<WallObject>(texture));
    };

    // Layer 1
    load_walls("1", 1);
    load_walls("5", width - 2);
    load_walls("2", 1);

    // Layers 2 + 3
    for (size_t i = 0; i < 2; ++i) {
        load_walls("6", 1);
        load_walls("0", 3);
        load_walls("7", 1);
        load_walls("0", width - 10);
        load_walls("8", 1);
        load_walls("0", 3);
        load_walls("6", 1);
    }

    // Layer 4
    load_walls("9", 1);
    load_walls("5", width - 2);
    load_walls("10", 1);

    // Layers 5 to (N - 1)
    for (size_t i = 0; i < height - 5; ++i) {
        load_walls("6", 1);
        load_walls("0", width - 2);
        load_walls("6", 1);
    }

    // Layer N
    load_walls("4", 1);
    load_walls("5", width - 2);
    load_walls("3", 1);

    // Place walls into their grid positions
    auto offset = Vector2(
        -0.5 * TILE_SIZE * (width - 1),
        0.5 * TILE_SIZE * (height - 1)
    );
    for (int i = 0; i < walls_.size(); ++i) {
        auto pos = TILE_SIZE * Vector2(
            i % width,
            -i / width
        );
        walls_[i]->transform().position() = pos + offset;
    }
}

TileableBoard::TileableBoard(const Size& size, size_t mine_count)
    : MINE_COUNT_(mine_count),
      BOARD_SIZE_(size),
      WALL_SIZE_(size.width() + 2, size.height() + 5),
      board_(BOARD_SIZE_, MINE_COUNT_)
{
    // Find top-left corner of the screen
    auto corner = Vector2(
        -0.5 * TILE_SIZE * WALL_SIZE_.width(),
        0.5 * TILE_SIZE * WALL_SIZE_.height()
    );

    // Generate walls
    generateWalls_();

    // Generate tiles
    auto tile_offset = corner + TILE_SIZE * Vector2(1.5, -4.5);
    for (int y = 0; y < BOARD_SIZE_.height(); ++y) {
        for (int x = 0; x < BOARD_SIZE_.width(); ++x) {
            auto tile = create<TileObject>(&board_, Vector2i(x, y));
            tile->transform().position() = tile_offset + TILE_SIZE * Vector2i(x, -y);
            tiles_.push_back(tile);
        }
    }

    // Generate smile button
    smile_ = create<SmileButton>();
    smile_->transform().position() = Vector2(0, corner.y - 2 * TILE_SIZE);

    // Create mine display
    auto mine_counter_pos = corner + Vector2(24, -32);
    for (int i = 0; i < 3; ++i) {
        counter_[i] = create<Counter>();
        counter_[i]->transform().position() = mine_counter_pos + Vector2(static_cast<double>(COUNTER_SIZE.width()) * i, 0);
    }

    // Create timer display
    auto timer_pos = corner + Vector2((WALL_SIZE_.width() - 4) * TILE_SIZE + 8, -32);
    for (int i = 0; i < 3; ++i) {
        timer_[i] = create<Counter>();
        timer_[i]->transform().position() = timer_pos + Vector2(static_cast<double>(COUNTER_SIZE.width()) * i, 0);
    }
}
