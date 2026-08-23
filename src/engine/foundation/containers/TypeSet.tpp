/*
    TypeSet.tpp

    Template implementation of a type set, storing multiple objects of the same template with different underlying types.
*/

#include <stdexcept>
#include <utility>

namespace toxico {
    template<template<typename> typename Object>
    template<typename T>
    const Object<T>& TypeSet<Object>::get() const {
        return std::any_cast<const Object<T>&>(objects_.at(typeid(T)));
    }

    template<template<typename> typename Object>
    template<typename T>
    Object<T>& TypeSet<Object>::get() {
        return std::any_cast<Object<T>&>(objects_.at(typeid(T)));
    }

    template<template<typename> typename Object>
    template<typename T>
    Object<T>& TypeSet<Object>::insert(const Object<T>& object) {
        auto [iter, inserted] = objects_.insert(typeid(T), object);
        if (!inserted)
            throw std::runtime_error("Object of desired type already exists in the set");

        return std::any_cast<Object<T>&>(iter->second);
    }

    template<template<typename> typename Object>
    template<typename T, typename... Args>
    Object<T>& TypeSet<Object>::emplace(Args&&... args) {
        auto [iter, inserted] = objects_.emplace(
            typeid(T),
            std::in_place_type<Object<T>>,
            std::forward<Args>(args)...
        );
        if (!inserted)
            throw std::runtime_error("Object of desired type already exists in the set");

        return std::any_cast<Object<T>&>(iter->second);
    }

    template<template<typename> typename Object>
    template<typename T>
    bool TypeSet<Object>::contains() const noexcept {
        return objects_.contains(typeid(T));
    }

    template<template<typename> typename Object>
    template<typename T>
    void TypeSet<Object>::erase() noexcept {
        objects_.erase(typeid(T));
    }

    template<template<typename> typename Object>
    void TypeSet<Object>::clear() noexcept {
        objects_.clear();
    }

    template<template<typename> typename Object>
    size_t TypeSet<Object>::size() const noexcept {
        return objects_.size();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::const_iterator TypeSet<Object>::cbegin() const noexcept {
        return objects_.cbegin();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::const_iterator TypeSet<Object>::begin() const noexcept {
        return objects_.begin();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::iterator TypeSet<Object>::begin() noexcept {
        return objects_.begin();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::const_iterator TypeSet<Object>::cend() const noexcept {
        return objects_.cend();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::const_iterator TypeSet<Object>::end() const noexcept {
        return objects_.end();
    }

    template<template<typename> typename Object>
    TypeSet<Object>::iterator TypeSet<Object>::end() noexcept {
        return objects_.end();
    }
}
