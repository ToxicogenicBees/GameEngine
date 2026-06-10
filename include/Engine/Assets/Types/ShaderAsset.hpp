/*
    ShaderAsset.hpp

    Declaration of a shader file storage class
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Assets/AssetRecord.hpp"
#include "Assets/Types/File.hpp"
#include "Core/Handle.hpp"
#include <memory>

class ShaderAsset : public Asset {
private:
    FileHandle vert_shader_;
    FileHandle frag_shader_;

public:
    /**
     * @brief Constructor.
     * 
     * @param vert_shader The vertex shader file.
     * @param frag_shader The fragment shader file.
     */
    ShaderAsset(FileHandle vert_shader, FileHandle frag_shader);

    /**
     * @brief Constructor.
     */
    ShaderAsset() = default;

    /**
     * @brief Gets the vertex shader.
     * 
     * @return The binary content of the vertex shader.
     */
    FileHandle vertexShader() const;

    /**
     * @brief Gets the fragment shader.
     * 
     * @return The binary content of the fragment shader.
     */
    FileHandle fragmentShader() const;
};

using ShaderAssetHandle = Handle<AssetRecord<ShaderAsset>>;
