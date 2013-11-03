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

	T Length() const;
	T LengthSquared() const;

	Vector2T operator+() const;
	Vector2T operator-() const;
	Vector2T& operator+=(const Vector2T& vec);
	Vector2T& operator-=(const Vector2T& vec);
	Vector2T& operator*=(T multiplier);
	Vector2T& operator/=(T divisor);
};

#pragma warning(pop)

template<typename T>
T Vector2T<T>::LengthSquared() const
{
	return (x * x) + (y * y);
}

template<typename T>
T Vector2T<T>::Length() const
{
	return std::sqrt(LengthSquared());
}

template<typename T>
Vector2T<T> Vector2T<T>::operator+() const
{
	return *this;
}

template<typename T>
Vector2T<T> Vector2T<T>::operator-() const
{
	return Vector2T<T>(-x, -y);
}

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
Vector2T<T>& Vector2T<T>::operator*=(T multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}

template<typename T>
Vector2T<T>& Vector2T<T>::operator/=(T divisor)
{
	x /= divisor;
	y /= divisor;
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

template<typename T1, typename T2>
Vector2T<T1> operator*(const Vector2T<T1>& vec, T2 multiplier)
{
	Vector2T<T1> result(vec);
	result *= multiplier;
	return result;
}

template<typename T1, typename T2>
Vector2T<T2> operator*(T1 multiplier, const Vector2T<T2>& vec)
{
	Vector2T<T2> result(vec);
	result *= multiplier;
	return result;
}

template<typename T1, typename T2>
Vector2T<T1> operator/(const Vector2T<T1>& vec, T2 multiplier)
{
	Vector2T<T1> result(vec);
	result /= multiplier;
	return result;
}

template<typename T>
bool operator==(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}

template<typename T>
bool operator!=(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	return !(vec1 == vec2);
}

template<typename T>
T DotProduct(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

template<typename T>
T CrossProduct2D(const Vector2T<T>& vec1, const Vector2T<T>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

typedef Vector2T<float>  Vector2f;
typedef Vector2T<double> Vector2d;

}
