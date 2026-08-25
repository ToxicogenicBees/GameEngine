/*
    Result.hpp

    Declaration of a result class, used for gracefully handling non-deterministic operations.
*/

#pragma once

#include "foundation/utility/Error.hpp"
#include <optional>

namespace toxico {
    template<typename T, typename E>
    class Result {
    private:
        std::optional<T> result_;
        E error_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param result The result being stored.
         * @param error The default (success) error code.
         */
        Result(T result, E error = E());

        /**
         * @brief Constructor.
         * 
         * @param error The error code.
         */
        Result(E error = E());

        /**
         * @brief Gets if there is a value stored.
         * 
         * @return If there is a value stored
         */
        bool has_value() const noexcept;

        /**
         * @brief Gets the stored value.
         * 
         * @return The stored value.
         */
        T& value() &;

        /**
         * @brief Gets the stored value.
         * 
         * @return The stored value.
         */
        const T& value() const &;

        /**
         * @brief Gets the stored value.
         * 
         * @return The stored value.
         */
        T&& value() &&;

        /**
         * @brief Gets the stored value.
         * 
         * @return The stored value.
         */
        const T&& value() const &&;

        /**
         * @brief Dereference operator.
         * 
         * @return The stored value.
         */
        T& operator*();

        /**
         * @brief Dereference operator.
         * 
         * @return The stored value.
         */
        const T& operator*()const ;

        /**
         * @brief Dereference operator.
         * 
         * @return The stored value.
         */
        T* operator->() noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return The stored value.
         */
        const T* operator->() const noexcept;

        /**
         * @brief Boolean cast operator
         * 
         * @return If there is a value stored
         */
        explicit operator bool() const noexcept;

        /**
         * @brief Gets the error of the result.
         * 
         * @return The error of the result.
         */
        const E& error() const noexcept;
    };
}

#include "foundation/utility/Result.tpp"
