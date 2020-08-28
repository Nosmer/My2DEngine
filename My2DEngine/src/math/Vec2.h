#pragma once
#include <iostream>

namespace MyEngine {
	namespace math {

		struct vec2 {
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			vec2& add(const vec2& other);
			vec2& sub(const vec2& other);
			vec2& mul(const vec2& other);
			vec2& div(const vec2& other);

			//overloading operators
			friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
			friend vec2 operator+(vec2 left, const vec2& right);
			friend vec2 operator-(vec2 left, const vec2& right);
			friend vec2 operator*(vec2 left, const vec2& right);
			friend vec2 operator/(vec2 left, const vec2& right);
			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);
			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);
		};
} }