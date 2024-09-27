#include "Example.h"
#include <GL/glut.h>
#include <stdio.h>

Example::Example()
{
}

void Example::DrawAxis(GLfloat distance)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLineWidth(8.0);
	glBegin(GL_LINES);
	//GLfloat distance = 50;
	//Eje X
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-distance, 0.0f, 0.0f);
	glVertex3f(distance, 0.0f, 0.0f);

	//Eje Y
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -distance, 0.0f);
	glVertex3f(0.0f, distance, 0.0f);

	//Eje Z
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -distance);
	glVertex3f(0.0f, 0.0f, distance);

	glEnd();

	glutSwapBuffers();
}

void Example::DrawGrids()
{
	//std::cout << "DrawGrid" << std::endl;
	glLineWidth(3.0);
	glColor3f(5.0f, 2.0f, 4.0f);
	glBegin(GL_LINES);

	//Dibujar líneas en el plano XZ
	for (float z = -10.0f; z <= 10.0f; z += 1.0f) {
		glVertex3f(-10.0f, 0.0f, z);
		glVertex3f(10.0f, 0.0f, z);
	}
	// Dibujar líneas en el plano XZ (paralelas al eje Z)
	for (float x = -10.0f; x <= 10.0f; x += 1.0f) {
		glVertex3f(x, 0.0f, -10.0f);
		glVertex3f(x, 0.0f, 10.0f);
	}

	glEnd();

	glutSwapBuffers();

}

