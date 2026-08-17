/*
    ModuleRegistry.tpp

    Template implementation of a registry for modular components.
*/

#include "foundation/ModuleRegistry.hpp"

namespace toxico {
    template<typename BaseModule>
    requires std::is_base_of_v<IModule, BaseModule>
    template<typename T>
    requires std::is_base_of_v<BaseModule, T>
    bool ModuleRegistry<BaseModule>::contains() const {
        return modules_.contains(typeid(T));
    }

    template<typename BaseModule>
    requires std::is_base_of_v<IModule, BaseModule>
    template<typename T>
    requires std::is_base_of_v<BaseModule, T>
    T& ModuleRegistry<BaseModule>::get() {
        return static_cast<T&>(*modules_.at(typeid(T)));
    }

    template<typename BaseModule>
    requires std::is_base_of_v<IModule, BaseModule>
    template<typename Interface, typename Implementation>
    requires std::is_base_of_v<BaseModule, Implementation> && std::is_base_of_v<Interface, Implementation>
    void ModuleRegistry<BaseModule>::add(std::unique_ptr<Implementation> module) {
        modules_[typeid(Interface)] = std::move(module);
    }
}
