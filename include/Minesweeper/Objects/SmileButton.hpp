/*
    SmileButton.hpp

    Declaration for the minesweeper smile button
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>

enum class SmileState {
    PLAYING,
    THINKING,
    WIN,
    LOSE
};

class SmileButton : public GameObject {
private:
    SpriteComponent* sprite_;
    SmileState state_;
    bool dirty_ = false;

    /**
     * @brief Sets the appropriate tile texture based on it's state
     */
    void updateTexture_();

    /**
     * @brief Custom intialization logic
     */
    void onInit() override;

    /**
     * @brief Custom update logic
     * 
     * @param dt Time since update
     */
    void onUpdate(double dt) override;

public:
    SmileButton();

    void setState(SmileState state);
};
