/*
    ScriptConnection.cpp
*/

#include "Events/ScriptConnection.hpp"

ScriptConnection::ScriptConnection(std::function<void()> disconnect)
    : disconnect_(std::move(disconnect)) {}

ScriptConnection::ScriptConnection(ScriptConnection&& other)
    : disconnect_(std::move(other.disconnect_))
{
    other.disconnect_ = nullptr;
}

ScriptConnection& ScriptConnection::operator=(ScriptConnection&& other) {
    if (this != &other) {
        disconnect_ = std::move(other.disconnect_);
        other.disconnect_ = nullptr;
    }
    return *this;
}

void ScriptConnection::disconnect() {
    if (!connected_ && disconnect_) {
        disconnect_();
        disconnect_ = nullptr;
        connected_ = false;
    }
}

bool ScriptConnection::connected() const {
    return connected_;
}

ScriptConnection::~ScriptConnection() {
    disconnect();
}
