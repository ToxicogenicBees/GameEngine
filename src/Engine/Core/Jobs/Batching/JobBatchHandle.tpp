/*
    JobbatchHandle.tpp

    Template implementation of a job batch handle.
*/

#pragma once

#include "Core/Jobs/Batching/JobBatchHandle.hpp"

namespace toxico {
    template<typename Iter>
    requires std::input_iterator<Iter> && std::same_as<std::iter_value_t<Iter>, JobHandle>
    JobBatchHandle::JobBatchHandle(Iter begin, Iter end)
        : handles_(begin, end) {}
}
