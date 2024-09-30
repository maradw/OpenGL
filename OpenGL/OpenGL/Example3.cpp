#include "Example3.h"
#include "IncludeGL.h"
#include <GL/glut.h>
#include <iostream>
#include "Figura.h"

Example3::Example3()
{
    camera = new Camera();
}

void Example3::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST); // Habilitar el buffer de profundidad para la correcta renderización 3D
    camera->Init();
    glMatrixMode(GL_MODELVIEW);
    camera->SetPosition(Vector3(5, 2, 5));
    //camera->SetDirection(Vector3(0, 0, -1));
}

void Example3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiar color y profundidad
    camera->Update();
    DrawAxis(30, 2);
    DrawGrids(1);

    polygon->DrawCube(5, 0, -5);
    polygon->DrawSphere(-5, 0, 5);
    polygon->DrawCone(3, 0, -7);

    glutSwapBuffers();
}

void Example3::KeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        camera->MoveForward();
        break;
    case 's':
        camera->MoveBackward();
        break;
    case 'a':
        camera->StrafeLeft();
        break;
    case 'd':
        camera->StrafeRight();
        break;
    }
    glutPostRedisplay();
}

void Example3::SpecialFunc(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        camera->Rotate(-1.0f, 0.0f); // Rotar a la izquierda
        break;
    case GLUT_KEY_RIGHT:
        camera->Rotate(1.0f, 0.0f);  // Rotar a la derecha
        break;
    case GLUT_KEY_UP:
        camera->Rotate(0.0f, -1.0f); // Rotar hacia arriba
        break;
    case GLUT_KEY_DOWN:
        camera->Rotate(0.0f, 1.0f);  // Rotar hacia abajo
        break;
    }
    glutPostRedisplay();
}

void Example3::Idle()
{
    // Aquí puedes agregar animaciones si es necesario
}