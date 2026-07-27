/*
    main.cpp
*/

#include <iostream>

#include <Platform/Path.hpp>
#include <Platform/PlatformFactory.hpp>
#include <SDL3/SDL.h>

#include <Core/Jobs/ThreadPool.hpp>

using namespace toxico;

template<typename E>
void log(const E& error) {
    std::clog << "Error " << static_cast<int>(error.code()) << ": " << error.what() << "\n";
    std::exit(-1);
}

template<typename T>
struct JobLog {
    std::thread::id id;
    T result;
};

int main() {
    // if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    //     printf("SDL Initialization failed: %s\n", SDL_GetError());
    //     return -1;
    // }

    // auto platform = PlatformFactory::create();

    // auto& clipboard = platform->clipboard();
    // auto& files = platform->files();
    // auto& dirs = platform->dirs();

    // auto dir = dirs.executable();
    // if (!dir)
    //     log(dir.error());
    
    // auto file_result = files.open(*dir / Path{"MyFile.txt"}, FileOpenMode::ReadWrite);
    // if (!file_result)
    //     log(file_result.error());

    // auto& file = *file_result;

    // {
    //     auto read_result = file->readAll();
    //     if (!read_result) {
    //         log(read_result.error());
    //         return -1;
    //     }

    //     std::string data;
    //     for (auto& byte : *read_result)
    //         data += static_cast<unsigned char>(byte);

    //     std::clog << data << "\n";
    // }

    // {
    //     std::vector<std::byte> data;
    //     for (char& c : std::string("\nHello, World!"))
    //         data.emplace_back(std::byte{static_cast<unsigned char>(c)});

    //     auto result = file->write(data);
    //     if (!result)
    //         log(result.error());
    // }

    // SDL_Quit();
    // return 0;

    {
        // Create a thread pool to consume work
        ThreadPool pool(15);

        // Define a task to be done
        std::vector<JobLog<int>> results;
        auto task = [&results](std::size_t input) {
            // Simulate heavy work
            std::this_thread::sleep_for(std::chrono::milliseconds(5));

            // Run a (thread safe) operation to validate successful work
            results[input] = {std::this_thread::get_id(), static_cast<int>(input * 5)};
        };

        // Create jobs
        constexpr std::size_t TOTAL_JOBS = 1000;
        results.assign(TOTAL_JOBS, {});
        
        for (std::size_t i = 0; i < TOTAL_JOBS; ++i) {
            pool.submit([i, task] {
                task(i);
            });
        }

        // Yield for all of these jobs to complete
        pool.wait();

        // Output results
        for (auto result : results)
            std::clog << std::setw(2) << result.id << ": " << result.result << "\n";
    }

    return 0;
}
