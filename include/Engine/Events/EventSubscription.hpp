/*
    EventSubscription.hpp

    A simple struct to store event subscription data
*/

#pragma once

#include <typeindex>
#include <stdint.h>

struct EventSubscription {
    std::type_index type;
    size_t id;
};
