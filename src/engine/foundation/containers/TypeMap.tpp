/*
    TypeMap.tpp

    Template implementation of a map, a collection of objects of the same base type.
*/

#include <utility>

namespace toxico {
    template<typename Base>
    template<typename Derived, typename... Args>
    requires std::is_base_of_v<Base, Derived>
    Derived* TypeMap<Base>::insert(std::unique_ptr<Derived> value) {
        if (contains<Derived>())
            throw std::runtime_error("TypeMap cannot add an item of a type it already contains");

        data_[typeid(Derived)] = std::move(value);
        return data_[typeid(Derived)].get();
    }
    
    template<typename Base>
    template<typename Derived, typename... Args>
    requires std::is_base_of_v<Base, Derived>
    Derived* TypeMap<Base>::emplace(Args&& ...args) {
        if (contains<Derived>())
            throw std::runtime_error("TypeMap cannot add an item of a type it already contains");

        data_[typeid(Derived)] = std::make_unique<Derived>(std::forward<Args>(args)...);
        return data_[typeid(Derived)].get();
    }

    template<typename Base>
    template<typename Derived>
    bool TypeMap<Base>::contains() const noexcept {
        return data_.contains(typeid(Derived));
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    const Derived* TypeMap<Base>::get() const noexcept {
        if (!contains<Derived>())
            return nullptr;

        return static_cast<Derived*>(data_[typeid(Derived)].get());
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    Derived* TypeMap<Base>::get() noexcept {
        if (!contains<Derived>())
            return nullptr;

        return static_cast<Derived*>(data_.at(typeid(Derived)).get());
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    void TypeMap<Base>::erase() noexcept {
        data_.erase(typeid(Derived));
    }

    template<typename Base>
    TypeMap<Base>::const_iterator TypeMap<Base>::cbegin() const noexcept {
        return data_.cbegin();
    }

    template<typename Base>
    TypeMap<Base>::const_iterator TypeMap<Base>::begin() const noexcept {
        return data_.begin();
    }

    template<typename Base>
    TypeMap<Base>::iterator TypeMap<Base>::begin() noexcept {
        return data_.begin();
    }

    template<typename Base>
    TypeMap<Base>::const_iterator TypeMap<Base>::cend() const noexcept {
        return data_.cend();
    }

    template<typename Base>
    TypeMap<Base>::const_iterator TypeMap<Base>::end() const noexcept {
        return data_.end();
    }

    template<typename Base>
    TypeMap<Base>::iterator TypeMap<Base>::end() noexcept {
        return data_.end();
    }
}
