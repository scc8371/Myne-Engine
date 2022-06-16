#version 330 core
out vec4 FragColor;

in vec2 texCoord;
in vec4 tint;

uniform sampler2D tex0;

void main()
{
   FragColor = texture(tex0, texCoord) * tint;
}