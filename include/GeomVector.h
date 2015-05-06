#pragma once
#include <cmath>

#pragma warning(push)
#pragma warning(disable: 4201)

template<typename T>
struct CGeomVector2T {
	union {
		T v[2];
		struct {
			T x;
			T y;
		};
	};

	CGeomVector2T() {}
	CGeomVector2T(T x0, T y0) : x(x0), y(y0) {}

	T Length() const;
	T LengthSquared() const;

	CGeomVector2T operator+() const;
	CGeomVector2T operator-() const;
	CGeomVector2T& operator+=(const CGeomVector2T& vec);
	CGeomVector2T& operator-=(const CGeomVector2T& vec);
	CGeomVector2T& operator*=(T multiplier);
	CGeomVector2T& operator/=(T divisor);
};

#pragma warning(pop)

template<typename T>
T CGeomVector2T<T>::LengthSquared() const
{
	return (x * x) + (y * y);
}

template<typename T>
T CGeomVector2T<T>::Length() const
{
	return std::sqrt(LengthSquared());
}

template<typename T>
CGeomVector2T<T> CGeomVector2T<T>::operator+() const
{
	return *this;
}

template<typename T>
CGeomVector2T<T> CGeomVector2T<T>::operator-() const
{
	return CGeomVector2T<T>(-x, -y);
}

template<typename T>
CGeomVector2T<T>& CGeomVector2T<T>::operator+=(const CGeomVector2T<T>& vec)
{
	x += vec.x;
	y += vec.y;
	return *this;
}

template<typename T>
CGeomVector2T<T>& CGeomVector2T<T>::operator-=(const CGeomVector2T<T>& vec)
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

template<typename T>
CGeomVector2T<T>& CGeomVector2T<T>::operator*=(T multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}

template<typename T>
CGeomVector2T<T>& CGeomVector2T<T>::operator/=(T divisor)
{
	x /= divisor;
	y /= divisor;
	return *this;
}

template<typename T>
CGeomVector2T<T> operator+(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	CGeomVector2T<T> result(vec1);
	result += vec2;
	return result;
}

template<typename T>
CGeomVector2T<T> operator-(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	CGeomVector2T<T> result(vec1);
	result -= vec2;
	return result;
}

template<typename T1, typename T2>
CGeomVector2T<T1> operator*(const CGeomVector2T<T1>& vec, T2 multiplier)
{
	CGeomVector2T<T1> result(vec);
	result *= multiplier;
	return result;
}

template<typename T1, typename T2>
CGeomVector2T<T2> operator*(T1 multiplier, const CGeomVector2T<T2>& vec)
{
	CGeomVector2T<T2> result(vec);
	result *= multiplier;
	return result;
}

template<typename T1, typename T2>
CGeomVector2T<T1> operator/(const CGeomVector2T<T1>& vec, T2 multiplier)
{
	CGeomVector2T<T1> result(vec);
	result /= multiplier;
	return result;
}

template<typename T>
bool operator==(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	return (vec1.x == vec2.x) && (vec1.y == vec2.y);
}

template<typename T>
bool operator!=(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	return !(vec1 == vec2);
}

template<typename T>
T DotProduct(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

template<typename T>
T CrossProduct2D(const CGeomVector2T<T>& vec1, const CGeomVector2T<T>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

typedef CGeomVector2T<float>  CGeomVector2f;
typedef CGeomVector2T<double> CGeomVector2d;

