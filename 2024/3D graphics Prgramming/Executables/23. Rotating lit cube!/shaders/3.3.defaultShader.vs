#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexture;
layout (location = 2) in vec3 aNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 Normal;
out vec3 FragPos;
out vec2 texCoord;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f);
    // calculate the "normal matrix" (a matrix used to conver the normals to worldspace)
    Normal = mat3(transpose(inverse(model))) * aNormal;
    FragPos = vec3(model * vec4(aPos, 1.0f));
    texCoord = aTexture;
}

// note that the "inverse" of a matrix is an extremely costly operation and practically should be computed on the CPU
// before being passed as a uniform to the GPU. (just like we calculated the view, world & projection matrices on the CPU)