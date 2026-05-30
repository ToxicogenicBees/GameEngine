/*
    InputBuffer.hpp

    Declaration for a buffer, storing input states
*/

#pragma once

#include <unordered_set>

template<typename Key_t>
class InputBuffer {
private:
    // Per-frame state
    std::unordered_set<Key_t> pressed_;
    std::unordered_set<Key_t> released_;

    // Persistant state
    std::unordered_set<Key_t> held_;

public:
    /**
     * @brief Constructor.
     */
    InputBuffer() = default;

    /**
     * @brief Register that a key was pressed.
     * 
     * @param key The key pressed.
     */
    void registerPress(Key_t key);

    /**
     * @brief Register that a key was released.
     * 
     * @param key The key released.
     */
    void registerRelease(Key_t key);

    /**
     * @brief Refresh the per-frame state.
     */
    void refreshState();

    /**
     * @brief Clear all state.
     */
    void clear();

    /**
     * @brief Check if a key is held.
     * 
     * @param key The key being checked.
     */
    bool isHeld(Key_t key) const;

    /**
     * @brief Check if a key was pressed this update.
     * 
     * @param key The key being checked.
     */
    bool wasPressed(Key_t key) const;

    /**
     * @brief Check if a key was released this update.
     * 
     * @param key The key being checked.
     */
    bool wasReleased(Key_t key) const;

    /**
     * @brief Returns the current set of all pressed keys.
     * 
     * @return The current set of all pressed keys.
     */
    const std::unordered_set<Key_t>& allPressed() const;

     /**
     * @brief Returns the current set of all released keys.
     * 
     * @return The current set of all released keys.
     */
    const std::unordered_set<Key_t>& allReleased() const;

     /**
     * @brief Returns the current set of all held keys.
     * 
     * @return The current set of all held keys.
     */
    const std::unordered_set<Key_t>& allHeld() const;
};

#include "Input/InputBuffer.tpp"
