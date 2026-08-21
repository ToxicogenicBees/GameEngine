/*
    ComponentRegistry.tpp

    Template implementation of a component registry.
*/

namespace toxico {
    template<typename Component>
    void ComponentRegistry::add(EntityId entity, Component component) {
        // Does not own any pool of this component
        if (!pools_.contains<Component>())
            pools_.emplace<Component>();

        // Fetch pool
        auto pool = pools_.get<Component>();

        // Add component to the pool
        pool->insert(entity, std::move(component));
    }

    template<typename Component, typename... Args>
    void ComponentRegistry::add(EntityId entity, Args&& ...args) {
        // Fetch component pool
        if (!pools_.contains<ComponentPool<Component>>())
            pools_.emplace<ComponentPool<Component>>();
        auto pool = pools_.get<ComponentPool<Component>>();

        // Add component to the pool
        pool->emplace(entity, std::forward<Args>(args)...);
    }

    template<typename Component>
    const Component* ComponentRegistry::get(EntityId entity) const noexcept {
        // Does not own any pool of this component
        if (!pools_.contains<ComponentPool<Component>>())
            return nullptr;

        // Fetch component
        auto pool = pools_.get<ComponentPool<Component>>();
        return pool->get(entity);
    }

    template<typename Component>
    Component* ComponentRegistry::get(EntityId entity) noexcept {
        // Does not own any pool of this component
        if (!pools_.contains<ComponentPool<Component>>())
            return nullptr;

        // Fetch component
        auto pool = pools_.get<ComponentPool<Component>>();
        return pool->get(entity);
    }

    template<typename Component>
    bool ComponentRegistry::has(EntityId entity) const noexcept {
        // Does not own any pool of this component
        if (!pools_.contains<ComponentPool<Component>>())
            return false;

        // Check for component
        auto pool = pools_.get<ComponentPool<Component>>();
        return pool->contains(entity);
    }

    template<typename Component>
    void ComponentRegistry::remove(EntityId entity) noexcept {
        if (pools_.contains<ComponentPool<Component>>()) {
            auto pool = pools_.get<ComponentPool<Component>>();
            pool->erase(entity);
        }
    }
}
