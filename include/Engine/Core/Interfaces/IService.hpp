/*
    IService.hpp

    An interface for engine services, providing basic functionality requirements.
*/

#pragma once

class IService {
protected:
    /**
     * @brief Run logic to reset state at the beginning of a frame
     * 
     * @param dt Time since last update.
     */
    virtual void startUpdate(double dt) {};

    /**
     * @brief Run logic to finalize state at the end of a frame
     * 
     * @param dt Time since last update.
     */
    virtual void endUpdate(double dt) {};

    /**
     * @brief Destructor.
     */
    virtual ~IService() = default;
};
