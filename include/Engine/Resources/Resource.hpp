/*
    Resource.hpp

    Declaration of an abstract resource class, containing data loaded in from asset files / generated at runtime.
*/

#pragma once

class Resource {
public:
    /**
     * @brief Constructor.
     */
    Resource() = default;

    /**
     * @brief Copy constructor (deleted)
     */
    Resource(const Resource&) = delete;

    /**
     * @brief Destructor.
     */
    virtual ~Resource() = default;
};
