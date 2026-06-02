/*
    SingleCellConstraintResolution.cpp

    Implementation for a rule that flags neighboring tiles when applicable.
*/

#include "Minesweeper/Solver/Rules/SingleCellConstraintResolution.hpp"
#include "Minesweeper/Solver/Rules/RevealNeighbors.hpp"
#include "Minesweeper/Solver/Rules/FlagNeighbors.hpp"

SingleCellConstraintResolution::SingleCellConstraintResolution() {
    addRule(std::make_unique<RevealNeighbors>());
    addRule(std::make_unique<FlagNeighbors>());
}
