/*
    RunService.cpp

    Implementation for a singleton designed to control the dispatch of update and render events.
*/

#include "Core/RunService.hpp"

RunService::RunService(BindableEvent<double>& on_fixed_update, BindableEvent<double>& on_update)
    : on_fixed_update_(on_fixed_update), on_update_(on_update) {}

IBindableEvent<double>& RunService::onFixedUpdate() {
    return on_fixed_update_;
}

IBindableEvent<double>& RunService::onUpdate() {
    return on_update_;
}
