/*
    ThreadBalance.cpp

    Implementation of a thread balance test.
*/

#include "Testing/Core/Jobs/ThreadBalance.hpp"
#include "Core/Jobs/Batching/JobBatch.hpp"
#include "Core/CoreFactory.hpp"
#include "Core/Utility/Timer.hpp"
#include <unordered_map>
#include <sstream>
#include <atomic>
#include <format>
#include <thread>

namespace toxico::test {
    ThreadBalance::ThreadBalance(const JobTestConfig& config)
        : Test("Thread Balancing"),
          CONFIG_(config)
    {}

    TestResult ThreadBalance::test() {
        // Create a job scheduler
        auto core = CoreFactory::create();
        auto& scheduler = core->jobs();

        // Run a batch of jobs and track what thread completed it
        std::unordered_map<std::thread::id, size_t> completors;
        std::atomic<size_t> completed_jobs{0};
        std::mutex mutex;
        JobBatch batch;
        for (size_t i = 0; i < CONFIG_.job_count; ++i) {
            batch.push([this, &completors, &mutex, &completed_jobs] {
                Timer timer;
                while (timer.milliseconds() < CONFIG_.yield_ms)
                    std::this_thread::yield();

                completed_jobs.fetch_add(1);
                {
                    std::unique_lock lock(mutex);
                    ++completors[std::this_thread::get_id()];
                }
            });
        }

        // Yield for completion
        auto handle = scheduler.submit(CONFIG_.pool, std::move(batch));
        handle.wait();

        // Collect thread job counts
        std::stringstream thread_counts;
        for (auto& [id, count] : completors)
            thread_counts << count << " ";

        // Check for failures 
        if (completed_jobs.load() != CONFIG_.job_count) {
            return {
                .success = false,
                .info = std::format("{}- {}/{} jobs, {} ms delay, {} thread(s)", thread_counts.str(), completed_jobs.load(), CONFIG_.job_count, CONFIG_.yield_ms, scheduler.threads(CONFIG_.pool))
            };
        }

        // Test passed
        return {
            .success = true,
            .info = std::format("{}- {} jobs, {} ms delay, {} thread(s)", thread_counts.str(), CONFIG_.job_count, CONFIG_.yield_ms, scheduler.threads(CONFIG_.pool))
        };
    }
}
