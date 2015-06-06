#pragma once
#include <cmath>

/** 空間ベクトルクラス (任意次元) */
template<typename T, size_t N>
struct CGeomVector {
	T v[N];			/**< 成分(配列表現) */

	/** 長さの2乗計算 */
	T LengthSquared() const
	{
		T result = 0;
		for (size_t i = 0; i < N; ++i) {
			result += v[i] * v[i];
		}
		return result;
	}

	/** 長さ計算 */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** ゼロベクトル */
	static const CGeomVector Zero;
};

template<typename T, size_t N>
const CGeomVector<T,N> CGeomVector<T,N>::Zero = {};

// 名前なしstruct/unionに対する警告を無視するため一時的に警告C4201を無効化
#pragma warning(push)
#pragma warning(disable: 4201)

/** 空間ベクトルクラス (1次元特殊化) */
template<typename T>
struct CGeomVector<T,1> {
	union {
		T v[1];		/**< 成分 (配列表現) */
		T x;		/**< x成分 */
	};

	/** コンストラクタ (初期化なし) */
	CGeomVector() {}
	/** コンストラクタ (指定値で初期化) */
	CGeomVector(T x0) : x(x0) {}

	/** 長さの2乗計算 */
	T LengthSquared() const
	{
		return x * x;
	}

	/** 長さ計算 */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** ゼロベクトル */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,1> CGeomVector<T,1>::Zero(0);

/** 1次元空間ベクトル (float) */
typedef CGeomVector<float,1>  CGeomVector1f;
/** 1次元空間ベクトル (double) */
typedef CGeomVector<double,1> CGeomVector1d;

/** 空間ベクトルクラス (2次元特殊化) */
template<typename T>
struct CGeomVector<T,2> {
	union {
		T v[2];		/**< 成分(配列表現) */
		struct {
			T x;	/**< x成分 */
			T y;	/**< y成分 */
		};
	};

	/** コンストラクタ (初期化なし) */
	CGeomVector() {}
	/** コンストラクタ (指定値で初期化) */
	CGeomVector(T x0, T y0) : x(x0), y(y0) {}

	/** 長さの2乗計算 */
	T LengthSquared() const
	{
		return (x * x) + (y * y);
	}

	/** 長さ計算 */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** 回転後ベクトル取得 */
	CGeomVector<T,2> RotatedVector(double angleInRadians) const
	{
		T cosA = std::cos(angleInRadians);
		T sinA = std::sin(angleInRadians);
		return CGeomVector<T,2>(
			(x * cosA) - (y * sinA),
			(x * sinA) + (y * cosA));
	}

	/** 回転 */
	void Rotate(double angleInRadians)
	{
		*this = RotatedVector(angleInRadians);
	}

	/** ゼロベクトル */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,2> CGeomVector<T,2>::Zero(0,0);

/** 2次元空間ベクトル (float) */
typedef CGeomVector<float,2>  CGeomVector2f;
/** 2次元空間ベクトル (double) */
typedef CGeomVector<double,2> CGeomVector2d;

/** 空間ベクトルクラス (3次元特殊化) */
template<typename T>
struct CGeomVector<T,3> {
	union {
		T v[3];		/**< 成分(配列表現) */
		struct {
			T x;	/**< x成分 */
			T y;	/**< y成分 */
			T z;	/**< z成分 */
		};
	};

	/** コンストラクタ (初期化なし) */
	CGeomVector() {}
	/** コンストラクタ (指定値で初期化) */
	CGeomVector(T x0, T y0, T z0) : x(x0), y(y0), z(z0) {}

	/** 長さの2乗計算 */
	T LengthSquared() const{
		return (x * x) + (y * y) + (z * z);
	}

