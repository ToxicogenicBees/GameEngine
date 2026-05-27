/*
    Move.hpp

    A simple struct containing minesweeper solver move states.
*/

#pragma once

#include <Types/Vector2.hpp>
#include <optional>

enum class MoveType {
    FLAG,
    REVEAL
};

struct Move {
    MoveType type;
    Vector2i position;

    /**
     * @brief Constructor.
     * 
     * @param type The move type.
     * @param position The move position.
     */
    Move(MoveType type, const Vector2& position)
        : type(type), position(position) {}

    /**
     * @brief Constructor.
     * 
     * @param type The move type.
     */
    Move(MoveType type)
        : type(type) {}

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param move The move being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Move& move) {
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
};
