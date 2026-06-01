/*
    Application.hpp

    Declaration for a game application
*/

#pragma once

#include "Core/Engine.hpp"
#include "Geometry/Size.hpp"
#include <string>
#include <memory>

class Application {
private:
    std::unique_ptr<Engine> engine_;

protected:
    /**
     * @brief Initializes the game
     */
    virtual void init() {}

    /**
     * @brief Shuts down the game
     */
    virtual void shutdown() {}

public:
    /**
     * @brief Constructor
     */
    Application(const std::string& name);

    /**
     * @brief Runs the game
     */
    void run();

    /**
     * @brief Destructor
     */
    virtual ~Application();
};
