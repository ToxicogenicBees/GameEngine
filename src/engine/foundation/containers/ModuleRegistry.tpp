/*
    ModuleRegistry.tpp

    Template implementation of a registry for modular components.
*/

namespace toxico {
    template<typename Module>
    template<std::derived_from<Module> Key>
    bool ModuleRegistry<Module>::contains() const {
        return modules_.contains(typeid(Key));
    }

    template<typename Module>
    template<std::derived_from<Module> Key>
    Key& ModuleRegistry<Module>::get() {
        auto uncast_module = modules_.at(typeid(Key)).get();
        return *static_cast<Key*>(uncast_module);
    }

    template<typename Module>
    template<std::derived_from<Module> Key, std::derived_from<Module> T>
    void ModuleRegistry<Module>::add(std::unique_ptr<T> module) {
        modules_.template insert<T>({
            typeid(Key), std::move(module)
        });
    }
}
