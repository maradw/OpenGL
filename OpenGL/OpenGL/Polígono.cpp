#include "Polígono.h"
#include "IncludeGL.h"
#include <iostream>
Polígono::Polígono()
{
   
}
void Polígono::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
   
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Polígono::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
    glutSwapBuffers();
    //glFlush();

}

void Polígono::KeyboardFunc(unsigned char key, int x, int y)
{
    //
}
void Polígono::DrawCube(int x,int y, int z)
{
	glLineWidth(8.0);
	glTranslatef(x, y, z);
	//glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

	// Cara frontal (Z positiva)
	glColor3f(1.0, 0.0, 0.0);  // Rojo
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	// Cara trasera (Z negativa)
	glColor3f(0.0, 1.0, 0.0);  // Verde
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);

	// Cara izquierda (X negativa)
	glColor3f(0.0, 0.0, 1.0);  // Azul
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	// Cara derecha (X positiva)
	glColor3f(1.0, 1.0, 0.0);  // Amarillo
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	// Cara superior (Y positiva)
	glColor3f(1.0, 0.0, 1.0);  // Magenta
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);

	// Cara inferior (Y negativa)
	glColor3f(0.0, 1.0, 1.0);  // Cian
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glFlush();
}
void Polígono::DrawSphere(int x, int y, int z)
{
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.5f, 1.5f, 1.5f);
	glTranslatef(x, y, z);
	glColor3f(0.0, 0.5, 1.0); // Color azul claro

	gluSphere(quadric, 1.0, 32, 32); // Radio, slices, stacks
	gluDeleteQuadric(quadric);
	glFlush();
}
void Polígono::Idle()
{

}
void Polígono::DrawCone(int x, int y, int z)
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.5f, 1.5f, 1.5f);
	glTranslatef(x, y, z);
	// Configuración del cono
	glColor3f(1.0, 0.0, 0.0); // Color rojo brillante

							  // Dibujar el cono
	gluCylinder(quadric, 1.0, 0.0, 2.0, 32, 32); // Radio superior, radio inferior (0 para cono), altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}