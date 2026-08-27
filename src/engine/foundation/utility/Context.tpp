/*
    Context.tpp

    Template implementation of a context holder, storing references to preconstructed objects.
*/

#include <functional>

namespace toxico {
    template<typename... Args>
    Context::Context(Args& ...args) {
        (bind<Args>(args), ...);
    }

    template<typename T>
    void Context::bind(T& item) {
        references_.emplace(
            typeid(T),
            std::make_any<T>(std::ref(item))
        );
    }

    template<typename T>
    void Context::unbind() {
        references_.erase(typeid(T));
    }

    template<typename T>
    bool Context::contains() const {
        return references_.contains(typeid(T));
    }

    template<typename T>
    const T& Context::get() const {
        auto erased = references_.at(typeid(T));
        auto ref = std::any_cast<std::reference_wrapper<const T>>(erased);
        return ref.get();
    }

    template<typename T>
    T& Context::get() {
        auto erased = references_.at(typeid(T));
        auto ref = std::any_cast<std::reference_wrapper<T>>(erased);
        return ref.get();
    }
}
