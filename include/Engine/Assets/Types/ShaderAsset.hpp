/*
    ShaderAsset.hpp

    Declaration of a shader file storage class
*/

#pragma once

#include "Assets/Asset.hpp"
#include "Assets/Types/File.hpp"
#include <memory>

class ShaderAsset : public Asset {
private:
    std::shared_ptr<File> vert_shader_;
    std::shared_ptr<File> frag_shader_;

public:
    /**
     * @brief Constructor.
     * 
     * @param vert_shader The vertex shader file.
     * @param frag_shader The fragment shader file.
     */
    ShaderAsset(const std::shared_ptr<File> vert_shader, std::shared_ptr<File> frag_shader);

    /**
     * @brief Gets the vertex shader.
     * 
     * @return The binary content of the vertex shader.
     */
    std::shared_ptr<File> vertexShader() const;

    /**
     * @brief Gets the fragment shader.
     * 
     * @return The binary content of the fragment shader.
     */
    std::shared_ptr<File> fragmentShader() const;
};
