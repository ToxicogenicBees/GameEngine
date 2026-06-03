/*
    UpdateListener.hpp

    Declaration for a RunService onUpdate listener.
*/

#pragma once

#include "Events/ScriptConnection.hpp"

class UpdateListener {
private:
    ScriptConnection connection_;

protected:
    /**
     * @brief Custom update logic.
     * 
     * @param dt Time since last update.
     */
    virtual void onUpdate(double dt) = 0;

public:
    /**
     * @brief Constructor.
     */
    UpdateListener() = default;

    /**
     * @brief Binds the fixed update event.
     */
    void bindUpdate();

    /**
     * @brief Destructor.
     */
    virtual ~UpdateListener() = default;
};
