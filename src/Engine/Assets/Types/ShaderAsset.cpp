/*
    ShaderAsset.cpp

    Implementation of a shader file storage class
*/

#include "Assets/Types/ShaderAsset.hpp"

ShaderAsset::ShaderAsset(std::shared_ptr<File> vert_shader, std::shared_ptr<File> frag_shader)
    : Asset("ShaderAsset"),
      vert_shader_(vert_shader),
      frag_shader_(frag_shader)
{}

std::shared_ptr<File> ShaderAsset::vertexShader() const {
    return vert_shader_;
}

std::shared_ptr<File> ShaderAsset::fragmentShader() const {
    return frag_shader_;
}
