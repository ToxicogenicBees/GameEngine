/*
    main.cpp
*/

#include <iostream>

#include <platform/PlatformFactory.hpp>
#include <platform/files/Path.hpp>
#include <SDL3/SDL.h>

#include <testing/core/jobs/ThreadBalance.hpp>

using namespace toxico;

template<typename E>
void log(const E& error) {
    std::clog << "Error " << static_cast<int>(error.code()) << ": " << error.what() << "\n";
    std::exit(-1);
}

void fileTest() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        printf("SDL Initialization failed: %s\n", SDL_GetError());
        exit(-1);
    }

    auto platform = PlatformFactory::create();

    auto& clipboard = platform->clipboard();
    auto& files = platform->files();
    auto& dirs = platform->dirs();

    auto dir = dirs.executable();
    if (!dir)
        log(dir.error());
    
    auto file_result = files.open(*dir / Path{"MyFile.txt"}, FileOpenMode::ReadWrite);
    if (!file_result)
        log(file_result.error());

    auto& file = *file_result;

    {
        auto read_result = file->readAll();
        if (!read_result) {
            log(read_result.error());
            exit(-1);
        }

        std::string data;
        for (auto& byte : *read_result)
            data += static_cast<unsigned char>(byte);

        std::clog << data << "\n";
    }

    {
        std::vector<std::byte> data;
        for (char& c : std::string("\nHello, World!"))
            data.emplace_back(std::byte{static_cast<unsigned char>(c)});

        auto result = file->write(data);
        if (!result)
            log(result.error());
    }

    SDL_Quit();
}

int main() {
    using namespace test;

    ThreadBalance test({
        .pool = JobPool::Frame,
        .job_count = 1000,
        .yield_ms = 1
    });

    std::clog << test << "\n";

    return 0;
}
