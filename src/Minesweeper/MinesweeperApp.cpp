/*
    MinesweeperApp.cpp

    Implementatino for an application that implements minesweeper
*/

#include "Minesweeper/MinesweeperApp.hpp"
#include "Minesweeper/Scenes/GameScene.hpp"

void MinesweeperApp::init() {
    api()->setScene<GameScene>();
}

void MinesweeperApp::shutdown() {

}

MinesweeperApp::MinesweeperApp()
    : Application("Minesweeper") {}