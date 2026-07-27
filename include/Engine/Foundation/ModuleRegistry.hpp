/*
    ModuleRegistry.hpp

    Declaration of a registry for modular components.
*/

#pragma once

#include "Foundation/Interfaces/IModule.hpp"
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <type_traits>
#include <concepts>

namespace toxico {
    template<typename BaseModule>
    requires std::is_base_of_v<IModule, BaseModule>
    class ModuleRegistry {
    private:
        std::unordered_map<std::type_index, std::unique_ptr<BaseModule>> modules_;

    public:
        /**
         * @brief Gets if the registry owns a module of the desired type.
         * 
         * @return If the registry owns a module of the desired type.
         */
        template<typename T>
        requires std::is_base_of_v<BaseModule, T>
        bool contains() const;

        /**
         * @brief Gets the desired module.
         * 
         * @return The desired module.
         */
        template<typename T>
        requires std::is_base_of_v<BaseModule, T>
        T& get();

        /**
         * @brief Adds the desired module.
         * 
         * @param module The desired module.
         */
        template<typename Interface, typename Implementation = Interface>
        requires std::is_base_of_v<BaseModule, Implementation> && std::is_base_of_v<Interface, Implementation>
        void add(std::unique_ptr<Implementation> module);
    };
};

#include "Foundation/ModuleRegistry.tpp"
