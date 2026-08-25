/*
    Signature.hpp

    Declaration of an archetype signature.
*/

#pragma once

#include "core/ecs/component/ComponentId.hpp"
#include <functional>
#include <vector>

namespace toxico {
    class Signature {
    private:
        std::vector<ComponentId> ids_;

    public:
        using const_iterator = std::vector<ComponentId>::const_iterator;
        using iterator = std::vector<ComponentId>::iterator;

        /**
         * @brief Adds a component id to the signature, maintaining a sorted order.
         * 
         * @param id The component id being added.
         */
        void add(ComponentId id);

        /**
         * @brief Removes a component id from the signature, maintaining a sorted order.
         * 
         * @param id The component id being removed.
         */
        void remove(ComponentId id);

        /**
         * @brief Gets if the signature contains a specific component.
         * 
         * @param id The component id being checked for.
         * @return If the signature contains the component.
         */
        bool contains(ComponentId id) const noexcept;

        /**
         * @brief Compares two signatures.
         * 
         * @param other Another signature.
         * @return If these two signatures are the same.
         */
        bool operator==(const Signature& other) const = default;

        /**
         * @brief Gets the desired iterator for this signature's component ids.
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

namespace std {
    template<>
    struct hash<toxico::Signature> {
        /**
         * @brief Calculates the hash of a hashable object.
         * 
         * @param object A hashable object.
         * @return A deterministic hash for the object.
         */
        inline std::size_t operator()(const toxico::Signature& signature) const noexcept {
            std::size_t hash = 0;

            for (toxico::ComponentId id : signature) {
                hash ^= std::hash<toxico::ComponentId>{}(id)
                    + 0x9e3779b9
                    + (hash << 6)
                    + (hash >> 2);
            }

            return hash;
        }
    };
}
