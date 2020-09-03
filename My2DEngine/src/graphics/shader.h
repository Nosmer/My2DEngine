#pragma once

#include <vector>
#include <iostream>
#include <GL/glew.h>
#include "../math/Math_headers.h"
#include "../utils/fileutils.h";

namespace MyEngine {
	namespace graphics {

		class Shader {
		private:
			GLuint m_ShaderID;
			const char* m_fragPath, * m_vertPath;
			GLuint load();
			GLint getUniformLocation(GLchar *name);

		public:
			Shader(const char* vertPath, const char* FragPath);
			~Shader();

			void setUniformFloat(GLchar* name, float value);
			void setUniformInt(GLchar* name, int value);
			void setUniformVec2(GLchar* name, const math::vec2& vector);
			void setUniformVec3(GLchar* name, const math::vec3& vector);
			void setUniformVec4(GLchar* name, const math::vec4& vector);
			void setUniformMat4(GLchar *name, const math::mat4& matrix);

			void enable() const;
			void disable() const;
		};
}}