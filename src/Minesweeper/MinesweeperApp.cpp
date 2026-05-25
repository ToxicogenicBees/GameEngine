/*
    MinesweeperApp.cpp

    Implementatino for an application that implements minesweeper
*/

#include "Minesweeper/MinesweeperApp.hpp"
#include "Minesweeper/Scenes/EasyBoard.hpp"
#include "Core/Services.hpp"

void MinesweeperApp::init() {
    Services::scenes()->loadScene<EasyBoard>();
}

void MinesweeperApp::shutdown() {

}

MinesweeperApp::MinesweeperApp()
    : Application("Minesweeper") {}