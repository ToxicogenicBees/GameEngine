/*
    Renderer.cpp

    Implementation of a rendering object
*/

#include "Rendering/Renderer.hpp"
#include "Math/Vector2.hpp"

namespace {
    const double PI = 3.14159265;
};

void Renderer::onInit() {
    renderer_ = SDL_CreateRenderer(
        window_->raw(),
        nullptr
    );

    SDL_SetRenderVSync(renderer_, SDL_RENDERER_VSYNC_ADAPTIVE);
}

void Renderer::onShutdown() {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}

Renderer::Renderer()
    : Subsystem("Renderer")
{
    addDependency<Window>();
}

void Renderer::resolveDependencies(Macrosystem* system) {
    window_ = system->fetchSystem<Window>();
}

void Renderer::clear(Color4 color) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer_);
}

void Renderer::draw(
    const Sprite& sprite,
    const Transform& transform,
    const Vector2& anchor,
    const Camera& camera)
{
    auto texture = sprite.texture();
    if (!texture)
        return;

    auto screen_pos = camera.worldToScreen(transform.position() - sprite.offset());
    auto w = sprite.size().width() * transform.scale().x;
    auto h = sprite.size().height() * transform.scale().y;

    Vector2 anchor_pixels{
        w * anchor.x,
        h * anchor.y
    };

    SDL_FRect dst {
        static_cast<float>(screen_pos.x - 0.5 * w + anchor_pixels.x),
        static_cast<float>(screen_pos.y - 0.5 * h + anchor_pixels.y),
        static_cast<float>(w * camera.zoom()),
        static_cast<float>(h * camera.zoom())
    };

    SDL_RenderTextureRotated(
        renderer_,
        texture->raw(),
        nullptr,
        &dst,
        transform.rotation(),
        nullptr,
        SDL_FLIP_NONE
    );
}

void Renderer::present() {
    SDL_RenderPresent(renderer_);
}

void Renderer::setLogicalSize(size_t width, size_t height) {
    logical_size_ = {width, height};
    SDL_SetRenderLogicalPresentation(
        renderer_,
        width,
        height,
        SDL_LOGICAL_PRESENTATION_LETTERBOX
    );
}

void Renderer::setLogicalSize(const Size& size) {
    setLogicalSize(size);
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
