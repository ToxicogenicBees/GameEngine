/*
    Context.hpp

    Declaration of a context holder, storing references to preconstructed objects.
*/

#pragma once

#include "foundation/containers/erased/ErasedSet.hpp"
#include <functional>

namespace toxico {
    class Context {
    private:
        // Set of type-erased reference wrappers
        ErasedSet context_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param args Items being binded to this context.
         */
        template<typename... Args>
        Context(Args& ...args);
        
        /**
         * @brief Constructor.
         */
        Context() = default;

        /**
         * @brief Binds an item to this context.
         * 
         * @param item The item being binded.
         * 
         * Throws an exception if an item of this type was already bound to the context.
         */
        template<typename T>
        void bind(T& item);

        /**
         * @brief Unbinds an item from this context.
         */
        template<typename T>
        void unbind();

        /**
         * @brief Unbinds all items from this context.
         */
        void clear();

        /**
         * @brief Gets if an object is held in this context.
         * 
         * @return If the object is held in this context.
         */
        template<typename T>
        bool contains() const;

        /**
         * @brief Gets an item from this context.
         * 
         * @return The item in this context.
         * 
         * Throws an exception if the context doesn't have this item.
         */
        template<typename T>
        const T& get() const;

        /**
         * @brief Gets an item from this context.
         * 
         * @return The item in this context.
         * 
         * Throws an invalid arguments exception if the context doesn't have this item.
         */
        template<typename T>
        T& get();
    };
}

#include "foundation/utility/Context.tpp"
