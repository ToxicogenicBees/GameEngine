/*
    Guid.hpp

    Declaration for a simple GUID class
*/

#pragma once

#include "Core/Utility/Random.hpp"
#include <functional>
#include <cstdint>
#include <string>

namespace toxico {
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
        bool operator==(const Guid& other) const;

        /**
         * @brief Gets the hash for this object.
         * 
         * @return The hash for this object.
         */
        std::size_t getHash() const noexcept;

        /**
         * @brief Converts the guid to a string.
         * 
         * @return The guid as a string.
         */
        std::string get() const;
    };

    /**
     * @brief Write a guid to an output stream
     * 
     * @param o The output stream being written to.
     * @param guid The guid being written.
     * 
     * @return A reference to the modified output stream.
     */
    inline std::ostream& operator<<(std::ostream& o, const Guid& guid) {
        o << guid.get();
        return o;
    }
}

namespace std {
    using toxico::Guid;
    
    template<>
    struct hash<Guid> {
        /**
         * @brief Calculates the hash of a hashable object.
         * 
         * @param object A hashable object.
         * @return A deterministic hash for the object.
         */
        inline std::size_t operator()(const Guid& guid) const noexcept {
            return guid.getHash();
        }
    };
}
