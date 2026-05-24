/*
    MinesweeperApp.cpp

    Implementatino for an application that implements minesweeper
*/

#include "Minesweeper/MinesweeperApp.hpp"
#include "Minesweeper/Scenes/GameScene.hpp"
#include "Core/Services.hpp"

void MinesweeperApp::init() {
    Services::scenes()->loadScene<GameScene>();
}

void MinesweeperApp::shutdown() {

}

MinesweeperApp::MinesweeperApp()
    : Application("Minesweeper") {}