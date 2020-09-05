#pragma once

#include <vector>
#include <Gl/glew.h>
#include "buffer.h"

namespace MyEngine {
	namespace graphics {

		class VertexArray {
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*> m_Buffers;

		public:
			VertexArray();
			~VertexArray();

			void addBuffer(Buffer *buffer, GLuint index);
			void bind() const;
			void unbind() const;
		};
}}