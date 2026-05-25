/*
    Renderer.cpp

    Implementation of a rendering object
*/

#include "Rendering/Renderer.hpp"
#include "Types/Vector2.hpp"

namespace {
    const double PI = 3.14159265;
};


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

void Renderer::drawTexture(
    std::shared_ptr<Texture> texture,
    const Transform& transform,
    const DimVector& offset,
    const Camera& camera)
{
    Vector2 screen_pos = camera.worldToScreen(transform.position, viewport());

    float w = texture->size().width();
    float h = texture->size().height();

    Vector2 offset_pixels{
        w * -offset.x.scale + offset.x.offset,
        h * -offset.y.scale + offset.y.offset
    };

    SDL_FRect dst {
        (float)(screen_pos.x + offset_pixels.x),
        (float)(screen_pos.y + offset_pixels.y),
        (float)(w * camera.zoom()),
        (float)(h * camera.zoom())
    };

    SDL_RenderTextureRotated(
        renderer_,
        texture->raw(),
        nullptr,
        &dst,
        transform.rotation,
        nullptr,
        SDL_FLIP_NONE
    );
}

void Renderer::present() {
    SDL_RenderPresent(renderer_);
}

void Renderer::setLogicalSize(size_t width, size_t height) {
    logical_size_ = {(double)width, (double)height};
    SDL_SetRenderLogicalPresentation(
        renderer_,
        width,
        height,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );
}

void Renderer::setLogicalSize(const Size& size) {
    setLogicalSize(size.width(), size.height());
}

Size Renderer::logicalSize() const {
    return logical_size_;
}

Viewport Renderer::viewport() const {
    return Viewport{logicalSize()};
}

SDL_Renderer* Renderer::raw() const {
    return renderer_;
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}
