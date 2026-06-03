/*
    RunService.hpp

    Declaration for a singleton designed to control the dispatch of update and render events.
*/

#pragma once

#include "Events/BindableEvent.hpp"

class RunService {
protected:
    friend class Engine;

    inline static BindableEvent<double> on_fixed_update;
    inline static BindableEvent<double> on_update;

    /**
     * @brief Constructor (deleted).
     */
    RunService() = delete;

public:
    /**
     * @brief Gets a bindable event fired every fixed update.
     * 
     * @return Bindable event fired every fixed update.
     */
    static IBindableEvent<double>& onFixedUpdate();

    /**
     * @brief Gets a bindable event fired every update.
     * 
     * @return Bindable event fired every update.
     */
    static IBindableEvent<double>& onUpdate();
};
