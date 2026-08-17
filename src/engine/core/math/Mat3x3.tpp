/*
    Mat3x3.tpp

    Template implementation of a 3x3 matrix.
*/

namespace toxico {
    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat3x3 Mat3x3::operator*(T s) const {
        Mat3x3 result(*this);
        for (auto& val : result.data_)
            val *= s;
        return result;
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat3x3& Mat3x3::operator*=(T s) {
        for (auto& val : data_)
            val *= s;
        return *this;
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat3x3 Mat3x3::operator/(T s) const {
        Mat3x3 result(*this);
        for (auto& val : result.data_)
            val /= s;
        return result;
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat3x3& Mat3x3::operator/=(T s) {
        for (auto& val : data_)
            val /= s;
        return *this;
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    Mat3x3 operator*(T s, const Mat3x3& mat) {
        Mat3x3 result(mat);
        for (auto& val : result.data_)
            val *= s;
        return result;
    }
}
