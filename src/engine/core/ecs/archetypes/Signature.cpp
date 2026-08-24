/*
    Signature.cpp

    Implementation of an archetype signature.
*/

#include "core/ecs/archetypes/Signature.hpp"
#include <algorithm>

namespace toxico {
    void Signature::add(ComponentId id) {
        auto it = std::lower_bound(ids_.begin(), ids_.end(), id);
        if (it == ids_.end() || *it != id)
            ids_.insert(it, id);
    }

    void Signature::remove(ComponentId id) {
        auto it = std::lower_bound(ids_.begin(), ids_.end(), id);
        if (it != ids_.end() && *it == id)
            ids_.erase(it);
    }

    bool Signature::contains(ComponentId id) const noexcept {
        auto it = std::lower_bound(ids_.begin(), ids_.end(), id);
        return (it != ids_.end() && *it == id);
    }

    Signature::const_iterator Signature::cbegin() const noexcept {
        return ids_.cbegin();
    }

    Signature::const_iterator Signature::begin() const noexcept {
        return ids_.begin();
    }

    Signature::iterator Signature::begin() noexcept {
        return ids_.begin();
    }

    Signature::const_iterator Signature::cend() const noexcept {
        return ids_.cend();
    }

    Signature::const_iterator Signature::end() const noexcept {
        return ids_.end();
    }

    Signature::iterator Signature::end() noexcept {
        return ids_.end();
    }
}
