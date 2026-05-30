/*
    SmileButton.hpp

    Declaration for the minesweeper smile button
*/

#pragma once

#include <Core/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include <Components/BoxCollider2D.hpp>

enum class SmileState {
    PLAYING,
    THINKING,
    PRESSED,
    WIN,
    LOSE
};

class SmileButton : public GameObject {
private:
    SpriteComponent* sprite_;
    BoxCollider2D* collider_;
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
