#version 330 core
struct Material
{
    sampler2D ambient;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};

struct Light
{
    vec3 position;
    vec3 colour;
    float ambient;
};

uniform Material material;
uniform Light light;
uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;
in vec2 texCoord;

out vec4 FragColor;

void main()
{
    // ambient
    vec3 ambient = light.ambient * vec3(texture(material.ambient, texCoord));

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0f);
    vec3 diffuse = light.colour * diff * vec3(texture(material.ambient, texCoord));  // max(x, y) returns the greater of the two values (x or y)
                                                               // we use this so that the diffuse never becomes negative
    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflection = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflection), 0.0f), material.shininess);
    vec3 specular = light.colour * spec * vec3(texture(material.specular, texCoord));

    // emission
    vec3 emission = vec3(texture(material.emission, texCoord));

    vec3 result = (ambient + diffuse + specular + emission);
    FragColor = vec4(result, 1.0f);
}
