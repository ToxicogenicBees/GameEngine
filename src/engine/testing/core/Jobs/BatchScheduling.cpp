/*
    BatchScheduling.cpp

    Implementation of a job batching test.
*/

#include "testing/core/jobs/BatchScheduling.hpp"
#include "core/jobs/batching/JobBatch.hpp"
#include "core/CoreFactory.hpp"
#include "core/utility/Timer.hpp"
#include <unordered_map>
#include <atomic>
#include <format>

namespace toxico::test {
    BatchScheduling::BatchScheduling(const JobTestConfig& config)
        : Test("Batch Scheduling"),
          CONFIG_(config)
    {}

    TestResult BatchScheduling::test() {
        // Create a job scheduler
        auto core = CoreFactory::create();
        auto& scheduler = core->jobs();

        // Send a batch of jobs to the scheduler
        std::atomic<std::size_t> completed_jobs{0};
        JobBatch batch;
        for (std::size_t i = 0; i < CONFIG_.job_count; ++i) {
            batch.push([this, &completed_jobs] {
                Timer timer;
                while (timer.milliseconds() < CONFIG_.yield_ms)
                    std::this_thread::yield();

                completed_jobs.fetch_add(1);
            });
        }

        // Yield for completion
        auto handle = scheduler.submit(CONFIG_.pool, std::move(batch));
        handle.wait();

        // Check for failures 
        if (completed_jobs.load() != CONFIG_.job_count) {
            return {
                .success = false,
                .info = std::format("{}/{} jobs, {} ms delay, {} thread(s)", completed_jobs.load(), CONFIG_.job_count, CONFIG_.yield_ms, scheduler.threads(CONFIG_.pool))
            };
        }

        // Test passed
        return {
            .success = true,
            .info = std::format("{} jobs, {} ms delay, {} thread(s)", CONFIG_.job_count, CONFIG_.yield_ms, scheduler.threads(CONFIG_.pool))
        };
    }
}
