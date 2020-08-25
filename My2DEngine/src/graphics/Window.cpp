#include "Window.h"

namespace MyEngine { namespace graphics {
	void windowResize(GLFWwindow* window, int width, int height);

	Window::Window(const char *title, int width, int height) {
		//basic initialisation
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();
	}

	bool Window::init() {
		//creating a GLFW window
		if (!glfwInit()) {
			std::cout << "ErrorAbort" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			glfwTerminate();
			std::cout << "Failed to create a window!" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);
		return true;
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window);
	}

	void Window::update(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void windowResize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
	}
}}