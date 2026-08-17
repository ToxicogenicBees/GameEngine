/*
    PMR.hpp

    Declaration of memory resource container aliases.
*/

#pragma once

#include <memory_resource>
#include <vector>
#include <string>
#include <unordered_map>

namespace toxico {
    template<class T>
    using Vector = std::pmr::vector<T>;

    template <class T>
    using Queue = std::pmr::queue<T>;

    using String = std::pmr::string;

    template<class K, class V>
    using HashMap = std::pmr::unordered_map<K, V>;

    template<class T>
    using Set = std::pmr::unordered_set<T>;
}