/*
    Context.tpp

    Template implementation of a context holder, storing references to preconstructed objects.
*/

#include <functional>
#include <stdexcept>

namespace toxico {
    template<typename... Args>
    Context::Context(Args& ...args) {
        (bind<Args>(args), ...);
    }

    template<typename T>
    void Context::bind(T& item) {
        context_.emplace<T>(std::ref(item));
    }

    template<typename T>
    void Context::unbind() {
        context_.erase<T>();
    }

    template<typename T>
    bool Context::contains() const {
        return context_.contains<T>();
    }

    template<typename T>
    const T& Context::get() const {
        return context_.get<T>().get();
    }

    template<typename T>
    T& Context::get() {
        return context_.get<T>().get();
    }
}
