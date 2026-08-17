/*
    Quad.hpp

    A simple SDL3 quad struct.
*/

#pragma once

#include <SDL3/SDL.h>

namespace toxico {
    struct Quad {
        SDL_FRect rect;
        float rotation;
    };
}
