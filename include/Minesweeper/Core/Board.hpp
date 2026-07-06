/*
    Board.hpp

    Declaration for a minesweeper board.
*/

#pragma once

#include "Minesweeper/Core/AdjacencyMask.hpp"
#include "Minesweeper/Core/BitGrid.hpp"
#include <Events/BindableEvent.hpp>
#include <Math/Vector2.hpp>
#include <Geometry/Size.hpp>
#include <vector>

class ConstTileWrapper;
class TileWrapper;

class Board {
private:
    AdjacencyMask mask_;
    BitGrid revealed_;
    BitGrid mines_;
    BitGrid flags_;

    Size size_;
    size_t mine_count_;

public:
    /**
     * @brief Constructor.
     * 
     * @param mines A bit grid of mine data
     */
    Board(const BitGrid& mines);

    /**
     * @brief Constructor.
     */
    Board(Size size, size_t mine_count);

    /**
     * @brief Sets the board's adjacency mask.
     * 
     * @param mask The desired adjacency mask.
     */
    void setAdjacencyMask(const AdjacencyMask& mask);

    /**
     * @brief Gets the board's adjacency mask.
     * 
     * @return The adjacency mask.
     */
    AdjacencyMask adjacencyMask() const;

    /**
     * @brief Sets the size of the board.
     * 
     * @param size The new size of the board.
     */
    void setSize(Size size);

    /**
     * @brief Gets the size of the board.
     * 
     * @return The size of the board.
     */
    Size size() const;

    /**
     * @brief Applies the desired mine grid to the board.
     * 
     * @param mines The mine grid to apply to the board.
     */
    void setMineGrid(const BitGrid& mines);

    /**
     * @brief Gets the bit grid containing mine data.
     * 
     * @return The bit grid containing mine data.
     */
    BitGrid mineGrid() const;

    /**
     * @brief Sets the total number of mines.
     * 
     * @param count The total number of mines.
     */
    void setMineCount(size_t count);
    
    /**
     * @brief Gets the total number of mines.
     * 
     * @return The total number of mines.
     */
    size_t mineCount() const;

    /**
     * @brief Resets the board, clearing all mines, revealed tiles, and flags.
     */
    void reset();

    /**
     * @brief Gets if the board contains a tile at the specific index.
     * 
     * @param index The desired tile index.
     * @return True if the tile exists, and false otherwise.
     */
    bool contains(Vector2i index) const;

    /**
     * @brief Gets a wrapper for the tile index.
     *        Throws an error if the index is out of bounds of the board.
     * 
     * @param index The desired tile index.
     * @return A wrapper for this tile and it's operations.
     */
    ConstTileWrapper tile(Vector2i index) const;

    /**
     * @brief Gets a wrapper for the tile index.
     *        Throws an error if the index is out of bounds of the board.
     * 
     * @param index The desired tile index.
     * @return A wrapper for this tile and it's operations.
     */
    TileWrapper tile(Vector2i index);

    /**
     * @brief Gets the neighboring tile indices of an index.
     * 
     * @param index The desired tile index.
     * @return A vector of neighboring tile indices.
     */
    std::vector<Vector2i> neighbors(Vector2i index) const;

    /**
     * @brief Gets the number of mines around an index.
     * 
     * @param index The desired tile index.
     * @return The number of mines around an index.
     */
    uint8_t adjacentMineCount(Vector2i index) const;

    /**
     * @brief Gets the number of flags around an index.
     * 
     * @param index The desired tile index.
     * @return The number of flags around an index.
     */
    uint8_t adjacentFlagCount(Vector2i index) const;

    /**
     * @brief Gets the tile number shown on a revealed tile.
     *        Throws an error if the tile is not revealed
     * 
     * @param index The desired tile index.
     * @return The number on the revealed tile
     */
    uint8_t revealedNumber(Vector2i index) const;

    /**
     * @brief Gets if the desired tile is a mine.
     * 
     * @param index The desired tile index.
     * @return True if the tile is a mine, false otherwise.
     */
    bool isMine(Vector2i index) const;

    /**
     * @brief Gets if the desired tile is a flag.
     * 
     * @param index The desired tile index.
     * @return True if the tile is a flag, false otherwise.
     */
    bool isFlagged(Vector2i index) const;

    /**
     * @brief Gets if the desired tile is false flagged.
     * 
     * @param index The desired tile index.
     * @return True if the tile is false flagged, false otherwise.
     */
    bool isFalseFlagged(Vector2i index) const;

    /**
     * @brief Gets if the desired tile is revealed.
     * 
     * @param index The desired tile index.
     * @return True if the tile is revealed, false otherwise.
     */
    bool isRevealed(Vector2i index) const;

    /**
     * @brief Flags the desired tile
     * 
     * @param index The desired tile index.
     */
    void flag(Vector2i index);

    /**
     * @brief Unflags the desired tile
     * 
     * @param index The desired tile index.
     */
    void unflag(Vector2i index);

    /**
     * @brief Reveals the desired tile
     * 
     * @param index The desired tile index.
     */
    void reveal(Vector2i index);

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
     * @brief Gets if the board currently is empty.
     * 
     * @return True if the board is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Gets the total number of revealed tiles.
     * 
     * @return The total number of revealed tiles.
     */
    size_t revealedCount() const;

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
    template<typename Filter>
    std::vector<Vector2i> filterTiles(Filter filter);
};

/***
 * @brief Overloaded insertion operator
 * 
 * @param o A reference to an output stream
 * @param board The board being output to the stream
 * 
 * @result A reference to the output stream being output to
 */
std::ostream& operator<<(std::ostream& o, const Board& board);

#include "Minesweeper/Core/Board.tpp"
