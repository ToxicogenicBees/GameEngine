/*
    Region.hpp

    Declaration for an iterable 2D planar region.
*/

#pragma once

#include "foundation/math/Vector.hpp"
#include "foundation/geometry/Size.hpp"

namespace toxico {
    class RegionIterator {
    private:
        Vector2i current_;
        Vector2i begin_;
        Vector2i end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param current The current position of the iterator.
         * @param begin The starting point of the Region.
         * @param end The end point of the Region.
         */
        RegionIterator(Vector2i current, Vector2i begin, Vector2i end) noexcept;

        /**
         * @brief Dereference operator.
         * 
         * @return The position of this iterator.
         */
        Vector2i operator*() const noexcept;

        /**
         * @brief Post-increment operator.
         * 
         * @return The incremented iterator.
         */
        RegionIterator& operator++() noexcept;

        /**
         * @brief Comparison operator.
         * 
         * @param other Another Region iterator
         * @return If the two iterators are the same.
         */
        bool operator==(const RegionIterator& other) const noexcept;
    };

    class Region {
    private:
        Vector2i begin_;
        Vector2i end_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param begin The starting point of the Region.
         * @param size The size the Region.
         */
        Region(Vector2i begin, Size size) noexcept;

        /**
         * @brief Constructor.
         * 
         * @param size The size the Region.
         */
        Region(Size size) noexcept;

        /**
         * @brief Gets the desired iterator for this Region.
         * 
         * @return The desired iterator.
         */
        RegionIterator begin() const noexcept;
        RegionIterator end() const noexcept;
    };
}
