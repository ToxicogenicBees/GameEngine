/*
    ScriptConnection.cpp
*/

#include "Events/ScriptConnection.hpp"

ScriptConnection::ScriptConnection(std::function<void()> on_disconnect)
    : ON_DISCONNECT_(on_disconnect) {}

void ScriptConnection::disconnect() {
    if (!connected_)
        ON_DISCONNECT_();
}

bool ScriptConnection::connected() const {
    return connected_;
}

ScriptConnection::~ScriptConnection() {
    disconnect();
}
