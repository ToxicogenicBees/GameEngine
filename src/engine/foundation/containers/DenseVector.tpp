/*
    DenseVector.tpp

    Template implementation of a container with swap-and-pop erase semantics.
*/

namespace toxico {
    template<typename T>
    requires std::is_move_assignable_v<T>
    const T& DenseVector<T>::operator[](size_t index) const {
        return data_[index];
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    T& DenseVector<T>::operator[](size_t index) {
        return data_[index];
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    const T& DenseVector<T>::at(size_t index) const {
        return data_.at(index);
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    T& DenseVector<T>::at(size_t index) {
        return data_.at(index);
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    const T& DenseVector<T>::back() const {
        return data_.back();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    T& DenseVector<T>::back() {
        return data_.back();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    size_t DenseVector<T>::size() const noexcept {
        return data_.size();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    bool DenseVector<T>::empty() const noexcept {
        return data_.empty();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    void DenseVector<T>::reserve(size_t capacity) {
        data_.reserve(capacity);
    }
    
    template<typename T>
    requires std::is_move_assignable_v<T>
    template<typename... Args>
    T& DenseVector<T>::emplace_back(Args&&... args) {
        return data_.emplace_back(std::forward<Args>(args)...);
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    void DenseVector<T>::push_back(const T& value) {
        data_.push_back(value);
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    void DenseVector<T>::push_back(T&& value) {
        data_.push_back(std::move(value));
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    bool DenseVector<T>::erase(size_t index) noexcept {
        // Ensure the index passed is valid
        const auto size = size();
        if (index >= size)
            return false;

        // Swap elements in memory
        const auto last = size - 1;
        bool swapped = false;
        if (index != last) {
            data_[index] = std::move(data_[last]);
            swapped = true;
        }

        // Erase the desired entity
        data_.pop_back();
        return swapped;
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    void DenseVector<T>::clear() noexcept {
        data_.clear();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    const T* DenseVector<T>::data() const noexcept {
        return data_.data();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    T* DenseVector<T>::data() noexcept {
        return data_.data();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::const_iterator DenseVector<T>::cbegin() const noexcept {
        return data_.cbegin();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::const_iterator DenseVector<T>::begin() const noexcept {
        return data_.begin();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::iterator DenseVector<T>::begin() noexcept {
        return data_.begin();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::const_iterator DenseVector<T>::cend() const noexcept {
        return data_.cend();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::const_iterator DenseVector<T>::end() const noexcept {
        return data_.end();
    }

    template<typename T>
    requires std::is_move_assignable_v<T>
    DenseVector<T>::iterator DenseVector<T>::end() noexcept {
        return data_.end();
    }
}
