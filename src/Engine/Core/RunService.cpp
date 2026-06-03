/*
    RunService.cpp

    Implementation for a singleton designed to control the dispatch of update and render events.
*/

#include "Core/RunService.hpp"

IBindableEvent<double>& RunService::onFixedUpdate() {
    return on_fixed_update;
}

IBindableEvent<double>& RunService::onUpdate() {
    return on_update;
}
