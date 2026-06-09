/*
    Asset.hpp

    Declaration of an abstract asset class, containing data loaded in from files.
*/

#pragma once

#include <string>

class Asset {
private:
    const std::string TYPE_;

public:
    /**
     * @brief Constructor.
     * 
     * @param type The type name of the asset
     */
    Asset(const std::string& type);

    /**
     * @brief Copy constructor (deleted)
     */
    Asset(const Asset&) = delete;

    /**
     * @brief Assignment operator (deleted)
     * 
     * @param other Another asset.
     * @return A reference to this asset.
     */
    Asset& operator=(const Asset& other) = delete;

    /**
     * @brief Gets the type name of the asset.
     * 
     * @return The type name of the asset.
     */
    const std::string& assetType() const;

    /**
     * @brief Destructor.
     */
    virtual ~Asset() = default;
};
