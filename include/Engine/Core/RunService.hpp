/*
    RunService.hpp

    Declaration for a singleton designed to control the dispatch of update and render events.
*/

#pragma once

#include "Events/BindableEvent.hpp"

class RunService {
private:
    friend class Engine;

    BindableEvent<double>& on_fixed_update_;
    BindableEvent<double>& on_update_;

public:
    /**
     * @brief Constructor.
     * 
     * @param on_fixed_update Update fired for every fixed update.
     * @param on_update Update fired for evey update.
     */
    RunService(BindableEvent<double>& on_fixed_update, BindableEvent<double>& on_update);

    /**
     * @brief Gets a bindable event fired every fixed update.
     * 
     * @return Bindable event fired every fixed update.
     */
    IBindableEvent<double>& onFixedUpdate();

    /**
     * @brief Gets a bindable event fired every update.
     * 
     * @return Bindable event fired every update.
     */
    IBindableEvent<double>& onUpdate();
};
