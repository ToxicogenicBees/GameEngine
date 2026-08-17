/*
    CoreFactory.hpp

    Declaration of a core factory, building the low-level core engine layer.
*/

#pragma once

#include "core/Core.hpp"
#include <memory>

namespace toxico {
    class CoreFactory {
    private:
        /**
         * @brief Constructor. (deleted)
         */
        CoreFactory() = delete;

    public:
        /**
         * @brief Creates a new platform object for the appropriate system.
         * 
         * @return The constructed platform object.
         */
        static std::unique_ptr<Core> create();
    };
}
