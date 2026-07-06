/*
    PlatformWindow.hpp

    Declaration of an abstract engine window.
*/

#pragma once

#include "Geometry/Size.hpp"
#include <string>

enum class WindowState {
    Windowed,
    WindowedFullscreen,
    Fullscreen,
    Borderless,
};

class PlatformWindow {
private:
    const std::string TITLE_;

    WindowState state_ = WindowState::Windowed;
    Size size_;

protected:
    /**
     * @brief Custom resize logic.
     */
    virtual void onResize(size_t width, size_t height) = 0;

    /**
     * @brief Custom state change logic.
     */
    virtual void onStateChange(WindowState state) = 0;

public:
    /**
     * @brief Constructor
     * 
     * @param title The title of the window to create.
     * @param width The initial width of the window.
     * @param height The initial height of the window.
     */
    PlatformWindow(const std::string& title, size_t width, size_t height);

    /**
     * @brief Constructor
     * 
     * @param title The title of the window to create.
     * @param size The initial size of the window.
     */
    PlatformWindow(const std::string& title, Size size);

    /**
     * @brief Constructor
     * 
     * @param title The title of the window to create.
     */
    PlatformWindow(const std::string& title);

    /**
     * @brief Resizes the window.
     * 
     * @param width The new width of the window.
     * @param height The new height of the window.
     */
    void resize(size_t width, size_t height);

    /**
     * @brief Resizes the window.
     * 
     * @param size The new size of the window.
     */
    void resize(Size size);

    /**
     * @brief Gets the size of the window.
     * 
     * @return The size of the window.
     */
    Size size() const;

    /**
     * @brief Sets the state of the window.
     * 
     * @param state The window state.
     */
    void setState(WindowState state);

    /**
     * @brief Gets the state of the window.
     * 
     * @return The window state.
     */
    WindowState state() const;

    /**
     * @brief Gets the title of the window.
     * 
     * @return The title of the window.
     */
    const std::string& title() const;

    /**
     * @brief Gets the aspect ratio of the window.
     */
    double aspectRatio() const;

    /**
     * @brief Destructor.
     */
    virtual ~PlatformWindow() = default;
};
