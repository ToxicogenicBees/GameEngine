/*
    RuntimeTypeSet.tpp

    Template implementation of a type set, storing multiple objects of the same template with different underlying types.
*/

#include <stdexcept>
#include <utility>

namespace toxico {
    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    const Derived& RuntimeTypeSet<Base>::get() const {
        return static_cast<const Derived&>(get(typeid(Derived)));
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    Derived& RuntimeTypeSet<Base>::get() {
        return static_cast<Derived&>(get(typeid(Derived)));
    }

    template<typename Base>
    const Base& RuntimeTypeSet<Base>::get(const std::type_index& type_index) const {
        return static_cast<const Base&>(*objects_.at(type_index));
    }

    template<typename Base>
    Base& RuntimeTypeSet<Base>::get(const std::type_index& type_index) {
        return static_cast<Base&>(*objects_.at(type_index));
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    void RuntimeTypeSet<Base>::insert(const Derived& object) {
        auto [iter, inserted] = objects_.insert(typeid(Derived), std::make_unique<Derived>(object));
        if (!inserted)
            throw std::runtime_error("Object of desired type already exists in the set");
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    void RuntimeTypeSet<Base>::insert(std::unique_ptr<Derived> object) {
        auto [iter, inserted] = objects_.emplace(typeid(Derived), std::move(object));
        if (!inserted)
            throw std::runtime_error("Object of desired type already exists in the set");
    }

    template<typename Base>
    template<typename Derived, typename... Args>
    requires std::is_base_of_v<Base, Derived>
    Derived& RuntimeTypeSet<Base>::emplace(Args&&... args) {
        auto [iter, inserted] = objects_.emplace(
            typeid(Derived), std::make_unique<Derived>(std::forward<Args>(args)...)
        );
        if (!inserted)
            throw std::runtime_error("Object of desired type already exists in the set");

        return static_cast<Derived&>(*iter->second);
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    bool RuntimeTypeSet<Base>::contains() const noexcept {
        return objects_.contains(typeid(Derived));
    }

    template<typename Base>
    template<typename Derived>
    requires std::is_base_of_v<Base, Derived>
    void RuntimeTypeSet<Base>::erase() noexcept {
        objects_.erase(typeid(Derived));
    }

    template<typename Base>
    void RuntimeTypeSet<Base>::clear() noexcept {
        objects_.clear();
    }

    template<typename Base>
    std::size_t RuntimeTypeSet<Base>::size() const noexcept {
        return objects_.size();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::const_iterator RuntimeTypeSet<Base>::cbegin() const noexcept {
        return objects_.cbegin();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::const_iterator RuntimeTypeSet<Base>::begin() const noexcept {
        return objects_.begin();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::iterator RuntimeTypeSet<Base>::begin() noexcept {
        return objects_.begin();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::const_iterator RuntimeTypeSet<Base>::cend() const noexcept {
        return objects_.cend();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::const_iterator RuntimeTypeSet<Base>::end() const noexcept {
        return objects_.end();
    }

    template<typename Base>
    RuntimeTypeSet<Base>::iterator RuntimeTypeSet<Base>::end() noexcept {
        return objects_.end();
    }
}
