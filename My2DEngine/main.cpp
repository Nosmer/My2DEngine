#include <iostream>
#include "src/graphics/Window.h"
#include "src/math/Vec2.h"

int main() {
	//testing
	using namespace MyEngine;
	using namespace graphics;
	using namespace math;

	Window window("Test Window", 800, 600);
	glClearColor(0.2f, 0.3f, 0.4f, 0.5f);

	while (!window.closed()) {
		window.update();
	}
	return 0;
}