#pragma once

namespace Geom {

#pragma warning(push)
#pragma warning(disable: 4201)

struct Vector2f {
	union {
		float v[2];
		struct {
			float x;
			float y;
		};
	};
};

#pragma warning(pop)



}
