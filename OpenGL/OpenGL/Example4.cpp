#include "Example4.h"
#include "IncludeGL.h"
#include <iostream>
Example4::Example4()
{
}

void Example4::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	Lights();


	glEnable(GL_LIGHTING);
	
}

void Example4::Lights()
{
	glEnable(GL_LIGHT0);
	GLfloat lightPosition[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	//GLfloat ambientLight[] = { 0.0f, 0.8f, 0.2f, 1.0f }; // RGBA
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

}

void Example4::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawAxis(50);
	DrawSphere();
	
	//DrawCube();
	

}
void Example4::DrawCube()
{
	glLineWidth(8.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glTranslatef(0, 0, 0);
	glBegin(GL_QUADS);  // Usamos quads para dibujar el cubo

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
void Example4::DrawSphere()
{
	// Crear un objeto de esfera con GLU
	GLUquadricObj* quadric = gluNewQuadric();


	glTranslatef(4.0f, 3.0f, 1.0f);
	glColor3f(0.0, 0.9, 1.0); // Color azul claro

							  // Dibuja la esfera
	gluSphere(quadric, 0.5, 32, 32); // Radio, slices, stacks

	gluDeleteQuadric(quadric);
	glFlush();
}
void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{
	
}

void Example4::Figures(unsigned char key)
{
	switch (key)
	{
	case '1':
		
		break;
	default:
		std::cout << "Tecla no reconocida: " << key << std::endl;
		break;
	}
}


void Example4::Idle()
{

}
