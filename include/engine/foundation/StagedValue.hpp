/*
    StagedValue.hpp

    Declaration of a value which can be staged to update at a later time.
*/

#pragma once

#include <optional>

namespace toxico {
    template<typename T>
    class StagedValue {
    private:
        std::optional<T> staged_;
        T current_;

    public:
        using value_type = T;

        /**
         * @brief Constructor.
         * 
         * @param initial The initially stored value.
         */
        constexpr StagedValue(const T& initial);

        /**
         * @brief Constructor.
         * 
         * @param initial The initially stored value.
         */
        constexpr StagedValue(T&& initial);

        /**
         * @brief Constructor.
         */
        constexpr StagedValue() = default;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another staged value
         * @return If the two current values in these objects match.
         */
        constexpr bool operator==(const StagedValue<T>& other) const noexcept;

        /**
         * @brief Assignment operator.
         * 
         * @param value The value being staged.
         * @return A reference to this object.
         */
        constexpr StagedValue& operator=(const T& value);

        /**
         * @brief Gets the current value stored.
         * 
         * @return The current value stored.
         */
        constexpr const T& value() const noexcept;

        /**
         * @brief Gets the current value stored.
         * 
         * @return The current value stored.
         */
        constexpr const std::optional<T>& staged() const noexcept;

        /**
         * @brief Gets the current value stored.
         * 
         * @return The current value stored.
         */
        constexpr std::optional<T>& staged() noexcept;

        /**
         * @brief Stages a value to be stored.
         * 
         * @param value The value being staged.
         */
        constexpr void stage(T value);

        /**
         * @brief Gets if there is a value being staged.
         * 
         * @return If there is a value being staged.
         */
        constexpr bool has_staged() const;

        /**
         * @brief Commits the staged value.
         * 
         * @return If the value changed from this commit.
         */
        constexpr bool commit();

        /**
         * @brief Dereference operator.
         * 
         * @return The current value stored.
         */
        constexpr const T& operator*() const noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return The current value stored.
         */
        constexpr T& operator*() noexcept;

        /**
         * @brief Member access operator.
         * 
         * @return The current value stored.
         */
        constexpr const T* operator->() const noexcept;

        /**
         * @brief Member access operator.
         * 
         * @return The current value stored.
         */
        constexpr T* operator->() noexcept;
    };
}

#include "foundation/StagedValue.tpp"
