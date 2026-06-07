/*
    Renderable.hpp

    Declaration of an abstract class for renderable objects.
*/

#pragma once

class Renderable {
private:
    int layer_ = 0;
    int order_ = 0;

public:
    /**
     * @brief Assignment operator (deleted).
     * 
     * @param other Another renderable object.
     */
    Renderable& operator=(const Renderable& other) = delete;

    /**
     * @brief Assignment operator (deleted).
     * 
     * @param other Another renderable object.
     */
    Renderable& operator=(Renderable&& other) = delete;

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
