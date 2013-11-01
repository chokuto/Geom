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
};

#pragma warning(pop)

typedef Vector2T<float>  Vector2f;
typedef Vector2T<double> Vector2d;

}
