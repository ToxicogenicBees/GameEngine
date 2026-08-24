/*
    Entity.tpp

    Template implementation of an ECS entity wrapper.
*/

namespace toxico {
        template<Component C>
        void Entity::add(const C& component) {
            return ecs_.addComponent<C>(handle_, component);
        }

        template<Component C, typename... Args>
        void Entity::add(Args&& ...args) {
            return ecs_.addComponent<C>(handle_, std::forward<Args>(args)...);
        }

        template<Component C>
        const C* Entity::get() const noexcept {
            return ecs_.getComponent<C>(handle_);
        }

        template<Component C>
        C* Entity::get() noexcept {
            return ecs_.getComponent<C>(handle_);
        }

        template<Component C>
        bool Entity::has() noexcept {
            return ecs_.hasComponent<C>(handle_);
        }

        template<Component C>
        void Entity::remove() noexcept {
            return ecs_.removeComponent<C>(handle_);
        }
}
