/*
    RenderSystem.hpp

    Declaration of a render system, in charge of collecting, sorting, and calling a render for objects.
*/

#pragma once

#include "Rendering/Renderable.hpp"
#include <vector>

class RenderSystem {
private:
    std::vector<Renderable*> objects_;

public:
    /**
     * @brief Constructor.
     */
    RenderSystem() = default;

    /**
     * @brief Registers an object to the render system.
     * 
     * @param object The object being registered.
     */
    void registerObject(Renderable* object);

    /**
     * @brief Unregisters an object from the render system.
     * 
     * @param object The object being removed.
     */
    void unregisterObject(Renderable* object);

    /**
     * @brief Renders the list of objects to the active renderer.
     */
    void render();
};
