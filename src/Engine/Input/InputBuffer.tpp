/*
    InputBuffer.tpp

    Template implementation for a buffer, storing input states
*/

#pragma once

#include "Input/InputBuffer.hpp"

template<typename Key_t>
void InputBuffer<Key_t>::registerPress(Key_t key) {
    if (!isHeld(key))
        pressed_.insert(key);
        
    held_.insert(key);
}

template<typename Key_t>
void InputBuffer<Key_t>::registerRelease(Key_t key) {
    released_.insert(key);
    held_.erase(key);
}

template<typename Key_t>
void InputBuffer<Key_t>::refreshState() {
    released_.clear();
    pressed_.clear();
}

template<typename Key_t>
void InputBuffer<Key_t>::clear() {
    released_.clear();
    pressed_.clear();
    held_.clear();
}

template<typename Key_t>
bool InputBuffer<Key_t>::isHeld(Key_t key) const {
    return (held_.find(key) != held_.end());
}

template<typename Key_t>
bool InputBuffer<Key_t>::wasPressed(Key_t key) const {
    return (pressed_.find(key) != held_.end());
}

template<typename Key_t>
bool InputBuffer<Key_t>::wasReleased(Key_t key) const {
    return (released_.find(key) != held_.end());
}

template<typename Key_t>
const std::unordered_set<Key_t>& InputBuffer<Key_t>::allPressed() const {
    return pressed_;
}

template<typename Key_t>
const std::unordered_set<Key_t>& InputBuffer<Key_t>::allReleased() const {
    return released_;
}

template<typename Key_t>
const std::unordered_set<Key_t>& InputBuffer<Key_t>::allHeld() const {
    return held_;
}
