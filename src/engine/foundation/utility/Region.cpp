/*
    Region.cpp

    Implementation for an iterable 2D planar region.
*/

#include "foundation/utility/Region.hpp"

namespace toxico {
    RegionIterator::RegionIterator(Vector2i current, Vector2i begin, Vector2i end) noexcept
        : current_(current), begin_(begin), end_(end) {}

    Vector2i RegionIterator::operator*() const noexcept {
        return current_;
    }

    RegionIterator& RegionIterator::operator++() noexcept {
        ++current_.x;

        if (current_.x >= end_.x) {
            current_.x = begin_.x;
            ++current_.y;
        }

        return *this;
    }

    bool RegionIterator::operator==(const RegionIterator& other) const noexcept {
        return current_ == other.current_;
    }

    Region::Region(Vector2i begin, Size size) noexcept
        : begin_(begin),
          end_(begin + Vector2i{static_cast<int>(size.width), static_cast<int>(size.height)})
    {}

    Region::Region(Size size) noexcept
        : begin_(Vector2i::zero()),
          end_(Vector2i{static_cast<int>(size.width), static_cast<int>(size.height)})
    {}

    RegionIterator Region::begin() const noexcept {
        return {begin_, begin_, end_};
    }

    RegionIterator Region::end() const noexcept {
        return {{begin_.x, end_.y}, begin_, end_};
    }
}
