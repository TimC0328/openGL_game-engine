#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "mesh.h"

int main()
{
    Display display(800, 600, "Hello!");

    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0)),
                          Vertex(glm::vec3(0, 0.5, 0)),
                          Vertex(glm::vec3(0.5, -0.5, 0)), };

    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));

    while(!display.IsClosed())
    {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);

        display.Update();
    }
    return 0;
}
