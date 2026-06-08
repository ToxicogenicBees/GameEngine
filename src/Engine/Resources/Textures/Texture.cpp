/*
    Texture.cpp

    Implementation for a SDL3 + stbi texture class wrapper
*/

#include "Resources/Types/Texture.hpp"

Texture::Texture(SDL_Texture* handle, const Size& size)
    : handle_(handle), SIZE_(size) {}

Size Texture::size() const {
    return SIZE_;
}

SDL_Texture* Texture::raw() const {
    return handle_;
}

Texture::~Texture() {
    if (handle_) {
        SDL_DestroyTexture(handle_);
        handle_ = nullptr;
    }
}
