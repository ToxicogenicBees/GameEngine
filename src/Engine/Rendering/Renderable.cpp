/*
    Renderable.cpp

    Implementation of an abstract class for renderable objects.
*/

#include "Rendering/Renderable.hpp"

void Renderable::setLayer(int layer) {
    layer_ = layer;
}

int Renderable::layer() const {
    return layer_;
}

void Renderable::setOrder(int order) {
    order_ = order;
}

int Renderable::order() const {
    return order_;
}