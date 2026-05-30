/*
    IDestroyable.hpp

    An interface for a deferred-destruction supported object
*/

#pragma once

class IDestroyable {
protected:
    /**
     * @brief Handler for object destruction
     */
    virtual void onDestroy() {}
    
public:
    /**
     * @brief Gets if the object is marked for destruction.
     * 
     * @return True if the object is marked for destruction, false otherwise.
     */
    virtual bool isDestroyed() = 0;

    /**
     * @brief Marks the object for destruction.
     */
    virtual void destroy() = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IDestroyable() = default;
};
