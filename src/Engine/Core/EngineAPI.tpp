/*
    EngineAPI.tpp

    Template implementation for a safe engine wrapper for applications
*/

#include "Core/EngineAPI.hpp"

template<typename T, typename... Args>
void EngineAPI::setScene(Args&&... args) {
    engine_.scene_manager_.loadScene<T>(args...);
}
