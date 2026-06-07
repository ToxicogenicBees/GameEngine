/*
    BitGrid.cpp

    Implementation for a grid that stores bit data in a 2x2 grid
*/

#include "Minesweeper/Core/BitGrid.hpp"
#include <bit>

namespace {
    constexpr size_t requiredBytes(size_t bits) {
        return (bits + 7) / 8;
    }

    constexpr std::byte bitMask(size_t b) {
        return static_cast<std::byte>(0x80u >> b);
    }
}

void BitGrid::resetUnusedBits_() {
    size_t remaining_bits = bits_ & 7;
    if (remaining_bits > 0) {
        std::byte mask = static_cast<std::byte>(0xFFu << (8 - remaining_bits));
        bytes_.back() &= mask;
    }
}

// @TODO: check that the vector has an appropriate size
BitGrid::BitGrid(const Size& size, const std::vector<std::byte>& bytes)
    : bytes_(bytes),
      width_(size.width()),
      height_(size.height()),
      bits_(size.area())
{
    resetUnusedBits_();
}

BitGrid::BitGrid(const Size& size, bool value)
    : bytes_(requiredBytes(size.area()), std::byte(value ? 0xFF : 0x00)),
      width_(size.width()),
      height_(size.height()),
      bits_(size.area())
{
    resetUnusedBits_();
}

bool BitGrid::contains(const Vector2i& index) const noexcept {
    return index.x >= 0 && index.x < width_
        && index.y >= 0 && index.y < height_;
}

bool BitGrid::contains(size_t index) const noexcept {
    return index >= 0 && index < bits_;
}

bool BitGrid::get(const Vector2i& index) const {
    if (!contains(index))
        throw std::out_of_range("Invalid bit index");

    size_t lin_index = index.x + index.y * width_;
    size_t full_bytes = lin_index >> 3;
    size_t remaining_bits = lin_index & 7;
    return std::to_integer<bool>(bytes_[full_bytes] & bitMask(remaining_bits));
}

bool BitGrid::get(size_t index) const {
    if (!contains(index))
        throw std::out_of_range("Invalid bit index");

    size_t full_bytes = index >> 3;
    size_t remaining_bits = index & 7;
    return std::to_integer<bool>(bytes_[full_bytes] & bitMask(remaining_bits));
}

void BitGrid::set(const Vector2i& index, bool value) {
    if (!contains(index))
        throw std::out_of_range("Invalid bit index");

    size_t lin_index = index.x + index.y * width_;
    size_t full_bytes = lin_index >> 3;
    size_t remaining_bits = lin_index & 7;

    auto mask = bitMask(remaining_bits);
    bytes_[full_bytes] = (bytes_[full_bytes] & ~mask) | (std::byte(-static_cast<int>(value)) & mask);
}

void BitGrid::set(size_t index, bool value) {
    if (!contains(index))
        throw std::out_of_range("Invalid bit index");

    size_t full_bytes = index >> 3;
    size_t remaining_bits = index & 7;

    auto mask = bitMask(remaining_bits);
    bytes_[full_bytes] = (bytes_[full_bytes] & ~mask) | (std::byte(-static_cast<int>(value)) & mask);
}

void BitGrid::fill(bool value) {
    auto val = std::byte(value ? 0xFF : 0x00);
    std::fill(bytes_.begin(), bytes_.end(), val);
    resetUnusedBits_();
}

Size BitGrid::size() const noexcept {
    return {width_, height_};
}

void BitGrid::setSize(const Size& size) {
    // Set size
    width_ = size.width();
    height_ = size.height();
    bits_ = width_ * height_;

    // Update byte vector
    bytes_.resize(requiredBytes(bits_));
}

BitGrid BitGrid::operator|(const BitGrid& grid) const {
    if (grid.width_ != width_ || grid.height_ != height_)
        throw std::invalid_argument("Cannot operate on grids of different sizes");

    BitGrid result(Size{width_, height_});
    for (size_t i = 0; i < result.bytes_.size(); ++i)
        result.bytes_[i] = bytes_[i] | grid.bytes_[i];
    result.resetUnusedBits_();
    return result;
}

void BitGrid::operator|=(const BitGrid& grid) {
    *this = *this | grid;
}

BitGrid BitGrid::operator&(const BitGrid& grid) const {
    if (grid.width_ != width_ || grid.height_ != height_)
        throw std::invalid_argument("Cannot operate on grids of different sizes");

    BitGrid result(Size{width_, height_});
    for (size_t i = 0; i < result.bytes_.size(); ++i)
        result.bytes_[i] = bytes_[i] & grid.bytes_[i];
    result.resetUnusedBits_();
    return result;
}

void BitGrid::operator&=(const BitGrid& grid) {
    *this = *this & grid;
}

BitGrid BitGrid::operator^(const BitGrid& grid) const {
    if (grid.width_ != width_ || grid.height_ != height_)
        throw std::invalid_argument("Cannot operate on grids of different sizes");

    BitGrid result(Size{width_, height_});
    for (size_t i = 0; i < result.bytes_.size(); ++i)
        result.bytes_[i] = bytes_[i] ^ grid.bytes_[i];
    result.resetUnusedBits_();
    return result;
}

void BitGrid::operator^=(const BitGrid& grid) {
    *this = *this ^ grid;
}

BitGrid BitGrid::operator~() const {
    BitGrid result(Size{width_, height_});
    for (size_t i = 0; i < result.bytes_.size(); ++i)
        result.bytes_[i] = ~bytes_[i];
    result.resetUnusedBits_();
    return result;
}

bool BitGrid::operator==(const BitGrid& grid) const {
    size_t full_bytes = bits_ >> 3;
    size_t remaining_bits = bits_ & 7;

    for (size_t i = 0; i < full_bytes; ++i) {
        if (bytes_[i] != grid.bytes_[i])
            return false;
    }

    return true;
}

const std::vector<std::byte>& BitGrid::bytes() const noexcept {
    return bytes_;
}

size_t BitGrid::count() const {
    size_t total = 0;
    for (auto byte : bytes_)
        total += std::popcount(std::to_integer<uint8_t>(byte));
    return total;
}

std::vector<size_t> BitGrid::indices() const {
    std::vector<size_t> result;
    for (size_t i = 0; i < bits_; ++i) {
        if (get(i))
            result.push_back(i);
    }
    return result;
}

std::vector<Vector2i> BitGrid::positions() const {
    std::vector<Vector2i> result;
    for (size_t i = 0; i < bits_; ++i) {
        if (get(i)) {
            int x = i % width_;
            int y = i / width_;
            result.push_back({x, y});
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& o, const BitGrid& grid) {
    for (size_t y = 0; y < grid.size().height(); ++y) {
        for (size_t x = 0; x < grid.size().width(); ++x)
            o << grid.get({static_cast<int>(x), static_cast<int>(y)}) ? "1" : "0";
        o << "\n";
    }
    return o;
}
