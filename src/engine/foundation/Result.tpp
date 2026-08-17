/*
    Result.tpp

    Template implementation of a result class, used for gracefully handling non-deterministic operations.
*/

namespace toxico {
    template<typename T, typename E>
    Result<T, E>::Result(T result, E error)
        : result_(std::move(result)),
          error_(std::move(error))
    {}

    template<typename T, typename E>
    Result<T, E>::Result(E error)
        : result_(std::nullopt),
          error_(std::move(error))
    {}

    template<typename T, typename E>
    bool Result<T, E>::has_value() const noexcept {
        return result_.has_value();
    }

    template<typename T, typename E>
    T& Result<T, E>::value() & {
        return result_.value();
    }

    template<typename T, typename E>
    const T& Result<T, E>::value() const & {
        return result_.value();
    }

    template<typename T, typename E>
    T&& Result<T, E>::value() && {
        return std::move(result_.value());
    }

    template<typename T, typename E>
    const T&& Result<T, E>::value() const && {
        return std::move(result_.value());
    }

    template<typename T, typename E>
    T& Result<T, E>::operator*() {
        return *result_;
    }

    template<typename T, typename E>
    const T& Result<T, E>::operator*() const {
        return *result_;
    }

    template<typename T, typename E>
    T* Result<T, E>::operator->() noexcept {
        return result_.operator->();
    }

    template<typename T, typename E>
    const T* Result<T, E>::operator->() const noexcept {
        return result_.operator->();
    }

    template<typename T, typename E>
    Result<T, E>::operator bool() const noexcept {
        return static_cast<bool>(result_);
    }

    template<typename T, typename E>
    const E& Result<T, E>::error() const noexcept {
        return error_;
    }
}
