/*
    Core.hpp

    Declaration of a low-level core engine layer.
*/

#pragma once

#include "Core/Interfaces/ICoreModule.hpp"
#include "Foundation/ModuleRegistry.hpp"
#include "Core/Jobs/JobScheduler.hpp"
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

#include "Core/Core.tpp"