	/** 長さ計算 */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** ゼロベクトル */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,3> CGeomVector<T,3>::Zero(0,0,0);

/** 3次元空間ベクトル (float) */
typedef CGeomVector<float,3>  CGeomVector3f;
/** 3次元空間ベクトル (double) */
typedef CGeomVector<double,3> CGeomVector3d;

#pragma warning(pop)

/** 空間ベクトルの単項正符号演算子 */
template<typename T, size_t N>
CGeomVector<T,N> operator+(const CGeomVector<T,N>& vec)
{
	return vec;
}

/** 空間ベクトルの単項負符号演算子 */
template<typename T, size_t N>
CGeomVector<T,N> operator-(const CGeomVector<T,N>& vec)
{
	CGeomVector<T,N> result(vec);
	result *= static_cast<T>(-1);
	return result;
}

/** 空間ベクトルの加算代入演算子 */
template<typename T, size_t N>
CGeomVector<T,N>& operator+=(CGeomVector<T,N> &vec1, const CGeomVector<T,N>& vec2)
{
	for (size_t i = 0; i < N; ++i) {
		vec1.v[i] += vec2.v[i];
	}
	return vec1;
}

/** 空間ベクトルの減算代入演算子 */
template<typename T, size_t N>
CGeomVector<T,N>& operator-=(CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	for (size_t i = 0; i < N; ++i) {
		vec1.v[i] -= vec2.v[i];
	}
	return vec1;
}

/** 空間ベクトルの積算(スカラー倍)代入演算子 */
template<typename T, size_t N>
CGeomVector<T,N>& operator*=(CGeomVector<T,N>& vec, T multiplier)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] *= multiplier;
	}
	return vec;
}

/** 空間ベクトルの積算(スカラー倍)代入演算子 */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N>& operator*=(CGeomVector<T1,N>& vec, T2 multiplier)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] *= static_cast<T1>(multiplier);
	}
	return vec;
}

/** 空間ベクトルの除算(スカラー倍)代入演算子 */
template<typename T, size_t N>
CGeomVector<T,N>& operator/=(CGeomVector<T,N>& vec, T divisor)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] /= divisor;
	}
	return vec;
}

/** 空間ベクトルの除算(スカラー倍)代入演算子 */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N>& operator/=(CGeomVector<T1,N>& vec, T2 divisor)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] /= static_cast<T1>(divisor);
	}
	return vec;
}

/** 空間ベクトルの加算演算子 */
template<typename T, size_t N>
CGeomVector<T,N> operator+(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	CGeomVector<T,N> result(vec1);
	result += vec2;
	return result;
}

/** 空間ベクトルの減算演算子 */
template<typename T, size_t N>
CGeomVector<T,N> operator-(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	CGeomVector<T,N> result(vec1);
	result -= vec2;
	return result;
}

/** 空間ベクトルの積算(スカラー倍)演算子 */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N> operator*(const CGeomVector<T1,N>& vec, T2 multiplier)
{
	CGeomVector<T1,N> result(vec);
	result *= static_cast<T1>(multiplier);
	return result;
}

/** 空間ベクトルの積算(スカラー倍)演算子 */
template<typename T1, typename T2, size_t N>
CGeomVector<T2,N> operator*(T1 multiplier, const CGeomVector<T2,N>& vec)
{
	CGeomVector<T2,N> result(vec);
	result *= static_cast<T2>(multiplier);
	return result;
}

/** 空間ベクトルの除算(スカラー倍)演算子 */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N> operator/(const CGeomVector<T1,N>& vec, T2 multiplier)
{
	CGeomVector<T1,N> result(vec);
	result /= static_cast<T1>(multiplier);
	return result;
}

/** 空間ベクトルの比較演算子 */
template<typename T, size_t N>
bool operator==(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	for (size_t i = 0; i < N; ++i) {
		if (vec1.v[i] != vec2.v[i]) {
			return false;
		}
	}
	return true;
}

/** 空間ベクトルの比較演算子 */
template<typename T, size_t N>
bool operator!=(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	return !(vec1 == vec2);
}

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
T CrossProduct(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

/** 3次元空間ベクトルの外積計算 */
template<typename T>
CGeomVector<T,3> CrossProduct(const CGeomVector<T,3>& vec1, const CGeomVector<T,3>& vec2)
{
	return CGeomVector<T,3>(
		(vec1.y * vec2.z) - (vec1.z * vec2.y),
		(vec1.z * vec2.x) - (vec1.x * vec2.z),
		(vec1.x * vec2.y) - (vec1.y * vec2.x));
}

/** 2次元ベクトルのなす角を計算 (vec1からvec2へ反時計回り) */
template<typename T>
T AngleBetween(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	// atan2(A×B, A・B) として計算
	return std::atan2(CrossProduct(vec1, vec2), DotProduct(vec1, vec2));
}
