#ifndef VECTOR_H
#define VECTOR_H
template<typename Type,size_t size>
struct Vector
{
    Type data[size];
};

template<typename Type, size_t size>
bool Equal(Vector<Type, size> a, Vector<Type, size> b)
{

}

template<typename Type, size_t size>
bool NotEqual(Vector<Type, size> a, Vector<Type, size> b)
{

}

template<typename Type, size_t size>
Vector<Type, size> Add(Vector<Type, size> a, Vector<Type, size> b)
{

}

template<typename Type, size_t size>
Vector<Type, size> Subtract(Vector<Type, size> a, Vector<Type, size> b)
{

}


template<typename Type, size_t size>
Vector<Type, size> Mul(Vector<Type, size> a, Vector<Type, size> b)
{

}

template<typename Type, size_t size>
Vector<Type, size> Div(Vector<Type, size> a, Vector<Type, size> b)
{

}


template<typename Type, size_t size>
Vector<Type, size> Normalize(Vector<Type, size> a)
{

}

template<typename Type, size_t size>
float Length(Vector<Type, size> a)
{

}

#endif