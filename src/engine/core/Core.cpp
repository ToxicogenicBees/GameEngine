/*
    Core.cpp

    Implementation of a low-level core engine layer.
*/

#include "core/Core.hpp"

namespace toxico {
    LoggerBase& Core::logger() {
        return modules_.get<LoggerBase>();
    }

    JobScheduler& Core::jobs() {
        return modules_.get<JobScheduler>();
    }

    ECS& Core::ecs() {
        return modules_.get<ECS>();
    }
}
