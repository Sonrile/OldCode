#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 objectColour;
uniform vec3 lightColour;
uniform vec3 lightPos;

void main()
{
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColour;
    //vec3 ambientResult = ambient * objectColour;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = diff * lightColour;

    vec3 result = (ambient + diffuse) * objectColour;
    FragColor = vec4(result, 1.0f);
}