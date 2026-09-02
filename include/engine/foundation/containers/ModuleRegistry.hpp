/*
    ModuleRegistry.hpp

    Declaration of a registry for modular components.
*/

#pragma once

#include "foundation/containers/OwningMap.hpp"
#include <type_traits>
#include <typeindex>

namespace toxico {
    template<typename Module>
    class ModuleRegistry {
    private:
        OwningMap<std::type_index, Module> modules_;

    public:
        /**
         * @brief Gets if the registry owns a module of the desired type.
         * 
         * @return If the registry owns a module of the desired type.
         */
        template<std::derived_from<Module> Key>
        bool contains() const;

        /**
         * @brief Gets the desired module.
         * 
         * @return The desired module, or nullptr if it wasn't found.
         */
        template<std::derived_from<Module> Key>
        Key& get();

        /**
         * @brief Adds the desired module.
         * 
         * @param module The desired module.
         */
        template<std::derived_from<Module> Key, std::derived_from<Module> T = Key>
        void add(std::unique_ptr<T> module);
    };
};

#include "foundation/containers/ModuleRegistry.tpp"
