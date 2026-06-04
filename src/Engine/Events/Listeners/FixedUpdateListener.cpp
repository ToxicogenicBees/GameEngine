/*
    FixedUpdateListener.cpp

    Implementation for a RunService onFixedUpdate listener.
*/

#include "Events/Listeners/FixedUpdateListener.hpp"
#include "Core/Services.hpp"

void FixedUpdateListener::bindFixedUpdate() {
    connection_ = 
        Services::runService()->onFixedUpdate().connect([this](double dt) {
            onFixedUpdate(dt);
        });
}
