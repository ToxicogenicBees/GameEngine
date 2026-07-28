/*
    BatchScheduling.cpp

    Implementation of a job batching test.
*/

#include "Testing/Core/Jobs/BatchScheduling.hpp"
#include "Core/Jobs/Batching/JobBatch.hpp"
#include "Core/CoreFactory.hpp"
#include <unordered_map>
#include <atomic>
#include <format>

namespace toxico::test {
    BatchScheduling::BatchScheduling()
        : Test("Batch Scheduling") {}

    Result<std::string, bool> BatchScheduling::execute() {
        // Create a job scheduler
        auto core = CoreFactory::create();
        auto& scheduler = core->jobs();

        // Send a batch of jobs to a pool and yield for completion.
        auto test = [&scheduler](JobPool pool, std::size_t jobs) -> std::size_t {
            std::atomic<std::size_t> completed_jobs{0};
            JobBatch batch;

            for (std::size_t i = 0; i < jobs; ++i) {
                batch.push([&completed_jobs] {
                    completed_jobs.fetch_add(1);
                });
            }

            auto handle = scheduler.submit(pool, std::move(batch));
            handle.wait();

            return completed_jobs;
        };

        // Test each pool on a large set of jobs
        const std::size_t JOBS = 1000;
        std::unordered_map<std::string, std::size_t> results {
            {"Background",  test(JobPool::Background, JOBS)},
            {"Frame",       test(JobPool::Frame, JOBS)},
        };

        // Check for failures 
        for (auto& [pool, completed] : results) {
            if (completed != JOBS)
                return std::format("{} pool executed {}/{} jobs.", pool, completed, JOBS);
        }

        // Test passed
        return true;
    }
}
