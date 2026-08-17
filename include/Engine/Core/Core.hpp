/*
    Core.hpp

    Declaration of a low-level core engine layer.
*/

#pragma once

#include "core/interfaces/ICoreModule.hpp"
#include "foundation/ModuleRegistry.hpp"
#include "core/jobs/JobScheduler.hpp"
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
         * @brief Gets the job scheduler of this core.
         * 
         * @return The job scheduler of this core.
         */
        JobScheduler& jobs();
    };
}

#include "core/Core.tpp"
