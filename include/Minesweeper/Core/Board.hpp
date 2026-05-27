/*
    Board.hpp

    Declaration for a minesweeper board.
*/

#pragma once

#include "Minesweeper/Core/BitGrid.hpp"
#include <Types/Vector2.hpp>
#include <Types/Size.hpp>
#include <vector>

class Board {
private:
    BitGrid revealed_;
    BitGrid mines_;
    BitGrid flags_;

public:
    /**
     * @brief Constructor.
     */
    Board() = default;

    /**
     * @brief Constructor.
     * 
     * @param size The size of the field
     */
    Board(const Size& size);

    /**
     * @brief Constructor.
     * 
     * @param mines A bit grid of mine data
     */
    Board(const BitGrid& mines);

    /**
     * @brief Gets if the board contains a tile at the specific index.
     * 
     * @param index The desired tile index.
     * @return True if the tile exists, and false otherwise.
     */
    bool contains(const Vector2i& index) const;

    /**
     * @brief Gets the neighboring tile indices of an index.
     * 
     * @param index The desired tile index.
     * @return A vector of neighboring tile indices.
     */
    std::vector<Vector2i> neighbors(const Vector2i& index) const;

    /**
     * @brief Gets the number of mines around an index.
     * 
     * @param index The desired tile index.
     * @return The number of mines around an index.
     */
    uint8_t adjacentMineCount(const Vector2i& index) const;

    /**
     * @brief Gets the number of flags around an index.
     * 
     * @param index The desired tile index.
     * @return The number of flags around an index.
     */
    uint8_t adjacentFlagCount(const Vector2i& index) const;

    /**
     * @brief Gets the tile number shown on a revealed tile.
     *        Throws an error if the tile is not revealed
     * 
     * @param index The desired tile index.
     * @return The number on the revealed tile
     */
    uint8_t revealedNumber(const Vector2i& index) const;

    /**
     * @brief Gets if the desired tile is a mine.
     * 
     * @param index The desired tile index.
     * @return True if the tile is a mine, false otherwise.
     */
    bool isMine(const Vector2i& index) const;

    /**
     * @brief Gets if the desired tile is a flag.
     * 
     * @param index The desired tile index.
     * @return True if the tile is a flag, false otherwise.
     */
    bool isFlagged(const Vector2i& index) const;

    /**
     * @brief Gets if the desired tile is revealed.
     * 
     * @param index The desired tile index.
     * @return True if the tile is revealed, false otherwise.
     */
    bool isRevealed(const Vector2i& index) const;

    /**
     * @brief Flags the desired tile
     * 
     * @param index The desired tile index.
     */
    void flag(const Vector2i& index);

    /**
     * @brief Unflags the desired tile
     * 
     * @param index The desired tile index.
     */
    void unflag(const Vector2i& index);

    /**
     * @brief Reveals the desired tile
     * 
     * @param index The desired tile index.
     */
    void reveal(const Vector2i& index);

    /**
     * @brief Sets the size of the board.
     * 
     * @param size The desired size.
     */
    void setSize(const Size& size);

    /**
     * @brief Gets the size of the board.
     * 
     * @return The size of the board.
     */
    Size size() const;

    /**
     * @brief Gets the width of the board.
     * 
     * @return The width of the board.
     */
    size_t width() const;

    /**
     * @brief Gets the height of the board.
     * 
     * @return The height of the board.
     */
    size_t height() const;

    /**
     * @brief Gets whether the board has been cleared or not.
     * 
     * @return True if the board is cleared, false otherwise.
     */
    bool isCleared() const;

    /**
     * @brief Gets whether the board has been lost or not.
     * 
     * @return True if the board is lost, false otherwise.
     */
    bool isLost() const;

    /**
     * @brief Gets the total number of revealed tiles.
     * 
     * @return The total number of revealed tiles.
     */
    size_t revealedCount() const;

    /**
     * @brief Gets the total number of mines.
     * 
     * @return The total number of mines.
     */
    size_t mineCount() const;

    /**
     * @brief Gets the total number of flagged tiles.
     * 
     * @return The total number of flagged tiles.
     */
    size_t flagCount() const;

    /**
     * @brief Gets the bit grid containing revealed tile data.
     * 
     * @return The bit grid containing revealed tile data.
     */
    BitGrid revealedGrid() const;

    /**
     * @brief Gets the bit grid containing mine data.
     * 
     * @return The bit grid containing mine data.
     */
    BitGrid mineGrid() const;

    /**
     * @brief Gets the bit grid containing flag data.
     * 
     * @return The bit grid containing flag data.
     */
    BitGrid flagGrid() const;

    /**
     * @brief Gets a vector of all tile indexes in the board.
     * 
     * @return A vector of all tile indexes.
     */
    std::vector<Vector2i> allTiles() const;

    /**
     * @brief Gets a vector of tiles that satisfy a specific condition
     * 
     * @param filter A function that accepts a tile index and returns if it should be accepted.
     */
    template <typename Filter>
    std::vector<Vector2i> filterTiles(Filter filter);

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param board The board being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const Board& board) {
        const int X_END_ROW = board.size().width() - 1;
        const int Y_END_ROW = board.size().height() - 1;
        for (int y = 0; y < board.size().height(); ++y) {
            for (int x = 0; x < board.size().width(); ++x) {
                Vector2i index(x, y);
                int count = board.adjacentMineCount(index);
                if (board.isRevealed(index)) {
                    if (board.isMine(index))
                        o << "x";
                    else
                        o << count;
                }
                else if (board.isFlagged(index))
                    o << "/";
                else
                    o << "-";
                o << ((x == X_END_ROW && y != Y_END_ROW) ? "\n" : " ");
            }
        }

        return o;
    }
};

#include "Minesweeper/Core/Board.tpp"
