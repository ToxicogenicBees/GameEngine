/*
    FixedUpdateListener.cpp

    Implementation for a RunService onFixedUpdate listener.
*/

#include "Events/Listeners/FixedUpdateListener.hpp"
#include "Core/RunService.hpp"

void FixedUpdateListener::bindFixedUpdate() {
    connection_ = 
        RunService::onFixedUpdate().connect([this](double dt) {
            onFixedUpdate(dt);
        });
}
