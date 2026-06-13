/*
    IResolver.hpp

    An interface for handle resolvers
*/

#pragma once

#include "Core/Handle.hpp"

template<typename Handle_t, typename Result_t>
class IResolver {
public:
    /**
     * @brief Resolve the provided handle.
     * 
     * @param handle The handle being resolved.
     * @return The resolved type
     */
    virtual Result_t* resolve(Handle_t handle) = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IResolver() = default;
};
