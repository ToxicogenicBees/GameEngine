/*
    ErasedVector.tpp

    Template implementation of a type-erased collection of arbitrary data, stored in {numerical index, value} pairs.
*/

#include <utility>

namespace toxico {
    template<typename T>
    void ErasedVector::push_back(const T& value) {
        data_.push_back(
            std::make_any<T>(value)
        );
    }

    template<typename T, typename... Args>
    T& ErasedVector::emplace_back(Args&& ...args) {
        data_.emplace_back(
            std::make_any<T>(std::forward<Args>(args)...)
        );

        return back<T>();
    }

    template<typename T>
    const T& ErasedVector::at(std::size_t index) const {
        return std::any_cast<const T&>(data_.at(index));
    }

    template<typename T>
    T& ErasedVector::at(std::size_t index) {
        return std::any_cast<T&>(data_.at(index));
    }

    template<typename T>
    const T& ErasedVector::front() const {
        return std::any_cast<const T&>(data_.front());
    }

    template<typename T>
    T& ErasedVector::front() {
        return std::any_cast<T&>(data_.front());
    }

    template<typename T>
    const T& ErasedVector::back() const {
        return std::any_cast<const T&>(data_.back());
    }

    template<typename T>
    T& ErasedVector::back() {
        return std::any_cast<T&>(data_.back());
    }

    template<typename T>
    IterationRange<ErasedVector::const_iterator<T>> ErasedVector::iterate() const noexcept {
        return {
            const_iterator<T>(data_.begin(), data_.end()),
            const_iterator<T>(data_.end(), data_.end())
        };
    }

    template<typename T>
    IterationRange<ErasedVector::iterator<T>> ErasedVector::iterate() noexcept {
        return {
            iterator<T>(data_.begin(), data_.end()),
            iterator<T>(data_.end(), data_.end())
        };
    }
}
