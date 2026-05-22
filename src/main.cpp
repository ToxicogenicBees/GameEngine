#include "Minesweeper/Boards/RandomBoard.hpp"
#include "Communication/Events/WindowCloseEvent.hpp"
#include "Communication/EngineEventQueue.hpp"
#include "Communication/EngineEventDispatcher.hpp"
#include "UserInput/InputSystem.hpp"
#include "Assets/AssetManager.hpp"
#include "Rendering/Window.hpp"
#include "Rendering/Texture.hpp"
#include "Types/Vector2.hpp"
#include <SDL3/SDL.h>

int main() {
    /*****************
      Initialization
    *****************/

    // Create a random board
    const Size BOARD_SIZE(25, 25);
    RandomBoard board(BOARD_SIZE);  // 25x25 board
    board.generate(100);        // 100 mines
    
    // Create the game window
    const Size WINDOW_SIZE = 32 * BOARD_SIZE;
    Window window("Minesweeper", WINDOW_SIZE);

    // Create asset manager
    AssetManager assets(window.renderer());

    // Initialize the tiles
    for (auto& tile : board) {
        tile->setState(TileState::REVEALED);
        if (tile->isMine())
            tile->texture = assets.loadTexture("tiles/mine.png");
        else
            tile->texture = assets.loadTexture("tiles/" + std::to_string((int)tile->value()) + ".png");
    }
    
    /**************
      Update Loop
    **************/

    // Initialize rendering
    SDL_Init(SDL_INIT_VIDEO);

    EngineEventDispatcher::subscribe<MouseButtonEvent>([](const MouseButtonEvent& e) {
        std::clog << "Mouse event: " << (int)e.button << "\n";
    });

    bool running = true;
    EngineEventDispatcher::subscribe<WindowCloseEvent>([&running](const WindowCloseEvent& e) {
        running = false;
    });

    while (running) {
        // Handle events
        InputSystem::poll();
        EngineEventQueue::dispatch();

        // Clear the frame
        window.clear(Color4{0, 0, 0, 255});

        // Draw tiles to the frame
        for (auto& tile : board)
            tile->render(window);

        // Render the window to the screen
        window.render();
    }

    // Quit rendering
    SDL_Quit();

    return 0;
}
