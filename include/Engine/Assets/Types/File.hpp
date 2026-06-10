/*
    File.hpp

    Declaration of a raw text file storage class
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Assets/AssetRecord.hpp"
#include "Core/Handle.hpp"
#include <utility>
#include <vector>

class File : public Asset {
private:
    const std::vector<std::byte> CONTENT_;

public:
    /**
     * @brief Constructor.
     * 
     * @param content The byte content of the file.
     */
    File(const std::vector<std::byte>& content);

    /**
     * @brief Gets the content of the file.
     * 
     * @return The content of the file.
     */
    const std::vector<std::byte>& content() const;
};

using FileHandle = Handle<AssetRecord<File>>;
