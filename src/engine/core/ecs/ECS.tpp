/*
    ECS.tpp

    Template implementation of an ECS, storing entities and their components.
*/

namespace toxico {
    template<typename Component>
    void ECS::addComponent(EntityId entity, Component component) {
        components_.add<Component>(entity, std::move(component));
    }

    template<typename Component, typename... Args>
    void ECS::addComponent(EntityId entity, Args&& ...args) {
        components_.add<Component>(entity, std::forward<Args>(args)...);
    }

    template<typename Component>
    Component* ECS::getComponent(EntityId entity) noexcept {
        return components_.get<Component>(entity);
    }

    template<typename Component>
    bool ECS::hasComponent(EntityId entity) noexcept {
        return components_.has<Component>(entity);
    }

    template<typename Component>
    void ECS::removeComponent(EntityId entity) noexcept {
        components_.remove<Component>(entity);
    }
}
