/*
    Core.cpp

    Implementation of a low-level core engine layer.
*/

#include "core/Core.hpp"

namespace toxico {
    JobScheduler& Core::jobs() {
        return modules_.get<JobScheduler>();
    }
}
