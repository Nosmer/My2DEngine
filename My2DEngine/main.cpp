#include <iostream>
#include "src/graphics/Window.h"
#include "src/math/Math_headers.h"
//#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"

int main() {
	//testing
	using namespace MyEngine;
	using namespace graphics;
	using namespace math;

	Window window("Test Window", 800, 600);
	glClearColor(0.2f, 0.3f, 0.4f, 0.5f);

	GLuint vbo;
	GLfloat vertices[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();

	while (!window.closed()) {
		window.clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.update();
	}
	return 0;
}