#include <iostream>
#include "src/graphics/Window.h"
#include "src/math/Math_headers.h"

int main() {
	//testing
	using namespace MyEngine;
	using namespace graphics;
	using namespace math;

	Window window("Test Window", 800, 600);
	glClearColor(0.2f, 0.3f, 0.4f, 0.5f);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	position.elements[12] = 2.0f;

	vec4 column = position.columns[3];
	std::cout << column << std::endl;

	while (!window.closed()) {
		window.update();
	}
	return 0;
}