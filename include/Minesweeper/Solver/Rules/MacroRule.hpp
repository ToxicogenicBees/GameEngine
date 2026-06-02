/*
    MacroRule.hpp

    Declaration of a macro rule, composed of multiple rules.
*/

#pragma once

#include "Minesweeper/Solver/Rules/Rule.hpp"
#include <vector>
#include <memory>

class MacroRule : public Rule {
private:
    std::vector<std::unique_ptr<Rule>> rules_;

public:
    /**
     * @brief Constructor.
     */
    MacroRule() = default;

    /**
     * @brief Add a rule to the level.
     * 
     * @param rule The rule to add.
     */
    void addRule(std::unique_ptr<Rule> rule);

    /**
     * @brief Applies the rule to a board.
     */
    void apply(const SolverState& states, std::vector<Move>& out) const override;
};
