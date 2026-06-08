/*
    Macrosystem.hpp

    Declaration of a macrosystem class, a special subsystem that is in charge of other subsystems.
*/

#pragma once

#include "Core/System/Subsystem.hpp"
#include <unordered_map>
#include <memory>
#include <string>

class Macrosystem : public Subsystem {
private:
    // Subsystems
    std::unordered_map<size_t, std::unique_ptr<Subsystem>> subsystems_;
    
    // Subsystem dependency mapping
    std::unordered_map<size_t, std::vector<size_t>> reverse_graph_;
    std::unordered_map<size_t, int> indegree_;

    /**
     * @brief Resolves the depencency order for subsystems.
     */
    std::vector<size_t> resolveOrder_();

public:
    /**
     * @brief Constructor.
     * 
     * @param name The name of the subsystem.
     */
    Macrosystem(const std::string& name);

    /**
     * @brief Adds a subsystem to the macrosystem.
     * 
     * @param system The subsystem being added.
     */
    template<typename Subsystem_t, typename... Args>
    requires std::is_base_of_v<Subsystem, Subsystem_t>
    void addSystem(Args&& ...args);

    /**
     * @brief Fetches a desired subsystem.
     */
    template<typename Subsystem_t>
    requires std::is_base_of_v<Subsystem, Subsystem_t>
    Subsystem_t* fetchSystem();

    /**
     * @brief Initializes the macrosystem.
     */
    void init() final;

    /**
     * @brief Shuts down the macrosystem.
     */
    void shutdown() final;
};

#include "Core/System/Macrosystem.tpp"
