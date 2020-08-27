#pragma once
#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace MyEngine {
	namespace graphics {
#define MAX_KEYS	1024
#define MAX_BUTTONS	32

	class Window {
	private:
		int m_Height, m_Width;
		double m_xpos, m_ypos;
		const char *m_Title;
		GLFWwindow* m_Window;
		bool m_Keys[MAX_KEYS];
		bool m_MouseButtons[MAX_BUTTONS];
		bool m_Closed;
		bool init();
		friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	public:
		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }
		Window(const char* name, int width, int height);
		bool closed() const;
		bool isKeyPressed(unsigned int keycode) const;
		bool isMousePressed(unsigned int button) const;
		void getMousePosition(double &x, double &y) const;

		void update();
		~Window();
	};
} }