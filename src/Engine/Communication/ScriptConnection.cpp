/*
    ScriptConnection.cpp
*/

#include "Communication/ScriptConnection.hpp"

/**
 * @brief Constructor
 * 
 * @param on_disconnect Handler for disconnection logic
 */
ScriptConnection::ScriptConnection(void(*on_disconnect)())
    : ON_DISCONNECT_(on_disconnect) {}

/**
 * @brief Disconnects the event
 */
void ScriptConnection::disconnect() {
    if (!connected_)
        ON_DISCONNECT_();
}

/**
 * @brief Gets if the connection is active.
 * 
 * @return True if the connection is active, false otherwise.
 */
bool ScriptConnection::connected() const {
    return connected_;
}

/**
 * @brief Destructor
 */
ScriptConnection::~ScriptConnection() {
    disconnect();
}
