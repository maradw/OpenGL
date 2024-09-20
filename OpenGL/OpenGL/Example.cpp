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
	 
}

