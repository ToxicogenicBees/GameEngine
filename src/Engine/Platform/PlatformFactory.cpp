/*
    PlatformFactory.cpp

    Implementation of a platform factory, building a platform for specific build systems.
*/

#include "Platform/PlatformFactory.hpp"
#include "Platform/Platform.hpp"

#include "Platform/Implementations/Windows/WindowsDirectories.hpp"
#include "Platform/Implementations/STD/STDFileSystem.hpp"
#include "Platform/Implementations/SDL/SDLClipboard.hpp"

namespace toxico {
    std::unique_ptr<IPlatform> PlatformFactory::create() {
        auto platform = std::make_unique<Platform>();

        // @TODO: Add support for multiple operating systems
        // @TODO: Add base implementation

        platform->addModule<IPlatformDirectories>(std::make_unique<WindowsDirectories>());
        platform->addModule<IFileSystem>(std::make_unique<STDFileSystem>());
        platform->addModule<IClipboard>(std::make_unique<SDLClipboard>());

        return platform;
    }
}
