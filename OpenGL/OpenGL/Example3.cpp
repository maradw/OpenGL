#include "Example3.h"
#include "IncludeGL.h"
#include <GL/glut.h>
#include <iostream>

#include"Figura.h"

//#include <iostream>
//#include <cmath>
Example3::Example3()
{
    camera = new Camera();
}
void Example3::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
   // camera->Init();
   // camera->SetPosition(Vector3(5, 2, 5));
    gluLookAt(5, 2, 5, 0, 0, 0, 0, 1, 0);
    
    glMatrixMode(GL_MODELVIEW);
}
void Example3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawAxis(30,2);
    DrawGrids(1);

    //camera->Update();

    polygon->DrawCube(5, 0, -5);
    polygon->DrawSphere(-5, 0, 5);
    polygon->DrawCone(3, 0, -7);

    glutSwapBuffers();
    //glFlush();

}
void Example3::KeyboardFunc(unsigned char key, int x, int y) 
{

}
void Example3::Idle()
{

}

