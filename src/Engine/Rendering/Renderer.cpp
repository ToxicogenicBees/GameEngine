/*
    Renderer.cpp

    Implementation of a rendering object
*/

#include "Rendering/Renderer.hpp"

Renderer::Renderer(Window& window) 
    : window_(window.raw())
{
    renderer_ = SDL_CreateRenderer(
        window_,
        nullptr
    );
}

void Renderer::clear(Color4 color) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer_);
}

void Renderer::drawTexture(std::shared_ptr<Texture> texture, Vector2 pos) {
    SDL_FRect dst {
        (float)pos.x,
        (float)pos.y,
        (float)texture->width(),
        (float)texture->height()
    };

    SDL_RenderTexture(
        renderer_,
        texture->raw(),
        nullptr,
        &dst
    );
}

void Renderer::present() {
    SDL_RenderPresent(renderer_);
}

void Renderer::setLogicalSize(size_t width, size_t height) {
    SDL_SetRenderLogicalPresentation(
        renderer_,
        width,
        height,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );
}

void Renderer::setLogicalSize(const Size& size) {
    setLogicalSize(size.width, size.height);
}

Size Renderer::logicalSize(const Size& size) {
    SDL_FRect* rect;
    SDL_GetRenderLogicalPresentationRect(renderer_, rect);

    return Size{(size_t)rect->w, (size_t)rect->h};
}

SDL_Renderer* Renderer::raw() const {
    return renderer_;
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}
