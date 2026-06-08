/*
    Subsystem.cpp

    Implementation of a subsystem class, in charge of initialization and shutdown.
*/

#include "Core/System/Subsystem.hpp"
#include "Logging/Logger.hpp"
#include "Utility/Timer.hpp"
#include <format>

Subsystem::Subsystem(const std::string& name)
    : NAME_(name) {}

void Subsystem::init() {
    // Ignore if already initialized
    if (isInitialized())
        return;

    // Start timer
    Timer timer;

    // Run initialization logic
    onInit();
    setState(SubsystemState::INITIALIZED);

    // Send format
    ENGINE_INFO(CORE, std::format(
        "Initialized {} in {} ms",
        name(),
        timer.milliseconds()
    ));
}

void Subsystem::shutdown() {
    // Ignore if already shutdown
    if (!isInitialized())
        return;

    // Start timer
    Timer timer;

    // Run shutdown logic
    onShutdown();
    setState(SubsystemState::UNINITIALIZED);

    // Send format
    ENGINE_INFO(CORE, std::format(
        "Shutdown {} in {} ms",
        name(),
        timer.milliseconds()
    ));
}

void Subsystem::setState(SubsystemState state) {
    state_ = state;
}

const std::vector<size_t>& Subsystem::dependencies() const {
    return dependencies_;
}

bool Subsystem::isInitialized() const {
    return state_ == SubsystemState::INITIALIZED;
}

const std::string& Subsystem::name() const {
    return NAME_;
}
