/*
    Asset.cpp

    Implementation of an abstract asset class, containing data loaded in from files.
*/

#include "Assets/Asset.hpp"

Asset::Asset(const std::string& type)
    : TYPE_(type) {}

const std::string& Asset::type() const {
    return TYPE_;
}