/*
    MinesweeperApp.cpp

    Implementatino for an application that implements minesweeper
*/

#include "Minesweeper/MinesweeperApp.hpp"
#include "Minesweeper/Scenes/IntermediateBoard.hpp"
#include "Core/Services.hpp"

void MinesweeperApp::init() {
    Services::scenes()->loadScene<IntermediateBoard>();
}

void MinesweeperApp::shutdown() {

}

MinesweeperApp::MinesweeperApp()
    : Application("Minesweeper") {}