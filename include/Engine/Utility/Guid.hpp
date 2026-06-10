/*
    Guid.hpp

    Declaration for a simple GUID class
*/

#pragma once

#include "Utility/Random.hpp"
#include <functional>
#include <cstdint>
#include <string>

class Guid {
private:
    inline static Random random_generator_;
    uint64_t high_;
    uint64_t low_;

public:
    /**
     * @brief Constructor
     */
    Guid();

    /**
     * @brief Comparision operator.
     * 
     * @param other Another guid object.
     * @return If the two guids are the same.
     */
    bool operator==(const Guid& other) const = default;

    /**
     * @brief Gets the raw binary of the guid.
     * 
     * @return The binary of the guid.
     */
    std::pair<uint64_t, uint64_t> bytes() const;

    /**
     * @brief Converts the guid to a string.
     * 
     * @return The guid as a string.
     */
    std::string get() const;
};

namespace std {
    template<>
    struct hash<Guid> {
        /**
         * @brief Calculate a hash for a guid object.
         * 
         * @param guid A guid object.
         * @return A deterministic hash for the guid object.
         */
        size_t operator()(const Guid& guid) const noexcept;
    };
}
