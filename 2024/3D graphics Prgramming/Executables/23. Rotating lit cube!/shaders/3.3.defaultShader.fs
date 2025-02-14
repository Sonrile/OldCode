#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec2 texCoord;

uniform vec3 lightColour;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform sampler2D myTexture;

void main()
{
    // ambient
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColour;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    vec3 diffuse = lightColour * max(dot(norm, lightDir), 0.0f); // max(x, y) returns the greater of the two values (x or y)
                                                                // we use this so that the diffuse never becomes negative
    // specular
    float specularStrength = 0.35f;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflection = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflection), 0.0f), 32);
    vec3 specular = spec * specularStrength * lightColour;

    vec3 result = (ambient + diffuse + specular);
    FragColor = texture(myTexture, texCoord) * vec4(result, 1.0f);
}
