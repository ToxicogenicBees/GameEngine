/*
    SingleCellConstraintResolution.hpp

    Declaration for a rule that flags neighboring tiles when applicable.
*/

#pragma once

#include "Minesweeper/Solver/Rules/MacroRule.hpp"

class SingleCellConstraintResolution : public MacroRule {
public:
    /**
     * @brief Constructor.
     */
    SingleCellConstraintResolution();
};
