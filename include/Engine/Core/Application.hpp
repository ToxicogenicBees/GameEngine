/*
    Application.hpp

    Declaration for a game application
*/

#pragma once

#include "Core/IApplication.hpp"
#include "Core/EngineAPI.hpp"
#include "Core/Engine.hpp"
#include "Types/Size.hpp"
#include <string>
#include <memory>

class Application : public IApplication {
private:
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<EngineAPI> api_;

protected:
    /**
     * @brief Initializes the game
     */
    void init() override {}

    /**
     * @brief Shuts down the game
     */
    void shutdown() override {}

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
     * @brief Gets a pointer to the engine api
     *
     * @return A pointer to the engine api
     */
    EngineAPI* api();

    /**
     * @brief Destructor
     */
    ~Application();
};
