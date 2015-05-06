#pragma once
#include "GeomVector.h"

/** ��ԃx�N�g���̓��όv�Z */
template<typename T, size_t N>
T DotProduct(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	T result = 0;
	for (size_t i = 0; i < N; ++i) {
		result += vec1.v[i] * vec2.v[i];
	}
	return result;
}

/** 2������ԃx�N�g���̊O�όv�Z */
template<typename T>
T CrossProduct2D(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

/** 3������ԃx�N�g���̊O�όv�Z */
template<typename T>
CGeomVector<T,3> CrossProduct3D(const CGeomVector<T,3>& vec1, const CGeomVector<T,3>& vec2)
{
	return CGeomVector<T,3>(
		(vec1.y * vec2.z) - (vec1.z * vec2.y),
		(vec1.z * vec2.x) - (vec1.x * vec2.z),
		(vec1.x * vec2.y) - (vec1.y * vec2.x));
}
