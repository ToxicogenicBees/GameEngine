/*
    IFrameLifecycle.hpp

    An interface for objects running on a frame lifecyle.
*/

#pragma once

class IFrameLifecycle {
public:
    /**
     * @brief Begin the frame.
     */
    virtual void beginFrame() = 0;

    /**
     * @brief End the frame.
     */
    virtual void endFrame() = 0;

    /**
     * @brief Destructor.
     */
    virtual ~IFrameLifecycle() = default;
};
