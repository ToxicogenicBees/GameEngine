/*
    UpdateListener.cpp

    Implementation for a RunService onUpdate listener.
*/

#include "Events/Listeners/UpdateListener.hpp"
#include "Core/RunService.hpp"

void UpdateListener::bindUpdate() {
    connection_ = 
        RunService::onUpdate().connect([this](double dt) {
            onUpdate(dt);
        });
}
