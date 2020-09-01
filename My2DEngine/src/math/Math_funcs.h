#pragma once

#include <math.h>
#define SP_PI 3.14159265358f

namespace MyEngine {
	namespace math {

		inline float toRadians(float degrees) {
			return (float)(degrees * (SP_PI / 180.0f));
		}

	}}