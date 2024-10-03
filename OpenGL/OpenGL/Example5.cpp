#include "Example5.h"
//#include "Color.h"
#include "Cubo.h"
#include <stdio.h>
#include "BMPTextureLoader.h"
Example5::Example5()
{
}
void Example5::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	shape = new Cubo(2);
	_TextureLoader = new BMPTextureLoader();
	texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./textures/wallBMP.bmp");
}
void Example5::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Example::DrawGrids();
	DrawShape();
	glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	switch (key)
	{
	case 'A':
		pos.x += 0.5;
		break;
	case 'D':
		pos.x -= 0.5;
		break;
	case 'W':
		pos.z += 0.5;
		break;
	case 'S':
		pos.z -= 0.5;
		break;
	case 'Q':
		pos.y += 0.5;
		break;
	case 'E':
		pos.y -= 0.5;
		break;
	default:
		break;
	}
}
void Example5::Idle()
{
}
void Example5::DrawShape()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, texture);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	((Cubo*)shape)->Draw();
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers(); //Se hace el cambio de buffer
/*#include "Example5.h"
#include "IncludeGL.h"
#include <iostream>
Example5::Example5()
{

}
void Example5::init()
{ 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //DrawQuad();
  //DrawTriangle();
	//DrawCube();
	//DrawSphere();
   glFlush();
}

void Example5::DrawTriangle()
{
	//glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f); 

    glBegin(GL_TRIANGLES);       
    glVertex2f(-0.5f, -0.5f); 
    glVertex2f(0.5f, -0.5f);   
    glVertex2f(0.0f, 0.5f);    
    glEnd();
	glFlush();
}

void Example5::DrawQuad()
{
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);  

    glBegin(GL_QUADS);       
    glVertex2f(-0.5, -0.5);  
    glVertex2f(0.5, -0.5);   
    glVertex2f(0.5, 0.5);    
    glVertex2f(-0.5, 0.5);   
    glEnd();   
	glFlush();
}
void Example5::DrawCube()
{
	glLineWidth(8.0);
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
void Example5::DrawSphere()
{
    GLUquadricObj* quadric = gluNewQuadric();
    glColor3f(0.0, 0.5, 1.0); // Color azul claro

    gluSphere(quadric, 1.0, 32, 32); // Radio, slices, stacks
    gluDeleteQuadric(quadric);
    glFlush();
}

void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{
	//Draw(key);
}
void Example5::Draw(unsigned char key)
{
	std::cout << "xd " << std::endl;
	switch (key)
	{
	case '1':
		std::cout << "xd1 " << std::endl;
		DrawTriangle();
		break;
	case '2':
		std::cout << "xd2 " << std::endl;
		DrawQuad();
		break;
	case '3':
		std::cout << "xd3 " << std::endl;
		DrawCube();
		break;
	case '4':
		std::cout << "xd4 " << std::endl;
		DrawSphere();
		break;
	default:
		std::cout << "Tecla no reconocida: " << key << std::endl;
		break;
	}
}
void Example5::Idle() 
{

}
*/