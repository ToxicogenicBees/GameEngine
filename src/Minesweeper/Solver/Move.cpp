/*
    Move.cpp

    Implementation of a simple struct containing minesweeper solver move states.
*/

#include "Minesweeper/Solver/Move.hpp"

Move::Move(MoveType type, Vector2 position)
    : type(type), position(position) {}

Move::Move(MoveType type)
    : type(type) {}

std::ostream& operator<<(std::ostream& o, const Move& move) {
    switch(move.type) {
        case (MoveType::FLAG):
            o << "Flagged: " << move.position;
            break;
        case (MoveType::REVEAL):
            o << "Revealed: " << move.position;
            break;
        default:
            o << "INVALID MOVE";
    }

    return o;
}
