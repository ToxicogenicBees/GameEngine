/*
    Quad.hpp

    A simple SDL3 quad struct.
*/

#pragma once

#include <SDL3/SDL.h>

struct Quad {
    SDL_FRect rect;
    float rotation;
};
