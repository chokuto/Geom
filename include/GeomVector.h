#pragma once
#include <cmath>

/** ��ԃx�N�g���N���X (�C�ӎ���) */
template<typename T, size_t N>
struct CGeomVector {
	T v[N];			/**< ����(�z��\��) */

	/** ������2��v�Z */
	T LengthSquared() const
	{
		T result = 0;
		for (size_t i = 0; i < N; ++i) {
			result += v[i] * v[i];
		}
		return result;
	}

	/** �����v�Z */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** �[���x�N�g�� */
	static const CGeomVector Zero;
};

template<typename T, size_t N>
const CGeomVector<T,N> CGeomVector<T,N>::Zero = {};

// ���O�Ȃ�struct/union�ɑ΂���x���𖳎����邽�߈ꎞ�I�Ɍx��C4201�𖳌���
#pragma warning(push)
#pragma warning(disable: 4201)

/** ��ԃx�N�g���N���X (1�������ꉻ) */
template<typename T>
struct CGeomVector<T,1> {
	union {
		T v[1];		/**< ���� (�z��\��) */
		T x;		/**< x���� */
	};

	/** �R���X�g���N�^ (�������Ȃ�) */
	CGeomVector() {}
	/** �R���X�g���N�^ (�w��l�ŏ�����) */
	CGeomVector(T x0) : x(x0) {}

	/** ������2��v�Z */
	T LengthSquared() const
	{
		return x * x;
	}

	/** �����v�Z */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** �[���x�N�g�� */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,1> CGeomVector<T,1>::Zero(0);

/** 1������ԃx�N�g�� (float) */
typedef CGeomVector<float,1>  CGeomVector1f;
/** 1������ԃx�N�g�� (double) */
typedef CGeomVector<double,1> CGeomVector1d;

/** ��ԃx�N�g���N���X (2�������ꉻ) */
template<typename T>
struct CGeomVector<T,2> {
	union {
		T v[2];		/**< ����(�z��\��) */
		struct {
			T x;	/**< x���� */
			T y;	/**< y���� */
		};
	};

	/** �R���X�g���N�^ (�������Ȃ�) */
	CGeomVector() {}
	/** �R���X�g���N�^ (�w��l�ŏ�����) */
	CGeomVector(T x0, T y0) : x(x0), y(y0) {}

	/** ������2��v�Z */
	T LengthSquared() const
	{
		return (x * x) + (y * y);
	}

	/** �����v�Z */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** ��]��x�N�g���擾 */
	CGeomVector<T,2> RotatedVector(double angleInRadians) const
	{
		T cosA = std::cos(angleInRadians);
		T sinA = std::sin(angleInRadians);
		return CGeomVector<T,2>(
			(x * cosA) - (y * sinA),
			(x * sinA) + (y * cosA));
	}

	/** ��] */
	void Rotate(double angleInRadians)
	{
		*this = RotatedVector(angleInRadians);
	}

	/** �[���x�N�g�� */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,2> CGeomVector<T,2>::Zero(0,0);

/** 2������ԃx�N�g�� (float) */
typedef CGeomVector<float,2>  CGeomVector2f;
/** 2������ԃx�N�g�� (double) */
typedef CGeomVector<double,2> CGeomVector2d;

/** ��ԃx�N�g���N���X (3�������ꉻ) */
template<typename T>
struct CGeomVector<T,3> {
	union {
		T v[3];		/**< ����(�z��\��) */
		struct {
			T x;	/**< x���� */
			T y;	/**< y���� */
			T z;	/**< z���� */
		};
	};

	/** �R���X�g���N�^ (�������Ȃ�) */
	CGeomVector() {}
	/** �R���X�g���N�^ (�w��l�ŏ�����) */
	CGeomVector(T x0, T y0, T z0) : x(x0), y(y0), z(z0) {}

	/** ������2��v�Z */
	T LengthSquared() const{
		return (x * x) + (y * y) + (z * z);
	}

	/** �����v�Z */
	T Length() const
	{
		return std::sqrt(LengthSquared());
	}

	/** �[���x�N�g�� */
	static const CGeomVector Zero;
};

template<typename T>
const CGeomVector<T,3> CGeomVector<T,3>::Zero(0,0,0);

/** 3������ԃx�N�g�� (float) */
typedef CGeomVector<float,3>  CGeomVector3f;
/** 3������ԃx�N�g�� (double) */
typedef CGeomVector<double,3> CGeomVector3d;

#pragma warning(pop)

/** ��ԃx�N�g���̒P�����������Z�q */
template<typename T, size_t N>
CGeomVector<T,N> operator+(const CGeomVector<T,N>& vec)
{
	return vec;
}

/** ��ԃx�N�g���̒P�����������Z�q */
template<typename T, size_t N>
CGeomVector<T,N> operator-(const CGeomVector<T,N>& vec)
{
	CGeomVector<T,N> result(vec);
	result *= static_cast<T>(-1);
	return result;
}

/** ��ԃx�N�g���̉��Z������Z�q */
template<typename T, size_t N>
CGeomVector<T,N>& operator+=(CGeomVector<T,N> &vec1, const CGeomVector<T,N>& vec2)
{
	for (size_t i = 0; i < N; ++i) {
		vec1.v[i] += vec2.v[i];
	}
	return vec1;
}

/** ��ԃx�N�g���̌��Z������Z�q */
template<typename T, size_t N>
CGeomVector<T,N>& operator-=(CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	for (size_t i = 0; i < N; ++i) {
		vec1.v[i] -= vec2.v[i];
	}
	return vec1;
}

/** ��ԃx�N�g���̐ώZ(�X�J���[�{)������Z�q */
template<typename T, size_t N>
CGeomVector<T,N>& operator*=(CGeomVector<T,N>& vec, T multiplier)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] *= multiplier;
	}
	return vec;
}

