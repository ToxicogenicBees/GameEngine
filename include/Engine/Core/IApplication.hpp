/*
    IApplication.hpp

    Interface for a game application
*/

#pragma once

class IApplication {
public:
    /**
     * @brief Initializes the game
     */
    virtual void init() = 0;

    /**
     * @brief Shuts down the game
     */
    virtual void shutdown() = 0;

    /**
     * @brief Destructor
     */
    virtual ~IApplication() = default;
};
