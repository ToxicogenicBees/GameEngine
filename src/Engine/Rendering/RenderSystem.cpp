/*
    RenderSystem.cpp

    Implementation of a render system, in charge of collecting, sorting, and calling a render for objects.
*/

#include "Rendering/RenderSystem.hpp"
#include "Core/Services.hpp"
#include <algorithm>

void RenderSystem::registerObject(Renderable* object) {
    objects_.push_back(object);

    std::sort(objects_.begin(), objects_.end(), [](Renderable* a, Renderable* b) {
        if (a->layer() != b->layer())
            return a->layer() < b->layer();
        else
            return a->order() < b->order();
    });
}

void RenderSystem::unregisterObject(Renderable* object) {
    std::erase_if(objects_, [&](auto& o) {
        return object == o;
    });
}

void RenderSystem::render() {
    for (auto& object : objects_)
        object->onRender();
}
