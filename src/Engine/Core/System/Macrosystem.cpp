/*
    Macrosystem.cpp

    Implementation of a macrosystem class, a special subsystem that is in charge of other subsystems.
*/

#include "Core/System/Macrosystem.hpp"
#include "Logging/Logger.hpp"
#include "Utility/Timer.hpp"
#include <queue>

std::vector<size_t> Macrosystem::resolveOrder_() {
    // Fetch nodes without dependencies
    std::queue<size_t> q;
    for (auto& [id, deg] : indegree_) {
        if (deg == 0)
            q.push(id);
    }
    
    // Process
    std::vector<size_t> order;
    while (!q.empty()) {
        size_t current = q.front();
        q.pop();

        order.push_back(current);

        // Visit dependents
        auto it = reverse_graph_.find(current);
        if (it != reverse_graph_.end()) {
            for (size_t dependent : it->second) {
                if (--indegree_[dependent] == 0)
                    q.push(dependent);
            }
        }
    }

    // Cycle detection
    if (order.size() != nodes_.size())
        ENGINE_FATAL(CORE, "Circular subsystem dependency detected");

    return order;
}

Macrosystem::Macrosystem(const std::string& name)
    : Subsystem(name) {}

void Macrosystem::init() {
    // Ignore if already initialized
    if (isInitialized())
        return;

    // Start timer
    Timer timer;

    // Run initialization logic for subsystems
    auto order = resolveOrder_();
    for (auto id : order)
        nodes_[id]->init();

    // Send log
    ENGINE_INFO(CORE, std::format(
        "Initialized {}'s ({}) subsystems in {} ms",
        name(),
        subsystems_.size(),
        timer.milliseconds()
    ));

    // Initialize self
    Subsystem::init();
}

void Macrosystem::shutdown() {
    // Ignore if already initialized
    if (!isInitialized())
        return;

    // Start timer
    Timer timer;

    // Run shutdown logic for subsystems
    auto order = resolveOrder_();
    std::reverse(order.begin(), order.end());
    for (auto id : order)
        nodes_[id]->shutdown();

    // Send log
    ENGINE_INFO(CORE, std::format(
        "Shutdown {}'s ({}) subsystems in {} ms",
        name(),
        subsystems_.size(),
        timer.milliseconds()
    ));

    // Shutdown self
    Subsystem::shutdown();
}
