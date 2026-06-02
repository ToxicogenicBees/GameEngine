/*
    MacroRule.cpp

    Implementation of a macro rule, composed of multiple rules.
*/

#include "Minesweeper/Solver/Rules/MacroRule.hpp"

void MacroRule::addRule(std::unique_ptr<Rule> rule) {
    rules_.push_back(std::move(rule));
}

void MacroRule::apply(const SolverState& states, std::vector<Move>& out) const {
    for (const auto& rule : rules_)
        rule->apply(states, out);
}
