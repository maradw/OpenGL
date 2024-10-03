#include "Example6.h"
#include "IncludeGL.h"
#include <iostream>
Example6::Example6()
{
}

void Example6::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    CreateCubeDisplayList();
	glMatrixMode(GL_MODELVIEW);

}

void Example6::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glCallList(cubeList);

}
void Example6::KeyboardFunc(unsigned char key, int x, int y)
{

}
void Example6::CreateCubeDisplayList() {
    // Generar un nuevo Display List
    cubeList = glGenLists(1);

    // Iniciar la definición del Display List
    glNewList(cubeList, GL_COMPILE);

    // Dibujar el cubo
    glBegin(GL_QUADS);

    // Cara frontal
    glColor3f(1.0, 0.0, 0.0); // Rojo
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);

    // Cara trasera
    glColor3f(0.0, 1.0, 0.0); // Verde
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    // Cara izquierda
    glColor3f(0.0, 0.0, 1.0); // Azul
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    // Cara derecha
    glColor3f(1.0, 1.0, 0.0); // Amarillo
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    // Cara superior
    glColor3f(1.0, 0.0, 1.0); // Magenta
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);

    // Cara inferior
    glColor3f(0.0, 1.0, 1.0); // Cian
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
   // glFlush();
    glEnd();
    
    // Finalizar el Display List
    glEndList();
    
}

void Example6::Idle()
{

}

