/*
    Board.hpp

    Declaration for a minesweeper board
*/

#pragma once

#include "Minesweeper/Tile.hpp"
#include "Types/Size.hpp"
#include <memory>
#include <vector>

class Board {
protected:
    using CIterator = std::vector<std::unique_ptr<Tile>>::const_iterator;
    using Iterator = std::vector<std::unique_ptr<Tile>>::iterator;

    std::vector<std::unique_ptr<Tile>> tiles_;
    Size size_;

public:
    /**
     * @brief Constructor
     * 
     * @param width The width of the board.
     * @param height The height of the board.
     */
    Board(const Size& size);

    /**
     * @brief Gets the tile at the specified coordinates.
     * 
     * @param position The position of the tile.
     * @return A pointer to the tile at the specified position.
     */
    Tile* getTile(const Vector2i& position) const;

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
     * @brief Generates the board with the desired number of mines.
     * 
     * @param mine_count The number of mines to be placed on the board.
     */
    virtual void generate(size_t mine_count) = 0;

    /**
     * @brief Gets an iterator to the beginning of the tiles vector
     * 
     * @return An iterator to the beginning of the tiles vector
     */
    Iterator begin();

    /**
     * @brief Gets a constant iterator to the beginning of the tiles vector
     * 
     * @return A constant iterator to the beginning of the tiles vector
     */
    CIterator cbegin() const;

    /**
     * @brief Gets a constant iterator to the beginning of the tiles vector
     * 
     * @return A constant iterator to the beginning of the tiles vector
     */
    CIterator cbegin();

    /**
     * @brief Gets an iterator to the end of the tiles vector
     * 
     * @return An iterator to the end of the tiles vector
     */
    Iterator end();

    /**
     * @brief Gets a constant iterator to the end of the tiles vector
     * 
     * @return A constant iterator to the end of the tiles vector
     */
    CIterator cend() const;

    /**
     * @brief Gets a constant iterator to the end of the tiles vector
     * 
     * @return A constant iterator to the end of the tiles vector
     */
    CIterator cend();

    /**
     * @brief Destructor
     */
    virtual ~Board() = default;
};
