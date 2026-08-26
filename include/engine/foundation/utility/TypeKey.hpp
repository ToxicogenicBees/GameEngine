/*
    TypeKey.hpp

    Declaration of a type key, where the order of the types matters.
*/

#include <typeindex>
#include <vector>

namespace toxico {
    class TypeKey {
    private:
        std::vector<std::type_index> types_;

    public:
        using const_iterator = std::vector<std::type_index>::const_iterator;
        using iterator = std::vector<std::type_index>::iterator;

        /**
         * @brief Creates a type key from a list of types.
         * 
         * @return The created type key.
         */
        template<typename... Types>
        static TypeKey of() noexcept;

        /**
         * @brief Constructor.
         */
        TypeKey() noexcept = default;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another ordered type key.
         * @return If the two keys are the same.
         */
        bool operator==(const TypeKey& other) const;

        /**
         * @brief Gets if this type key contains a certain type.
         */
        template<typename T>
        bool contains() const noexcept;

        /**
         * @brief Gets if this type key contains a certain type.
         * 
         * @param type The type being checked.
         */
        bool contains(const std::type_index& type) const noexcept;

        /**
         * @brief Accesses the desired type in the set.
         * 
         * @param index The desired index.
         * @return The desired type.
         */
        std::type_index operator[](std::size_t index) const;

        /**
         * @brief Accesses the desired type in the set.
         * 
         * @param index The desired index.
         * @return The desired type.
         * 
         * Throws an error if the index is out of bounds.
         */
        std::type_index at(std::size_t index) const;

        /**
         * @brief Gets the number of types in the key.
         * 
         * @return The number of types in the key.
         */
        std::size_t size() const noexcept;

        /**
         * @brief Gets if the key is empty.
         * 
         * @return If they key is empty.
         */
        bool empty() const noexcept;

        /**
         * @brief Gets the desired iterator for this set's types.
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

#include "foundation/utility/TypeKey.tpp"
