/*
    Object.hpp

    Declaration of a core engine Object, of which all items are derived
*/

#pragma once

#include "Core/Interfaces/IDestroyable.hpp"
#include "Utility/Guid.hpp"
#include <stdint.h>

class Object : public IDestroyable {
private:
    const Guid GUID_;
    bool destroyed_ = false;

public:
    /**
     * @brief Gets if the object is marked for destruction.
     * 
     * @return True if the object is marked for destruction, false otherwise.
     */
    bool isDestroyed() final;

    /**
     * @brief Marks the object for destruction.
     */
    void destroy() final;

    /**
     * @brief Gets this object's GUID
     * 
     * @return This object's GUID
     */
    const Guid& guid() const;
};
