/*
    ResourceRecord.tpp

    Template implementation of a resource record
*/

#pragma once

#include "Resources/ResourceRecord.hpp"

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
ResourceRecord<Resource_t>::ResourceRecord(const std::filesystem::path& path, Handle<Resource_t> handle)
    : PATH_(path),
      handle_(handle),
      loaded_(true)
{}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
void ResourceRecord<Resource_t>::load(Handle<Resource_t> handle) {
    handle_ = handle;
    loaded_ = true;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
void ResourceRecord<Resource_t>::unload() {
    loaded_ = false;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
Handle<Resource_t> ResourceRecord<Resource_t>::handle() {
    return handle_;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
const std::filesystem::path& ResourceRecord<Resource_t>::path() const {
    return PATH_;
}

template<typename Resource_t>
requires std::is_base_of_v<Resource, Resource_t>
bool ResourceRecord<Resource_t>::isLoaded() const {
    return loaded_;
}
