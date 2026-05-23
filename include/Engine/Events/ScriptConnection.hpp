/*
    ScriptConnection.hpp
*/

#pragma once

#include <functional>

class ScriptConnection {
private:
    void(*const ON_DISCONNECT_)();
    bool connected_ = false;

public:
    /**
     * @brief Constructor
     * 
     * @param on_disconnect Handler for disconnection logic
     */
    ScriptConnection(void(*on_disconnect)());

    /**
     * @brief Disconnects the event
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
