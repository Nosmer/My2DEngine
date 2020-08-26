#pragma once
#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace MyEngine { namespace graphics {

	class Window {
	private:
		int m_Height, m_Width;
		const char *m_Title;
		GLFWwindow* m_Window;
		bool init();
		bool m_Closed;

	public:
		bool closed() const;
		Window(const char* name, int width, int height);
		void update();
		~Window();
	};
} }