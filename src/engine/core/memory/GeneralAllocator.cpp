/*
    GeneralAllocator.cpp

    Implementation of a generic allocator.
*/

#include "core/memory/GeneralAllocator.hpp"

namespace toxico {
    void* GeneralAllocator::do_allocate(std::size_t bytes, std::size_t alignment) {
        return upstream_->allocate(bytes, alignment);
    }

    void GeneralAllocator::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
        upstream_->deallocate(p, bytes, alignment);
    }

    bool GeneralAllocator::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
        return this == &other;
    }

    GeneralAllocator::GeneralAllocator(std::pmr::memory_resource* upstream)
        : upstream_(upstream) {}
}
