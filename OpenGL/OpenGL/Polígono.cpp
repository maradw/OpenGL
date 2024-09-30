#include "Pol�gono.h"
#include "IncludeGL.h"
#include <iostream>
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

void Pol�gono::KeyboardFunc(unsigned char key, int x, int y)
{
   
}
void Pol�gono::DrawCube(int a,int b, int c)
{
	glLineWidth(8.0);
	glTranslatef(a, b, c);
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
void Pol�gono::DrawSphere(int x, int y, int z)
{
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.0f, 1.0f, 1.0f);
	glTranslatef(x, y, z);
	glColor3f(0.0, 0.5, 1.0); // Color azul claro

	gluSphere(quadric, 1.0, 32, 32); // Radio, slices, stacks
	gluDeleteQuadric(quadric);
	glFlush();
}
void Pol�gono::Idle()
{

}
void Pol�gono::DrawCone(int x, int y, int z)
{
	// Crear un objeto de cilindro con GLU
	GLUquadricObj* quadric = gluNewQuadric();
	glScalef(1.5f, 1.5f, 1.5f);
	glTranslatef(x, y, z);
	// Configuraci�n del cono
	glColor3f(0.0f, 1.0f, 1.0f);



							  // Dibujar el cono
	gluCylinder(quadric, 1.0, 0.0, 2.0, 32, 32); // Radio superior, radio inferior (0 para cono), altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}
void Pol�gono::DrawOrthohedron(int x, int y, int z)
{
	glColor3f(0.5, 0.2, 0.8); // Morado
	glTranslatef(x, y, z);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(1.5, 1.0, -0.5);
	glVertex3f(1.5, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glEnd();

	// Base inferior (rect�ngulo)
	glColor3f(0.2, 0.8, 0.5); // Verde claro
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5);
	glVertex3f(1.5, -1.0, -0.5);
	glVertex3f(1.5, -1.0, 0.5);
	glVertex3f(-1.0, -1.0, 0.5);
	glEnd();

	// Cara frontal
	glColor3f(1.0, 0.5, 0.0); // Naranja
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, -0.5); // V�rtice superior izquierdo
	glVertex3f(1.5, 1.0, -0.5); // V�rtice superior derecho
	glVertex3f(1.5, -1.0, -0.5); // V�rtice inferior derecho
	glVertex3f(-1.0, -1.0, -0.5); // V�rtice inferior izquierdo
	glEnd();

	// Cara derecha
	glColor3f(0.0, 0.7, 1.0); // Azul celeste
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 1.0, -0.5); // V�rtice superior izquierdo
	glVertex3f(1.5, 1.0, 0.5); // V�rtice superior derecho
	glVertex3f(1.5, -1.0, 0.5); // V�rtice inferior derecho
	glVertex3f(1.5, -1.0, -0.5); // V�rtice inferior izquierdo
	glEnd();

	// Cara trasera
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 1.0, 0.5); // V�rtice superior derecho
	glVertex3f(-1.0, 1.0, 0.5); // V�rtice superior izquierdo
	glVertex3f(-1.0, -1.0, 0.5); // V�rtice inferior izquierdo
	glVertex3f(1.5, -1.0, 0.5); // V�rtice inferior derecho
	glEnd();

	// Cara izquierda
	glColor3f(0.5, 1.0, 0.5); // Verde pastel
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0, 0.5); // V�rtice superior derecho
	glVertex3f(-1.0, 1.0, -0.5); // V�rtice superior izquierdo
	glVertex3f(-1.0, -1.0, -0.5); // V�rtice inferior izquierdo
	glVertex3f(-1.0, -1.0, 0.5); // V�rtice inferior derecho
	glEnd();

	// Cara inferior
	glColor3f(0.8, 0.8, 0.0); // Amarillo pastel
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, -1.0, -0.5); // V�rtice inferior izquierdo
	glVertex3f(1.5, -1.0, -0.5); // V�rtice inferior derecho
	glVertex3f(1.5, -1.0, 0.5); // V�rtice superior derecho
	glVertex3f(-1.0, -1.0, 0.5); // V�rtice superior izquierdo
	glEnd();
	glFlush();
}
void Pol�gono::DrawPiramid(int x, int y, int z)
{
	glTranslatef(x, y, z);
	glLineWidth(8.0);

	// Aplicar la escala para reducir el tama�o de la pir�mide
	glScalef(0.5f, 0.5f, 0.5f); // Reduce la pir�mide al 50% de su tama�o original

	glBegin(GL_TRIANGLES); // Usar tri�ngulos para las caras de la pir�mide

	// Cara frontal
	glColor3f(1.0, 0.0, 0.0); // Rojo
	glVertex3f(0.0, 1.0, 0.0); // V�rtice superior
	glVertex3f(-1.0, -1.0, 1.0); // V�rtice inferior izquierdo
	glVertex3f(1.0, -1.0, 1.0); // V�rtice inferior derecho

	// Cara derecha
	glColor3f(0.0, 1.0, 0.0); // Verde
	glVertex3f(0.0, 1.0, 0.0); // V�rtice superior
	glVertex3f(1.0, -1.0, 1.0); // V�rtice inferior derecho
	glVertex3f(1.0, -1.0, -1.0); // V�rtice inferior trasero derecho

	// Cara trasera
	glColor3f(0.0, 0.0, 1.0); // Azul
	glVertex3f(0.0, 1.0, 0.0); // V�rtice superior
	glVertex3f(1.0, -1.0, -1.0); // V�rtice inferior derecho
	glVertex3f(-1.0, -1.0, -1.0); // V�rtice inferior izquierdo

	// Cara izquierda
	glColor3f(1.0, 1.0, 0.0); // Amarillo
	glVertex3f(0.0, 1.0, 0.0); // V�rtice superior
	glVertex3f(-1.0, -1.0, -1.0); // V�rtice inferior izquierdo
	glVertex3f(-1.0, -1.0, 1.0); // V�rtice inferior izquierdo

	// Base de la pir�mide
	glColor3f(0.5, 0.5, 0.5); // Gris
	glVertex3f(-1.0, -1.0, 1.0); // V�rtice inferior izquierdo (frontal izquierdo)
	glVertex3f(1.0, -1.0, 1.0); // V�rtice inferior derecho (frontal derecho)
	glVertex3f(1.0, -1.0, -1.0); // V�rtice inferior derecho (trasero derecho)
	glVertex3f(-1.0, -1.0, -1.0); // V�rtice inferior izquierdo (trasero izquierdo)

	glEnd();
	glFlush();
}
void Pol�gono::DrawFrustum(int x, int y, int z)
{
	// Crear un objeto de cilindro con GLU
	glTranslatef(x, y, z);
	GLUquadricObj* quadric = gluNewQuadric();

	// Configuraci�n del tronco de cono
	glColor3f(0.0, 0.8, 0.8); // Color marr�n claro

							  // Dibujar el tronco de cono
	gluCylinder(quadric, 1.0, 0.5, 2.0, 32, 32); // Radio superior, radio inferior, altura, slices, stacks

												 // Limpiar el objeto quadric
	gluDeleteQuadric(quadric);
	glFlush();
}
void Pol�gono::DrawIcosahedron(int x, int y, int z)
{
	glTranslatef(x, y, z);
	glLineWidth(8.0);
	glScalef(1.0f, 1.0f, 1.0f);
	glColor3f(0.7, 0.4, 0.2);
	glutSolidIcosahedron();
	glutSwapBuffers();
}
