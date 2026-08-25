/*
    Engine.hpp

    Declaration of a composition of engine layers working together to form an engine.
*/

#pragma once

#include "platform/Platform.hpp"
#include "core/Core.hpp"
#include <memory>

namespace toxico {
    class Engine {
    private:
        std::unique_ptr<Platform> platform_;
        std::unique_ptr<Core> core_;

    public:
        /**
         * @brief Constructor.
         */
        Engine();

        /**
         * @brief 
         */
    };
}
