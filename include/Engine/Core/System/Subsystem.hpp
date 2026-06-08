/*
    Subsystem.hpp

    Declaration of a subsystem class, in charge of initialization and shutdown.
*/

#pragma once

#include <concepts>
#include <string>
#include <vector>

enum class SubsystemState {
    UNINITIALIZED,
    INITIALIZED,
};

class Macrosystem;  // forward declaration

class Subsystem {
private:
    // Name
    const std::string NAME_;

    // Initialization state
    SubsystemState state_ = SubsystemState::UNINITIALIZED;

    // Subsystem ids
    inline static size_t next_id_ = 0;

    // Dependencies
    std::vector<size_t> dependencies_;

protected:
    /**
     * @brief Customizable initialization logic.
     */
    virtual void onInit() {};

    /**
     * @brief Customizable shutdown logic.
     */
    virtual void onShutdown() {};

public:
    /**
     * @brief Constructor.
     * 
     * @param name The name of the subsystem.
     */
    Subsystem(const std::string& name);

    /**
     * @brief Gets the system id for the desired subsystem.
     * 
     * @return The system id for the desired subsystem.
     */
    template<typename Subsystem_t>
    requires std::is_base_of_v<Subsystem, Subsystem_t>
    static size_t getSystemId();

    /**
     * @brief Adds a dependency for the subsystem.
     */
    template<typename Subsystem_t>
    requires std::is_base_of_v<Subsystem, Subsystem_t>
    void addDependency();

    /**
     * @brief Custimizable depencency resolution logic.
     * 
     * @param system The macrosystem this system is owned by.
     */
    virtual void resolveDependencies(Macrosystem* system) {};

    /**
     * @brief Initializes the subsystem.
     */
    virtual void init();

    /**
     * @brief Shuts down the subsystem.
     */
    virtual void shutdown();

    /**
     * @brief Gets the name of the subsystem.
     * 
     * @return The name of the subsystem.
     */
    const std::string& name() const;

    /**
     * @brief Gets if the subsystem is initialized.
     * 
     * @return If the subsystem is initialized.
     */
    bool isInitialized() const;

    /**
     * @brief Gets the dependencies of this subsystem as system ids.
     * 
     * @return The dependencies of this subsystem.
     */
    const std::vector<size_t>& dependencies() const;

    /**
     * @brief Destructor.
     */
    virtual ~Subsystem() = default;
};

#include "Core/System/Subsystem.tpp"
