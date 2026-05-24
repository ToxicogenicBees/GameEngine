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
    // Screen position
    auto screen_pos = camera.worldToScreen(transform.position);

    // Texture pixel offset
    float width = (float)texture->width();
    float height = (float)texture->height();
    Vector2 offset_pixels{
        width * offset.x.scale + offset.x.offset,
        height* offset.y.scale + offset.y.offset
    };

    // Destination rectangle
    SDL_FRect dst {
        (float)(screen_pos.x + offset_pixels.x),
        (float)(screen_pos.y + offset_pixels.y),
        (float)(width * camera.zoom()),
        (float)(height * camera.zoom())
    };

    // Pivot center
    SDL_FPoint center {
        width * 0.5f,
        height * 0.5f
    };

    // Rotation
    double degrees = transform.rotation * 180.0 / PI;

    // Render texture
    SDL_RenderTextureRotated(
        renderer_,
        texture->raw(),
        nullptr,
        &dst,
        degrees,
        &center,
        SDL_FLIP_NONE
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
