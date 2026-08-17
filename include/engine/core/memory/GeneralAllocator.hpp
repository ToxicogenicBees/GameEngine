/*
    GeneralAllocator.hpp

    Declaration of a generic allocator.
*/

#pragma once

#include <memory_resource>

namespace toxico {
    class GeneralAllocator final : std::pmr::memory_resource {
    private:
        std::pmr::memory_resource* upstream_;

        /**
         * @brief Allocates the desired data.
         * 
         * @param bytes The amount of bytes being allocated.
         * @param alignment The desired byte allignment.
         */
        void* do_allocate(size_t bytes, size_t alignment) final;

        /**
         * @brief Deallocated the desired data.
         * 
         * @param p The pointer being deallocated.
         * @param bytes The size of the data being deallocated.
         * @param alignment The data's byte allignment.
         */
        void do_deallocate(void* p, size_t bytes, size_t alignment) final;

        /**
         * @brief Compares if two memory resources are the same
         * 
         * @param other The other memory resource.
         * @return If the two resources are equal.
         */
        bool do_is_equal(const std::pmr::memory_resource& other) const noexcept final;

    public:
        /**
         * @brief Constructor.
         * 
         * @param upstream An upstream resource manager
         */
        explicit GeneralAllocator(std::pmr::memory_resource* upstream = std::pmr::new_delete_resource());
    };
}
