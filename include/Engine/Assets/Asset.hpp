/*
    Asset.hpp

    Declaration of an abstract asset class, containing data loaded in from files.
*/

#pragma once

#include <filesystem>

class Asset {
public:
    /**
     * @brief Constructor.
     */
    Asset() = default;

    /**
     * @brief Copy constructor (deleted)
     */
    Asset(const Asset&) = delete;

    /**
     * @brief Destructor.
     */
    virtual ~Asset() = default;
};
