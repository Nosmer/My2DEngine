#include "Window.h"

namespace MyEngine { namespace graphics {
	void window_Resize(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char *title, int width, int height) {
		//basic initialisation
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if (!init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++) {
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++) {
			m_MouseButtons[i] = false;
		}
	}

	bool Window::init() {
		//creating a GLFW window
		if (!glfwInit()) {
			std::cout << "Failed to initialize GFWL" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window) {
			glfwTerminate();
			std::cout << "Failed to create a window" << std::endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, window_Resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		//initializing GLEW
		if (glewInit() != GLEW_OK) {
			std::cout << "Failed to initialize GLEW" << std::endl;
			return false;
		}

		std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

		return true;
	}

	bool Window::isKeyPressed(unsigned int keycode) const {
		if (keycode >= MAX_KEYS)
			return false;
		return m_Keys[keycode];
	}

	bool Window::isMousePressed(unsigned int button) const {
		if (button >= MAX_BUTTONS)
			return false;
		return m_MouseButtons[button];
	}

	void Window::getMousePosition(double &x, double &y) const {
		x = m_xpos;
		y = m_ypos;
	}

	bool Window::closed() const {
		return glfwWindowShouldClose(m_Window);
	}
	void Window::clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update(){
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	Window::~Window() {
		glfwTerminate();
	}

	void window_Resize(GLFWwindow *window, int width, int height) {
			glViewport(0, 0, width, height);
	}

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_xpos = xpos;
		win->m_ypos = ypos;
	}
}}