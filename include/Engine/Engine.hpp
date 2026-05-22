/*
    Engine.hpp

    Declaration for the game engine control class
*/

#pragma once

class Engine {
public:
    /**
     * @brief Run the engine
     */
    static void run();

private:
    static bool running_;

    /**
     * @brief Constructor (deleted)
     */
    Engine() = delete;

    /**
     * @brief Initialize the engine
     */
    static void init_();

    /**
     * @brief Shutdown the engine
     */
    static void shutdown_();

    /**
     * @brief Tick the engine
     */
    static void tick_();
};
