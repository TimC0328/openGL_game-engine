#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    Display display(WIDTH, HEIGHT, "Hello!");

    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
                          Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)), };

    unsigned int indicies[] = {0, 1, 2};

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]), indicies, sizeof(indicies)/sizeof(indicies[0]));
    Mesh mesh2("./res/monkey3.obj");
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpeg");
    Camera camera(glm::vec3(0,0,-3), 70.0f, (float)WIDTH/(float)HEIGHT, 0.01f, 1000.0f);
    Transform transform;

    float counter = 0.0f;

    while(!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        float sinCounter = sinf(counter);
        float cosCounter = cosf(counter);

        transform.GetPos().x = sinCounter;
        transform.GetPos().z = cosCounter;
        transform.GetRot().x = counter;
        transform.GetRot().y = counter;
        transform.GetRot().z = counter;
        //transform.GetScale() *= cosCounter;

        shader.Bind();
        texture.Bind();
        shader.Update(transform, camera);
        mesh2.Draw();

        display.Update();
        counter += 0.01f;
    }
    return 0;
}
