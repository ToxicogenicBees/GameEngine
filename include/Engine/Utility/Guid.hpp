/*
    Guid.hpp

    Declaration for a simple GUID class
*/

#pragma once

#include "Utility/Random.hpp"
#include <utility>
#include <string>
#include <vector>

class Guid {
private:
    inline static Random random_generator_;
    std::vector<std::byte> bytes_;

public:
    /**
     * @brief Constructor
     */
    Guid();

    /**
     * @brief Comparision operator.
     * 
     * @param other Another guid object.
     */
    bool operator==(const Guid& other);

    /**
     * @brief Gets the raw bytes of the guid
     */
    const std::vector<std::byte>& bytes() const;

    /**
     * @brief Converts the guid to a string
     */
    std::string get() const;
};
