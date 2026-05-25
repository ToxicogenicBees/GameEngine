/*
    IntermediateBoard.cpp

    Implementation for a minesweeper game scene
*/

#include "Minesweeper/Scenes/IntermediateBoard.hpp"
#include <Core/Services.hpp>
#include <algorithm>

namespace {
    const Vector2 TILE_OFFSET{-118, -96}; 

    // SMILE: 128, 16
}

void IntermediateBoard::onLeftClick_(const Vector2i& mouse_pos) {
    auto tile = board_->tileAt(mouse_pos);

    if (!tile)
        return;
    
    // Reveal hidden tile
    if (!tile->isRevealed() && !tile->isFlagged())
        tile->reveal();

    // Reveal neighbors if total flags == value
    else if(tile->isRevealed() && (tile->neighboringFlags() == (int)tile->value()))
        tile->revealNeighbors();
}

void IntermediateBoard::onRightClick_(const Vector2i& mouse_pos) {
    auto tile = board_->tileAt(mouse_pos);
    if (tile)
        tile->isFlagged() ? tile->unflag() : tile->flag();
}

void IntermediateBoard::setCount_(int count) {
    auto count_mag = std::abs(count);

    counter_[0]->setValue(CounterValue((count % 1000) / 100));
    counter_[1]->setValue(CounterValue((count % 100) / 10));
    counter_[2]->setValue(CounterValue((count % 10) / 1));

    if (count_mag != count)
        counter_[0]->setValue(CounterValue::DASH);
}

void IntermediateBoard::setTimer_(int time) {
    timer_[0]->setValue(CounterValue((time % 1000) / 100));
    timer_[1]->setValue(CounterValue((time % 100) / 10));
    timer_[2]->setValue(CounterValue((time % 10) / 1));
}

IntermediateBoard::IntermediateBoard() {
    // Create board
    board_ = create<RandomBoard>();

    // Create smile
    smile_ = create<SmileButton>();
    smile_->transform().position = {2, -131.5};

    // Create mine display
    for (int i = 0; i < 3; ++i)
        counter_[i] = create<Counter>();
    counter_[0]->transform().position = {-114, -132};
    counter_[1]->transform().position = {-101, -132};
    counter_[2]->transform().position = {-88, -132};

    // Create flag display
    for (int i = 0; i < 3; ++i)
        timer_[i] = create<Counter>();
    timer_[0]->transform().position = {91, -132};
    timer_[1]->transform().position = {104, -132};
    timer_[2]->transform().position = {117, -132};

    // Generate board
    auto creator = [this]() {return create<Tile>();};
    auto destroyer = [this](Tile* tile) {destroy(tile);};
    board_->generate({16, 16}, 40, creator, destroyer);

    for (auto& tile : board_->tiles())
        tile->transform().position += TILE_OFFSET;
}

void IntermediateBoard::onInit() {
    // Set window size
    auto board_size = board_->getComponent<SpriteComponent>()->size();
    Services::renderer()->setLogicalSize(board_size);
    Services::window()->setSize(1.5 * board_size);
}

void IntermediateBoard::onUpdate(double dt) {
    auto won = board_->isCleared();
    auto lost = board_->isLost();
    auto playing = !won && !lost;

    if (playing) {
        // Handle input
        auto mouse_pos = Services::input()->mousePosition();
        if (Services::input()->wasReleased(MouseButton::LEFT))
            onLeftClick_(mouse_pos);
        else if (Services::input()->wasReleased(MouseButton::RIGHT))
            onRightClick_(mouse_pos);
        
        // Update timer
        elapsed_time_ += dt;
        setTimer_((int)elapsed_time_);

        // Update mine count
        int flag_count = (int)board_->flagCount();
        int mine_count = (int)board_->mineCount();
        setCount_(mine_count - flag_count);
    }

    else if (won){
        smile_->setState(SmileState::WIN);
    }
    else if (lost) {
        smile_->setState(SmileState::LOSE);
        board_->expose();
    }
}
