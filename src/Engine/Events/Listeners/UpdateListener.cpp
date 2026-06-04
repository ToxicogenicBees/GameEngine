/*
    UpdateListener.cpp

    Implementation for a RunService onUpdate listener.
*/

#include "Events/Listeners/UpdateListener.hpp"
#include "Core/Services.hpp"

void UpdateListener::bindUpdate() {
    connection_ = 
        Services::runService()->onUpdate().connect([this](double dt) {
            onUpdate(dt);
        });
}
