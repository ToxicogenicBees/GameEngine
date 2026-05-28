/*
    IntermediateBoard.cpp

    Implementation for a minesweeper game scene
*/

#include "Minesweeper/Scenes/IntermediateBoard.hpp"
#include "Minesweeper/Generators/RandomGenerator.hpp"
#include <Core/Services.hpp>
#include <algorithm>
#include <iostream>

namespace {
    const Vector2 TILE_OFFSET{-118, 96};
    const Size BOARD_SIZE = {16, 16};
    const size_t MINES = 40;
}

TileObject* IntermediateBoard::tileAt_(const Vector2& mouse_pos) {
    auto world_pos = camera().screenToWorld(mouse_pos);
    for (auto& tile : tiles_) {
        if (tile->getComponent<BoxCollider2D>()->contains(world_pos)) {
            return tile;
        }
    }
    return nullptr;
}

TileObject* IntermediateBoard::tileWithIndex_(const Vector2i& index) {
    for (auto& tile : tiles_) {
        if (tile->index() == index)
            return tile;
    }
    return nullptr;
}

void IntermediateBoard::onLeftClick_(const Vector2i& mouse_pos) {
    auto tile = tileAt_(mouse_pos);
    
    if (!tile)
        return;

    auto index = tile->index();
    
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

        auto hidden_mines = board_.filterTiles([this](const Vector2i& index) {
            return !board_.isRevealed(index) && board_.isMine(index) && !board_.isFlagged(index);
        });
        auto false_flags = board_.filterTiles([this](const Vector2i& index) {
            return !board_.isMine(index) && board_.isFlagged(index);
        });

        for (auto& tile : false_flags) {
            tileWithIndex_(tile)->setState(TileState::FALSE_FLAGGED);
        }
    }
}

void IntermediateBoard::onRightClick_(const Vector2i& mouse_pos) {
    auto tile = tileAt_(mouse_pos);

    if (!tile)
        return;

    auto index = tile->index();
    if (board_.isFlagged(index))
        board_.unflag(index);
    else if (!board_.isRevealed(index))
        board_.flag(index);
}

void IntermediateBoard::updateMineCount_() {
    int flag_count = (int)board_.flagCount();
    int mine_count = (int)board_.mineCount();
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

void IntermediateBoard::updateTimer_(double dt) {
    elapsed_time_ += dt;
    int time = elapsed_time_;

    if (time > 999)
        time = 999;
    
    timer_[0]->setValue(CounterValue((time % 1000) / 100));
    timer_[1]->setValue(CounterValue((time % 100) / 10));
    timer_[2]->setValue(CounterValue((time % 10) / 1));
}

void IntermediateBoard::resetTimer_() {
    elapsed_time_ = 0;
    updateTimer_(0);
}

void IntermediateBoard::generateBoard_() {
    // Generate board
    RandomGenerator generator;
    board_ = generator.generate(BOARD_SIZE, MINES);

    // Set tile values
    for (const auto& index : board_.allTiles()) {
        auto tile = tileWithIndex_(index);
        tile->setState(TileState::HIDDEN);
        if (board_.isMine(index))
            tile->setValue(TileValue::MINE);
        else
            tile->setValue((TileValue)board_.adjacentMineCount(index));
    }

    // Connect events
    board_.onTileRevealed().connect([this](const Vector2i& index) {
        tileWithIndex_(index)->setState(TileState::PLAYER_SHOWN);
    });
    board_.onTileExposed().connect([this](const Vector2i& index) {
        auto tile = tileWithIndex_(index);
        if (board_.isFlagged(index))
            tile->setState(TileState::FALSE_FLAGGED);
        else
            tile->setState(TileState::GAME_SHOWN);
    });
    board_.onTileFlagged().connect([this](const Vector2i& index) {
        tileWithIndex_(index)->setState(TileState::FLAGGED);
        updateMineCount_();
    });
    board_.onTileUnflagged().connect([this](const Vector2i& index) {
        tileWithIndex_(index)->setState(TileState::HIDDEN);
        updateMineCount_();
    });

    // Reset counters
    updateMineCount_();
    resetTimer_();
}

IntermediateBoard::IntermediateBoard() {
    // Create board
    background_ = create<BoardObject>();

    // Create smile
    smile_ = create<SmileButton>();
    smile_->transform().position = {2, 131.5};

    // Create mine display
    for (int i = 0; i < 3; ++i)
        counter_[i] = create<Counter>();
    counter_[0]->transform().position = {-114, 132};
    counter_[1]->transform().position = {-101, 132};
    counter_[2]->transform().position = {-88, 132};

    // Create flag display
    for (int i = 0; i < 3; ++i)
        timer_[i] = create<Counter>();
    timer_[0]->transform().position = {91, 132};
    timer_[1]->transform().position = {104, 132};
    timer_[2]->transform().position = {117, 132};

    // Create tiles
    for (size_t y = 0; y < BOARD_SIZE.height(); ++y) {
        for (size_t x = 0; x < BOARD_SIZE.width(); ++x) {
            auto tile = create<TileObject>(Vector2i(x, y));
            tile->transform().position = TILE_OFFSET + (int)TileObject::tileSize() * Vector2i(x, -y);
            tiles_.push_back(tile);
        }
    }

    // Generate board
    generateBoard_();
}

void IntermediateBoard::onInit() {
    // Set window size
    auto background_size = background_->getComponent<SpriteComponent>()->size();
    Services::renderer()->setLogicalSize(background_size.width(), background_size.height());
    Services::window()->setSize(1.5 * background_size);
}

void IntermediateBoard::onUpdate(double dt) {
    auto playing = !board_.isCleared() && !board_.isLost();
    auto mouse_pos = Services::input()->mousePosition();
    auto world_pos = camera().screenToWorld(mouse_pos);

    if (playing) {
        // Handle input
        auto mouse_pos = Services::input()->mousePosition();
        if (Services::input()->wasReleased(MouseButton::LEFT))
            onLeftClick_(mouse_pos);
        else if (Services::input()->wasPressed(MouseButton::RIGHT))
            onRightClick_(mouse_pos);
        
        // Update timer
        updateTimer_(dt);
    }

    if (Services::input()->wasReleased(MouseButton::LEFT)
        && smile_->getComponent<BoxCollider2D>()->contains(world_pos))
    {
        generateBoard_();
    }
}
