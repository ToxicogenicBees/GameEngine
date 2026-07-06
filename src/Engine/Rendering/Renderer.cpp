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

void Renderer::beginFrame() {
    clear({0, 0, 0, 255});
}

void Renderer::endFrame() {
    present();
}

void Renderer::clear(Color4 color) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer_);
}

void Renderer::draw(const Quad& quad, Texture* texture) {
    SDL_RenderTextureRotated(
        renderer_,
        texture->raw(),
        nullptr,
        &quad.rect,
        quad.rotation,
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

void Renderer::setLogicalSize(Size size) {
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
