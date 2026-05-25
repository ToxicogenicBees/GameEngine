/*
    Board.hpp

    Declaration for a minesweeper board
*/

#pragma once

#include <GameObject/GameObject.hpp>
#include <Components/SpriteComponent.hpp>
#include "Minesweeper/Objects/Tile.hpp"
#include "Types/Size.hpp"
#include <functional>
#include <memory>
#include <vector>

enum class BoardState {
    PLAYING,
    WIN,
    LOSE
};

class Board : public GameObject {
private:
    /**
     * @brief Populates the board with the desired number of tiles
     * 
     * @param size The desired board size
     * @param tile_creator Tile creator method
     * @param tile_destroyer Tile destroyer method; accepts a Tile pointer
     */
    template <typename Creator, typename Destroyer>
    void populateTiles_(const Size& size, Creator tile_creator, Destroyer tile_destroyer);

    /**
     * @brief Updates the neighbors of all the tiles
     */
    void assignNeighbors_();

protected:
    SpriteComponent* sprite_;
    std::vector<Tile*> tiles_;
    Size size_;

    /**
     * @brief Assign a certain number of tiles to be mines
     * 
     * @param mine_count The number of mines to be placed on the board.
     */
    virtual void populateMines(size_t mine_count) = 0;

    /**
     * @brief Custom intialization logic
     */
    void onInit() override;

    /**
     * @brief Custom update logic
     * 
     * @param dt Time between updates
     */
    void onUpdate(double dt) override;

public:
    /**
     * @brief Constructor
     */
    Board();

    /**
     * @brief Gets the tile at the specified coordinates.
     * 
     * @param position The position of the tile.
     * @return A pointer to the tile at the specified position.
     */
    Tile* getTile(const Vector2i& position) const;

    /**
     * @brief Gets the tile at the specified coordinates.
     * 
     * @param pixel The pixel location of the tile.
     * @return A pointer to the tile at the specified position.
     */
    Tile* tileAt(const Vector2i& pixel) const;

    /**
     * @brief Gets the size of the board.
     * 
     * @return The size of the board.
     */
    Size size() const;

    /**
     * @brief Generates the board with the desired number of mines.
     * 
     * @param mine_count The number of mines to be placed on the board.
     */
    template <typename Creator, typename Destroyer>
    void generate(const Size& size, size_t mine_count, Creator tile_creator, Destroyer tile_destroyer);

    /**
     * @brief Returns a vector of tile pointers.
     * 
     * @return A vector of tile pointers.
     */
    std::vector<Tile*> tiles() const;

    /**
     * @brief Destructor
     */
    virtual ~Board() = default;
};

#include "Minesweeper/Objects/Boards/Board.tpp"