/** ��ԃx�N�g���̐ώZ(�X�J���[�{)������Z�q */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N>& operator*=(CGeomVector<T1,N>& vec, T2 multiplier)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] *= static_cast<T1>(multiplier);
	}
	return vec;
}

/** ��ԃx�N�g���̏��Z(�X�J���[�{)������Z�q */
template<typename T, size_t N>
CGeomVector<T,N>& operator/=(CGeomVector<T,N>& vec, T divisor)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] /= divisor;
	}
	return vec;
}

/** ��ԃx�N�g���̏��Z(�X�J���[�{)������Z�q */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N>& operator/=(CGeomVector<T1,N>& vec, T2 divisor)
{
	for (size_t i = 0; i < N; ++i) {
		vec.v[i] /= static_cast<T1>(divisor);
	}
	return vec;
}

/** ��ԃx�N�g���̉��Z���Z�q */
template<typename T, size_t N>
CGeomVector<T,N> operator+(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	CGeomVector<T,N> result(vec1);
	result += vec2;
	return result;
}

/** ��ԃx�N�g���̌��Z���Z�q */
template<typename T, size_t N>
CGeomVector<T,N> operator-(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	CGeomVector<T,N> result(vec1);
	result -= vec2;
	return result;
}

/** ��ԃx�N�g���̐ώZ(�X�J���[�{)���Z�q */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N> operator*(const CGeomVector<T1,N>& vec, T2 multiplier)
{
	CGeomVector<T1,N> result(vec);
	result *= static_cast<T1>(multiplier);
	return result;
}

/** ��ԃx�N�g���̐ώZ(�X�J���[�{)���Z�q */
template<typename T1, typename T2, size_t N>
CGeomVector<T2,N> operator*(T1 multiplier, const CGeomVector<T2,N>& vec)
{
	CGeomVector<T2,N> result(vec);
	result *= static_cast<T2>(multiplier);
	return result;
}

/** ��ԃx�N�g���̏��Z(�X�J���[�{)���Z�q */
template<typename T1, typename T2, size_t N>
CGeomVector<T1,N> operator/(const CGeomVector<T1,N>& vec, T2 multiplier)
{
	CGeomVector<T1,N> result(vec);
	result /= static_cast<T1>(multiplier);
	return result;
}

/** ��ԃx�N�g���̔�r���Z�q */
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

/** ��ԃx�N�g���̔�r���Z�q */
template<typename T, size_t N>
bool operator!=(const CGeomVector<T,N>& vec1, const CGeomVector<T,N>& vec2)
{
	return !(vec1 == vec2);
}

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
T CrossProduct(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	return (vec1.x * vec2.y) - (vec1.y * vec2.x);
}

/** 3������ԃx�N�g���̊O�όv�Z */
template<typename T>
CGeomVector<T,3> CrossProduct(const CGeomVector<T,3>& vec1, const CGeomVector<T,3>& vec2)
{
	return CGeomVector<T,3>(
		(vec1.y * vec2.z) - (vec1.z * vec2.y),
		(vec1.z * vec2.x) - (vec1.x * vec2.z),
		(vec1.x * vec2.y) - (vec1.y * vec2.x));
}

/** 2�����x�N�g���̂Ȃ��p���v�Z (vec1����vec2�֔����v���) */
template<typename T>
T AngleBetween(const CGeomVector<T,2>& vec1, const CGeomVector<T,2>& vec2)
{
	// atan2(A�~B, A�EB) �Ƃ��Čv�Z
	return std::atan2(CrossProduct(vec1, vec2), DotProduct(vec1, vec2));
}
