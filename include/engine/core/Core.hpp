/*
    Core.hpp

    Declaration of a low-level core engine layer.
*/

#pragma once

#include "core/interfaces/ICoreModule.hpp"
#include "foundation/containers/ModuleRegistry.hpp"
#include "core/logging/LoggerBase.hpp"
#include "core/jobs/JobScheduler.hpp"
#include "core/ecs/ECS.hpp"
#include <memory>

namespace toxico {
    class Core {
    private:
        ModuleRegistry<ICoreModule> modules_;

    public:
        /**
         * @brief Adds a platform module to the object.
         * 
         * @param module The module being added.
         */
        template<typename Interface, typename Implementation = Interface>
        void addModule(std::unique_ptr<Implementation> module);

        /**
         * @brief Constructor.
         */
        Core() = default;

        /**
         * @brief Gets the logger of this core.
         * 
         * @return The logger of this core.
         */
        LoggerBase& logger();

        /**
         * @brief Gets the job scheduler of this core.
         * 
         * @return The job scheduler of this core.
         */
        JobScheduler& jobs();

        /**
         * @brief Gets the ECS module of this core.
         * 
         * @return The ECS module of this core.
         */
        ECS& ecs();
    };
}

#include "core/Core.tpp"
