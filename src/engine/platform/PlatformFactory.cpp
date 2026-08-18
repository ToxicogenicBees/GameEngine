/*
    PlatformFactory.cpp

    Implementation of a platform factory, building a platform for specific build systems.
*/

#include "platform/PlatformFactory.hpp"
#include "platform/Platform.hpp"

#include "platform/implementations/windows/WindowsDirectories.hpp"
#include "platform/implementations/STD/STDFileSystem.hpp"
#include "platform/implementations/SDL/SDLClipboard.hpp"

namespace toxico {
    std::unique_ptr<Platform> PlatformFactory::create() {
        auto platform = std::make_unique<Platform>();

        // @TODO: Add support for multiple operating systems
        // @TODO: Add base implementation

        platform->addModule<IDirectories>(std::make_unique<WindowsDirectories>());
        platform->addModule<IFileSystem>(std::make_unique<STDFileSystem>());
        platform->addModule<IClipboard>(std::make_unique<SDLClipboard>());

        return platform;
    }
}
