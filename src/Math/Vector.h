#ifndef VECTOR_H
#define VECTOR_H

template<typename Type,size_t size>
struct Vector
{
    Type data[size];

  
    inline Type& operator[](size_t index) { return data[index]; }
    inline const Type& operator[](size_t index) const { return data[index]; }

    Vector operator+(const Vector& other) const
    {
        Vector result{};
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    Vector operator-(const  Vector& other) const
    {
        Vector result{};
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    Vector operator*(const Type& scalar) const
    {
        Vector result{};
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i] * scalar;
        }

        return result;
    }

    Vector operator/(const Type& scalar) const
    {
        Vector result{};
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i] /  scalar;
        }

        return result;
    }

    Vector& operator+=(const Vector& other) {
        for (size_t i = 0; i < size; ++i)
            data[i] += other.data[i];
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        for (size_t i = 0; i < size; ++i)
            data[i] -= other.data[i];
        return *this;
    }

    Vector& operator*=(Type scalar) {
        for (size_t i = 0; i < size; ++i)
            data[i] *= scalar;
        return *this;
    }

    Vector& operator/=(Type scalar) {
        for (size_t i = 0; i < size; ++i)
            data[i] /= scalar;
        return *this;
    }

    bool operator==(const Vector& other) const {
        for (size_t i = 0; i < size; ++i)
            if (data[i] != other.data[i])
                return false;
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    Vector Normalize(Vector<Type, size> a)
    {
        Vector result = {};
        return result;
    }

    float Length(Vector<Type, size> a)
    {
        result = 0.0f;
        return result;
    }

};



#endif