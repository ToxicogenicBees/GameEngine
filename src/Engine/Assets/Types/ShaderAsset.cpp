/*
    ShaderAsset.cpp

    Implementation of a shader file storage class
*/

#include "Assets/Types/ShaderAsset.hpp"

ShaderAsset::ShaderAsset(FileHandle vert_shader, FileHandle frag_shader)
    : Asset("ShaderAsset"),
      vert_shader_(vert_shader),
      frag_shader_(frag_shader)
{}

FileHandle ShaderAsset::vertexShader() const {
    return vert_shader_;
}

FileHandle ShaderAsset::fragmentShader() const {
    return frag_shader_;
}
