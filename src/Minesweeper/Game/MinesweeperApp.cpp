/*
    MinesweeperApp.cpp

    Implementation for an application that implements minesweeper
*/

#include "Minesweeper/Game/MinesweeperApp.hpp"
#include "Minesweeper/Game/Scenes/IntermediateBoard.hpp"
#include <Core/Services.hpp>

void MinesweeperApp::init() {
    Services::scenes()->loadScene<IntermediateBoard>();
}

void MinesweeperApp::shutdown() {

}

MinesweeperApp::MinesweeperApp()
    : Application("Minesweeper") {}