#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 aTexCoord;
in float aSinTime;

out vec2 texCoord;
out vec3 myColour;
out float sinTime;

void main()
{
    gl_Position = vec4(aPos.x + aSinTime, aPos.y, aPos.z, 1.0);
    myColour = aColour;
    texCoord = aTexCoord;
    sinTime = aSinTime;
}