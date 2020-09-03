#version 330 core

layout (location = 0) in vec4 position;

uniform mat4 projection_matrix;
uniform mat4 view_matrix = mat4(1.0);
uniform mat4 model_matrix = mat4(1.0);

void main(){
	gl_Position = projection_matrix * position;
}