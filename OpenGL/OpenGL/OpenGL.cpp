// OpenGL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <Windows.h>
#include "IncludeGL.h"
#include "Example.h"
#include "Example5.h"
 
 
#include <iostream>
using namespace std;
Example* _Example;
void Render()
{
	((Example5*)_Example)->Render();
}
void KeyboardFunc(unsigned char key, int X, int Y )
{
	((Example5*)_Example)->KeyboardFunc(key,  X,  Y);
	glutPostRedisplay(); 
}
void reSize(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset
	// Enable perspective projection with fovy, aspect, zNear and zFar
	gluPerspective(45.0f, aspect, 0.1f, 10000.0f);
}

void Idle()
{
	((Example5*)_Example)->Idle();
}


void init(void)
{
	_Example = new Example5();
	((Example5*)_Example)->init();
}
int main(int argc, char** argv)
{
	GLuint width = 550;
	GLuint heigth = 550;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, heigth);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hello");
	
	init();
	
	glutDisplayFunc(Render);
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyboardFunc);
	glutReshapeFunc(reSize);
	glutMainLoop();
	
	return 0;
}
