#include "Cube.h"
#include "IncludeGL.h"
#include <iostream>

Vector3 position;
Pol�gono::Pol�gono()
{

}
void Pol�gono::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);

    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Pol�gono::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSwapBuffers();
    //glFlush();

}
void Pol�gono::DrawCube1() {
    glPushMatrix(); // Guardar la matriz de transformaci�n actual
    glTranslatef(position.x, position.y, position.z); // Aplicar la transformaci�n a la posici�n del cubo

    glBegin(GL_QUADS);
    // Aqu� ir�a el c�digo para dibujar el cubo (como lo ten�as antes)
    glEnd();

    glPopMatrix(); // Restaurar la matriz de transformaci�n
}

void Pol�gono::KeyboardFunc(unsigned char key, int x, int y)
{

}
void Pol�gono::MoveForward() {
    position.z += 0.1f; // Mover hacia adelante en el eje Z
}

void Pol�gono::MoveBackward() {
    position.z -= 0.1f; // Mover hacia atr�s en el eje Z
}

void Pol�gono::StrafeLeft() {
    position.x -= 0.1f; // Mover a la izquierda en el eje X
}

void Pol�gono::StrafeRight() {
    position.x += 0.1f; // Mover a la derecha en el eje X
}