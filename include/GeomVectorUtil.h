#pragma once
#include "GeomVector.h"

/** 空間ベクトルの内積計算 */
template<typename T, size_t N>
T DotProduct(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	T result = 0;
	for (size_t i = 0; i < N; ++i) {
		result += vec1.v[i] * vec2.v[i];
	}
	return result;
}

/** 2次元空間ベクトルの外積計算 */
template<typename T>
T CrossProduct2D(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

/** 3次元空間ベクトルの外積計算 */
template<typename T>
CGeomVector<T,3> CrossProduct3D(const CGeomVector<T,3>& vec1, const CGeomVector<T,3>& vec2)
{
	return CGeomVector<T,3>(
		(vec1.y * vec2.z) - (vec1.z * vec2.y),
		(vec1.z * vec2.x) - (vec1.x * vec2.z),
		(vec1.x * vec2.y) - (vec1.y * vec2.x));
}

/** 2次元空間ベクトルの回転計算(反時計回り) */
template<typename T>
CGeomVector<T,2> Rotate2D(const CGeomVector<T,2>& vec, T angleInRadians)
{
	T cosA = std::cos(angleInRadians);
	T sinA = std::sin(angleInRadians);
	return CGeomVector<T,2>(
		(vec.x * cosA) - (vec.y * sinA),
		(vec.x * sinA) + (vec.y * cosA));
}

/** 2次元ベクトルのなす角を計算 (vec1からvec2へ反時計回り) */
template<typename T>
T Angle2D(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	// atan2(A×B, A・B) として計算
	return std::atan2(CrossProduct2D(vec1, vec2), DotProduct(vec1, vec2));
}
