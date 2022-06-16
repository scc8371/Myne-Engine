#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTex;
layout (location = 2) in vec4 aTint;

out vec2 texCoord;
out vec4 tint;
uniform mat4 projection;

void main()
{
   gl_Position = projection * vec4(aPos.x, aPos.y, 0.0, 1.0);
   texCoord = aTex;
   tint = aTint;
}