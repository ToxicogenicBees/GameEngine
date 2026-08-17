/*
    Core.tpp

    Template implementation of a low-level core engine layer.
*/

#include "core/Core.hpp"

namespace toxico {
    template<typename Interface, typename Implementation>
    void Core::addModule(std::unique_ptr<Implementation> module) {
        modules_.add<Interface>(std::move(module));
    };
}
