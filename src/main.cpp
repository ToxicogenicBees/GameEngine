/*
    main.cpp
*/

#include <iostream>

#include <platform/PlatformFactory.hpp>
#include <platform/files/Path.hpp>
#include <SDL3/SDL.h>

#include <testing/core/jobs/ThreadBalance.hpp>
#include <foundation/math/Vector.hpp>

using namespace toxico;

template<typename E>
void log(const E& error) {
    std::clog << "Error " << static_cast<int>(error.code()) << ": " << error.what() << "\n";
    std::exit(-1);
}

// @TODO: Move file operations into a separate test
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

#include <testing/core/ecs/ECSUnitTest.hpp>

int main() {
    using namespace toxico::test;

    ECSUnitTest test;
    std::clog << test << "\n";

    return 0;
}
