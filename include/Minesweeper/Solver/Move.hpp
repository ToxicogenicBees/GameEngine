/*
    Move.hpp

    Declaration of a simple struct containing minesweeper solver move states.
*/

#pragma once

#include <Math/Vector2.hpp>

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
    Move(MoveType type, Vector2 position);

    /**
     * @brief Constructor.
     * 
     * @param type The move type.
     */
    Move(MoveType type);
};

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param move The move being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const Move& move);
