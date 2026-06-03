/*
    Renderable.hpp

    Declaration of an abstract class for renderable objects.
*/

#pragma once

class Renderable {
private:
    int layer_ = 0;
    int order_ = 0;

protected:
    friend class RenderSystem;

    /**
     * @brief Custom rendering logic.
     */
    virtual void onRender() = 0;

public:
    /**
     * @brief Constructor.
     */
    Renderable() = default;

    /**
     * @brief Set the layer of this sprite.
     * 
     * @param layer The desired layer.
     */
    void setLayer(int layer);

    /**
     * @brief Gets the layer of this sprite.
     * 
     * @return The layer of this sprite.
     */
    int layer() const;

    /**
     * @brief Set the order of this sprite.
     * 
     * @param order The desired order.
     */
    void setOrder(int order);

    /**
     * @brief Gets the order of this sprite.
     * 
     * @return The order of this sprite.
     */
    int order() const;

    /**
     * @brief Destructor.
     */
    virtual ~Renderable() = default;
};
