/*
    EntityId.hpp

    Declaration of a light-weight Entity handle.
*/

#pragma once

#include <cstdint>
#include <limits>

namespace toxico {
    class EntityId {
    private:
        uint32_t index_;
        uint32_t generation_;

    public:
        using index_type = uint32_t;
        static constexpr index_type invalid_index = std::numeric_limits<uint32_t>::max();

        /**
         * @brief Constructor.
         * 
         * @param index The index of this id.
         * @param generation The generation of this id.
         */
        EntityId(uint32_t index, uint32_t generation) noexcept;

        /**
         * @brief Compares two entity ids.
         * 
         * @return If the two ids are the same.
         */
        bool operator==(EntityId other) const noexcept;

        /**
         * @brief Gets the index of this id.
         * 
         * @return The index of this id.
         */
        uint32_t index() const noexcept;

        /**
         * @brief Gets the generation of this id.
         * 
         * @return The generation of this id.
         */
        uint32_t generation() const noexcept;
    };
}
