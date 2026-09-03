/*
    ECS.tpp

    Template implementation of an ECS, storing entities and their components.
*/

#include "core/ecs/component/ComponentPool.hpp"
#include "core/ecs/query/ECSQueryContext.hpp"
#include "core/ecs/Signature.hpp"
#include "foundation/utility/Context.hpp"

namespace toxico {
    template<Component... Cs>
    EntityHandle ECS::create(const Cs& ...components) {
        // Create an entity in the entities registry
        auto entity = entities_.create();

        // Create a signature from these components
        auto signature = components_.createSignature<Cs...>();

        // Create the components for the entity
        auto& archetype = archetypes_.fetch(signature);
        auto placement = archetype.create(entity);

        // Populate the components
        ([&](const auto& component) {
            using ComponentType = std::remove_cvref_t<decltype(component)>;

            // Fetch the up-casted pool
            auto id = components_.get<ComponentType>();
            auto* pool = static_cast<ComponentPool<ComponentType>*>(
                archetype.getPool(id)
            );

            // Copy the given component into the component storage
            (*pool)[placement.row] = component;
        }(components), ...);

        // Update the data for this entity
        auto* data = entities_.getData(entity);
        data->placement = placement;

        // Return the newly created entity
        return entity;
    }

    template<Component... Cs>
    EntityHandle ECS::create() {
        // Create an entity in the entities registry
        auto entity = entities_.create();

        // Register these component types
        (components_.insert<Cs>(), ...);

        // Create a signature from these components
        auto signature = components_.createSignature<Cs...>();

        // Create the components for the entity
        auto& archetype = archetypes_.fetch(signature);
        auto placement = archetype.create(entity);

        // Update the data for this entity
        auto* data = entities_.getData(entity);
        data->placement = placement;

        // Return the newly created entity
        return entity;
    }

    template<Component C>
    void ECS::add(EntityHandle entity, const C& component) {
        if (!isValid(entity))
            throw std::invalid_argument("Cannot add components to an invalid entity");

        // Register this component type
        components_.insert<C>();

        // Fetch the entity's new signature
        auto added_id = components_.insert<C>();
        Signature new_signature = entities_.getData(entity)->placement.signature;
        new_signature.add(added_id);

        // Move the entity to its new architecture
        auto placement = moveEntity_(entity, new_signature);

        // Copy over the new component
        auto* new_component = get<C>(entity);
        *new_component = component;
    }

    template<Component C, typename... Args>
    void ECS::add(EntityHandle entity, Args&& ...args) {
        if (!isValid(entity))
            throw std::invalid_argument("Cannot add components to an invalid entity");

        // Fetch the entity's new signature
        auto added_id = components_.insert<C>();
        Signature new_signature = entities_.getData(entity)->placement.signature;
        new_signature.add(added_id);

        // Move the entity to its new architecture
        auto placement = moveEntity_(entity, new_signature);

        // Copy over the new component
        auto* new_component = get<C>(entity);
        *new_component = C{std::forward<Args>(args)...};
    }

    template<Component C>
    const C* ECS::get(EntityHandle entity) const noexcept {
        if (!has<C>(entity))
            return nullptr;

        // Fetch entity and component data
        const auto* data = entities_.getData(entity);
        const auto id = components_.get<C>();

        // Fetch component pool
        const auto* archetype = archetypes_.get(data->placement.signature);
        const auto* pool = static_cast<const ComponentPool<C>*>(archetype->getPool(id));

        // Return the desired component
        return &(*pool)[data->placement.row];
    }

    template<Component C>
    C* ECS::get(EntityHandle entity) noexcept {
        if (!has<C>(entity))
            return nullptr;

        // Fetch entity and component data
        auto* data = entities_.getData(entity);
        auto id = components_.get<C>();

        // Fetch component pool
        auto* archetype = archetypes_.get(data->placement.signature);
        auto* pool = static_cast<ComponentPool<C>*>(archetype->getPool(id));

        // Return the desired component
        return &(*pool)[data->placement.row];
    }

    template<Component C>
    bool ECS::has(EntityHandle entity) noexcept {
        if (!isValid(entity))
            return false;

        if (!components_.find<C>())
            return false;

        auto* data = entities_.getData(entity);
        auto id = components_.get<C>();

        return data->placement.signature.contains(id);
    }

    template<Component C>
    void ECS::remove(EntityHandle entity) noexcept {
        if (!isValid(entity))
            return;

        // Early exit if the component isn't a part of the entity
        if (!has<C>(entity))
            return;

        // Fetch the entity's new signature
        auto removed_id = components_.get<C>();
        Signature new_signature = entities_.getData(entity)->placement.signature;
        new_signature.remove(removed_id);

        // Move the entity to its new architecture
        auto placement = moveEntity_(entity, new_signature);
    }

    template<Component... Cs>
    ECSQuery<Cs...> ECS::query() noexcept {
        auto context = ECSQueryContext{archetypes_, components_};
        return {std::move(context)};
    }
}
