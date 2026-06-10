/*
    Resource.hpp

    Declaration of an abstract resource class, containing data loaded in from asset files / generated at runtime.
*/

#pragma once

#include <string>

class Resource {
private:
    const std::string TYPE_;

public:
    /**
     * @brief Constructor.
     * 
     * @param type The type name of the resource.
     */
    Resource(const std::string& type);

    /**
     * @brief Copy constructor (deleted).
     */
    Resource(const Resource&) = delete;

    /**
     * @brief Assignment operator (deleted).
     * 
     * @param other Another resource.
     * @return A reference to this resource.
     */
    Resource& operator=(const Resource& other) = delete;

    /**
     * @brief Gets the type name of the resource.
     * 
     * @return The type name of the resource.
     */
    const std::string& type() const;

    /**
     * @brief Destructor.
     */
    virtual ~Resource() = default;
};
