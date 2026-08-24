/*
    ComponentPool.hpp

    Declaration of a component pool
*/

#pragma once

#include "core/ecs/components/interfaces/IComponentPool.hpp"
#include "core/ecs/components/concepts/Component.hpp"
#include "foundation/containers/DenseVector.hpp"
#include <vector>
#include <limits>

namespace toxico {
    template<Component C>
    class ComponentPool final : public IComponentPool {
    private:
        DenseVector<C> components_;

    public:
        using value_type = C;
        using const_iterator = DenseVector<C>::const_iterator;
        using iterator = DenseVector<C>::iterator;

        /**
         * @brief Indexes the component pool.
         * 
         * @param index The index of the desired item.
         * @return The item at that index.
         */
        const C& operator[](size_t index) const;
        C& operator[](size_t index);

        /**
         * @brief Indexes the component pool.
         * 
         * @param index The index of the desired item.
         * @return The item at that index.
         * 
         * Throws an exception if the index is out of bounds.
         */
        const C& at(size_t index) const;
        C& at(size_t index);

        /**
         * @brief Gets the size of the component pool.
         * 
         * @return The size of the component pool.
         */
        size_t size() const noexcept final;

        /**
         * @brief Gets if this component pool is empty.
         * 
         * @return If the component pool is empty.
         */
        bool empty() const noexcept final;
        
        /**
         * @brief Emplaces an item into the component pool.
         * 
         * @param args The constructor arguments for the item.
         */
        template<typename... Args>
        C& emplace_back(Args&&... args);

        /**
         * @brief Puts an item into the component pool.
         * 
         * @param value The value being inserted.
         */
        void push_back(const C& value);
        void push_back(C&& value);

        /**
         * @brief Inserts a defaulted item into the component pool.
         */
        void push_back() final;

        /**
         * @brief Removes the last item from the component pool.
         */
        void pop_back() noexcept final;

        /**
         * @brief Erases an item from the component pool.
         * 
         * @param index The index being erased.
         * @return The result of this erasure.
         */
        DenseErasure erase(size_t index) noexcept final;

        /**
         * @brief Clears the data in this component pool.
         */
        void clear() noexcept final;

        /**
         * @brief Copies an item from this pool to another.
         * 
         * @param source_index The source index of the item being copied.
         * @param destination The destination pool.
         * @param destination_index The destination index of the item being copied.
         */
        void copyTo(size_t source_index, IComponentPool& destination, size_t destination_index) const final;

        /**
         * @brief Gets the desired iterator for this grid's data.
         * 
         * @return The desired iterator.
         */
        const_iterator cbegin() const noexcept;
        const_iterator begin() const noexcept;
        iterator begin() noexcept;
        const_iterator cend() const noexcept;
        const_iterator end() const noexcept;
        iterator end() noexcept;
    };
}

#include "core/ecs/components/ComponentPool.tpp"
