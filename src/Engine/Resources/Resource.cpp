/*
    Resource.cpp

    Implementation of an abstract resource class, containing data loaded in from asset files / generated at runtime.
*/


#include "Resources/Resource.hpp"

Resource::Resource(const std::string& type)
    : TYPE_(type) {}

const std::string& Resource::type() const {
    return TYPE_;
}