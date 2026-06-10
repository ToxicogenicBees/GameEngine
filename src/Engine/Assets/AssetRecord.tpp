/*
    AssetRecord.tpp

    Template implementation of an asset record
*/

#pragma once

#include "Assets/AssetRecord.hpp"

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
AssetRecord<Asset_t>::AssetRecord(const std::filesystem::path& path, Handle<Asset_t> handle)
    : PATH_(path),
      handle_(handle),
      loaded_(true)
{}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
void AssetRecord<Asset_t>::load(Handle<Asset_t> handle) {
    handle_ = handle;
    loaded_ = true;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
void AssetRecord<Asset_t>::unload() {
    loaded_ = false;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
Handle<Asset_t> AssetRecord<Asset_t>::handle() {
    return handle_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
const std::filesystem::path& AssetRecord<Asset_t>::path() const {
    return PATH_;
}

template<typename Asset_t>
requires std::is_base_of_v<Asset, Asset_t>
bool AssetRecord<Asset_t>::isLoaded() const {
    return loaded_;
}
