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
    glEnable(GL_DEPTH_TEST); 
    camera->Init();
    glMatrixMode(GL_MODELVIEW);
   //glutSpecialFunc(TPSKeyboardFunc);
    camera->SetPosition(Vector3(0, 2, 8));
}
//camera->SetDirection(Vector3(0, 0, -1));
void Example3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    camera->Update();
    DrawAxis(30, 2);
    DrawGrids(1);
   // polygon->DrawCube(-1, 1, 1);
    polygon->DrawPiramid(2, 1, 1);
    polygon->DrawIcosahedron(4, 1, 1);
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
    case 'z':
        camera->Rotate(-1.0f, 0.0f); 
        break;
    case 'x':
        camera->Rotate(1.0f, 0.0f); 
        break;
    case 'c':
        camera->Rotate(0.0f, -1.0f);
        break;
    case 'v':
        camera->Rotate(0.0f, 1.0f);
        break;
    }

    glutPostRedisplay();
}

void Example3::TPSKeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        camera->MoveForward();
        break;
    case '2':
        camera->MoveBackward();
        break;
    case '3':
        camera->StrafeLeft();
        break;
    case '4':
        camera->StrafeRight();
        break;
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