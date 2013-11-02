#pragma once

namespace Geom {

#pragma warning(push)
#pragma warning(disable: 4201)

template<typename T>
struct Vector2T {
	union {
		T v[2];
		struct {
			T x;
			T y;
		};
	};

	Vector2T() {}
	Vector2T(T x0, T y0) : x(x0), y(y0) {}

	Vector2T& operator+=(const Vector2T& vec);
	Vector2T& operator-=(const Vector2T& vec);
};

#pragma warning(pop)

template<typename T>
Vector2T<T>& Vector2T<T>::operator+=(const Vector2T<T>& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

template<typename T>
Vector2T<T>& Vector2T<T>::operator-=(const Vector2T<T>& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

template<typename T>
Vector2T<T> operator+(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	Vector2T<T> result(vec1);
	result += vec2;
	return result;
}

template<typename T>
Vector2T<T> operator-(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	Vector2T<T> result(vec1);
	result -= vec2;
	return result;
}

template<typename T>
T DotProduct(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

typedef Vector2T<float>  Vector2f;
typedef Vector2T<double> Vector2d;

}
