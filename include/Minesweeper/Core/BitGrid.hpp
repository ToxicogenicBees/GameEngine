/*
    ByteGrid.hpp

    Declaration for a grid that stores bit data in a 2x2 grid
*/

#pragma once

#include <Math/Vector2.hpp>
#include <Geometry/Size.hpp>
#include <stdint.h>
#include <vector>

class BitGrid {
private:
    std::vector<uint8_t> bytes_;
    size_t width_ = 0;
    size_t height_ = 0;
    size_t bits_ = 0;

    /**
     * @brief Resets the unused bits of the last byte in the grid
     */
    void resetUnusedBits_();

public:
    /**
     * @brief Constructor
     * 
     * @param size The size of the grid
     * @param bytes A vector of bytes composing the grid
     */
    BitGrid(const Size& size, const std::vector<uint8_t>& bytes);

    /**
     * @brief Constructor
     * 
     * @param size The size of the grid
     * @param value The value of the grid (default is 0)
     */
    BitGrid(const Size& size, bool value = false);

    /**
     * @brief Constructor
     */
    BitGrid() = default;

    /**
     * @brief Gets if the grid has a bit at the specified index.
     * 
     * @param index The bit index.
     */
    bool contains(const Vector2i& index) const noexcept;

    /**
     * @brief Gets if the grid has a bit at the specified index.
     * 
     * @param index The bit index.
     */
    bool contains(size_t index) const noexcept;

    /**
     * @brief Gets the bit at the desired index.
     * 
     * @param index The bit index.
     * @return The value of the bit at this index
     */
    bool get(const Vector2i& index) const;

    /**
     * @brief Gets the bit at the desired index.
     * 
     * @param index The bit index.
     * @return The value of the bit at this index
     */
    bool get(size_t index) const;

    /**
     * @brief Sets the bit at the desired index.
     * 
     * @param index The bit index.
     * @param value The bit value.
     */
    void set(const Vector2i& index, bool value);

    /**
     * @brief Sets the bit at the desired index.
     * 
     * @param index The bit index.
     * @param value The bit value.
     */
    void set(size_t index, bool value);

    /**
     * @brief Fills the grid with the desired bit value.
     * 
     * @param value The desired bit value.
     */
    void fill(bool value);

    /**
     * @brief Gets the size of the bit grid.
     */
    Size size() const noexcept;

    /**
     * @brief Sets the size of the bit grid.
     *        This does not reformat the data in the grid.
     * @param size The desired size.
     */
    void setSize(const Size& size);

    /**
     * @brief Bit-wise OR operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise OR of the operation
     */
    BitGrid operator|(const BitGrid& grid) const;

    /**
     * @brief Bit-wise OR operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise OR of the operation
     */
    void operator|=(const BitGrid& grid);

    /**
     * @brief Bit-wise AND operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise AND of the operation
     */
    BitGrid operator&(const BitGrid& grid) const;

    /**
     * @brief Bit-wise AND operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise AND of the operation
     */
    void operator&=(const BitGrid& grid);

    /**
     * @brief Bit-wise XOR operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise XOR of the operation
     */
    BitGrid operator^(const BitGrid& grid) const;

    /**
     * @brief Bit-wise XOR operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise XOR of the operation
     */
    void operator^=(const BitGrid& grid);

    /**
     * @brief Bit-wise NOT operation
     * 
     * @param grid Another bit grid of the same size
     * @result The bit-wise NOT of the operation
     */
    BitGrid operator~() const;

    /**
     * @brief Compare two bit grids.
     * 
     * @param grid The other grid being compared
     * @result If the grids share the same data
     */
    bool operator==(const BitGrid& grid) const;

    /**
     * @brief Gets the raw bytes composing this grid.
     * 
     * @return The raw bytes.
     */
    const std::vector<uint8_t>& bytes() const noexcept;

    /**
     * @brief Gets the total number of bits in the grid.
     * 
     * @return The total number of bits in the grid.
     */
    size_t count() const;

    /**
     * @brief Gets the indices of the (set) bits in the grid.
     * 
     * @return The indices of (set) bits in the grid
     */
    std::vector<size_t> indices() const;

    /**
     * @brief Gets the positions of the (set) bits in the grid.
     * 
     * @return The positions of (set) bits in the grid
     */
    std::vector<Vector2i> positions() const;

    /***
     * @brief Overloaded insertion operator
     * 
     * @param o A reference to an output stream
     * @param grid The BitGrid being output to the stream
     * 
     * @result A reference to the output stream being output to
     */
    friend std::ostream& operator<<(std::ostream& o, const BitGrid& grid) {
        for (size_t y = 0; y < grid.size().height(); ++y) {
            for (size_t x = 0; x < grid.size().width(); ++x) {
                o << grid.get({(int)x, (int)y}) ? "1" : "0";
            }
            o << "\n";
        }
        return o;
    }
};
