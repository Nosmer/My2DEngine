#pragma once
#include <GL/glew.h>

namespace MyEngine {
	namespace graphics {

		class Buffer {
		private:
			GLuint m_BufferID;
			GLuint m_ComponentCount;

		public:
			Buffer(GLfloat *data, GLsizei count, GLuint componentCount);
			inline GLuint getComponentCount() const { return m_ComponentCount; }

			void bind() const;
			void unbind() const;
		};
}}