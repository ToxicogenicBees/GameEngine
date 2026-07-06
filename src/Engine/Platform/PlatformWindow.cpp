/*
    PlatformWindow.cpp

    Implementation of an abstract engine window.
*/

#include "Platform/PlatformWindow.hpp"

PlatformWindow::PlatformWindow(const std::string& title, size_t width, size_t height)
    : TITLE_(title),
      size_(width, height)
{}

PlatformWindow::PlatformWindow(const std::string& title, Size size)
    : TITLE_(title),
      size_(size)
{}

PlatformWindow::PlatformWindow(const std::string& title)
    : TITLE_(title) {}

void PlatformWindow::resize(size_t width, size_t height) {
    size_ = Size(width, height);
    onResize(width, height);
}

void PlatformWindow::resize(Size size) {
    size_ = size;
    onResize(size.width(), size.height());
}

Size PlatformWindow::size() const {
    return size_;
}

void PlatformWindow::setState(WindowState state) {
    state_ = state;
    onStateChange(state);
}

WindowState PlatformWindow::state() const {
    return state_;
}

const std::string& PlatformWindow::title() const {
    return TITLE_;
}

double PlatformWindow::aspectRatio() const {
    return static_cast<double>(size_.width()) / static_cast<double>(size_.height());
}
