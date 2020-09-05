#include "shader.h"

namespace MyEngine {
	namespace graphics {

		Shader::Shader(const char* vertPath, const char* fragPath)
		: m_vertPath(vertPath), m_fragPath(fragPath){
			m_ShaderID = load();
		}

		Shader::~Shader() {
			glDeleteProgram(m_ShaderID);
		}

		GLuint Shader::load() {
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = read_file(m_vertPath);
			std::string fragSourceString = read_file(m_fragPath);

			const char *vertSource = vertSourceString.c_str();
			const char *fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout << "Failed to compile vertex shader!\n Error: " << &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE) {
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout << "Failed to compile fragment shader!\n Error: " << &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);
		}

		GLint Shader::getUniformLocation(const GLchar* name) {
			return glGetUniformLocation(m_ShaderID, name);
		}

		void Shader::setUniformFloat(const GLchar* name, float value) {
			glUniform1f(getUniformLocation(name), value);
		}
		void Shader::setUniformInt(const GLchar* name, int value) {
			glUniform1i(getUniformLocation(name), value);
		}
		void Shader::setUniformVec2(const GLchar* name, const math::vec2& vector) {
			glUniform2f(getUniformLocation(name), vector.x, vector.y);
		}
		void Shader::setUniformVec3(const GLchar* name, const math::vec3& vector) {
			glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
		}
		void Shader::setUniformVec4(const GLchar* name, const math::vec4& vector) {
			glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
		}
		void Shader::setUniformMat4(const GLchar* name, const math::mat4& matrix) {
			glUniformMatrix4fv(Shader::getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}

		void Shader::enable() const {
			glUseProgram(m_ShaderID);
		}
		void Shader::disable() const {
			glUseProgram(0);
		}

}}