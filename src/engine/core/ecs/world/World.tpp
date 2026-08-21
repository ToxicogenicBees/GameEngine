/*
    World.tpp

    Template implementation of a world, storing entities and their components.
*/

namespace toxico {
    template<typename Component>
    void World::addComponent(EntityId entity, Component component) {
        components_.add<Component>(entity, std::move(component));
    }

    template<typename Component, typename... Args>
    void World::addComponent(EntityId entity, Args&& ...args) {
        components_.add<Component>(entity, std::forward<Args>(args)...);
    }

    template<typename Component>
    Component* World::getComponent(EntityId entity) noexcept {
        return components_.get<Component>(entity);
    }

    template<typename Component>
    bool World::hasComponent(EntityId entity) noexcept {
        return components_.has<Component>(entity);
    }

    template<typename Component>
    void World::removeComponent(EntityId entity) noexcept {
        components_.remove<Component>(entity);
    }
}
