#pragma once
#include <iostream>
#include <GLFW/glfw3.h>

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