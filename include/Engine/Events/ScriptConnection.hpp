/*
    ScriptConnection.hpp
*/

#pragma once

#include <functional>

class ScriptConnection {
private:
    std::function<void()> disconnect_;
    bool connected_ = false;

public:
    /**
     * @brief Constructor.
     */
    ScriptConnection() = default;

    /**
     * @brief Constructor.
     * 
     * @param disconnect Handler for disconnection logic
     */
    ScriptConnection(std::function<void()> disconnect);

    /**
     * @brief Constructor.
     * 
     * @param other Another connection object.
     */
    ScriptConnection(ScriptConnection&& other);

    /**
     * @brief Assignment operator.
     * 
     * @param other RHS script connection object.
     */
    ScriptConnection& operator=(ScriptConnection&& other);

    /**
     * @brief Disconnects the event.
     */
    void disconnect();

    /**
     * @brief Gets if the connection is active.
     * 
     * @return True if the connection is active, false otherwise.
     */
    bool connected() const;

    /**
     * @brief Destructor
     */
    ~ScriptConnection();
};
