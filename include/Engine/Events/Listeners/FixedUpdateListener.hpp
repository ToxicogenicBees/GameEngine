/*
    FixedUpdateListener.hpp

    Declaration for a RunService onFixedUpdate listener.
*/

#pragma once

#include "Events/ScriptConnection.hpp"

class FixedUpdateListener {
private:
    ScriptConnection connection_;

protected:
    /**
     * @brief Custom fixed update logic.
     * 
     * @param dt Time since last update.
     */
    virtual void onFixedUpdate(double dt) = 0;

public:
    /**
     * @brief Constructor.
     */
    FixedUpdateListener() = default;

    /**
     * @brief Binds the fixed update event.
     */
    void bindFixedUpdate();

    /**
     * @brief Destructor.
     */
    virtual ~FixedUpdateListener() = default;
};
