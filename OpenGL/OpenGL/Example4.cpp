#include "Example4.h"
#include "IncludeGL.h"
#include <iostream>
Example4::Example4()
{

}
void Example4::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Example4::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawAxis(50);
    // Configurar la luz y el material antes de dibujar

    ConfigurarLuzPuntual();
    ConfigurarLuzSpotLight();
    ConfigurarMaterial();
    // Dibujar una esfera
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(1.0f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // Posicionar la esfera en el origen
    DrawPlane();   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();

    glFlush();
}
void Example4::DrawPlane() {
    // Dibujar un plano en el eje XZ (Y = 0)
    glBegin(GL_QUADS);  // Usamos un cuadrado (QUADS) para dibujar el plano
    glNormal3f(0.0f, 1.0f, 0.0f);  // Normal apuntando hacia arriba en el eje Y
    glVertex3f(-2.0f, 0.0f, -2.0f);  // V�rtice 1
    glVertex3f(2.0f, 0.0f, -2.0f);  // V�rtice 2
    glVertex3f(2.0f, 0.0f, 2.0f);  // V�rtice 3
    glVertex3f(-2.0f, 0.0f, 2.0f);  // V�rtice 4
    glEnd();
}
void Example4::ConfigurarMaterial() {
    // Definir propiedades del material
    GLfloat mat_ambiente[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat mat_difuso[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    GLfloat mat_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat brillo[] = { 50.0f };  // Brillo (especular)
    // Configurar el material
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambiente);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_difuso);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_especular);
    glMaterialfv(GL_FRONT, GL_SHININESS, brillo);
}
void Example4::ConfigurarLuzPuntual()
{
    glPushMatrix();
    glTranslatef(2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
    glEnable(GL_LIGHTING);   // Habilitar iluminaci�n
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (punto de luz)
    // Definir propiedades de la luz puntual (point light)
    GLfloat luz_ambiente[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat luz_difusa[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat posicion_luz[] = { 2.0f, 2.0f, 0.0f, 1.0f };  // Posici�n de la luz (1.0f para luz puntual)
    // Configurar la luz 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicion_luz);
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}
void Example4::ConfigurarLuzDireccional() {
    glEnable(GL_LIGHTING);   // Habilitar iluminaci�n
    glEnable(GL_LIGHT0);     // Habilitar la luz 0 (luz direccional)
    // Definir propiedades de la luz direccional
    GLfloat luz_ambiente[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat luz_difusa[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    // Definir la direcci�n de la luz
    GLfloat direccion_luz[] = { 1.0f, -1.0f, -1.0f, 0.0f };  // (x, y, z, 0.0f para luz direccional)
    // Configurar la luz 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT0, GL_POSITION, direccion_luz);
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}
void Example4::ConfigurarLuzSpotLight() {
    glPushMatrix();
    glTranslatef(-2.0f, 2.0f, 0.0f);  // Posicionar la esfera en el origen
    glutSolidSphere(0.2f, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos
    glPopMatrix();
    glEnable(GL_LIGHTING);   // Habilitar iluminaci�n
    glEnable(GL_LIGHT1);     // Habilitar la luz 0 (spotlight)
    // Definir propiedades de la luz spotlight
    GLfloat luz_ambiente[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat luz_difusa[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat luz_especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat posicion_luz[] = { -2.0f, 2.0f, 0.0f, 1.0f };  // Posici�n del spotlight
    // Configurar la luz 0
    glLightfv(GL_LIGHT1, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
    glLightfv(GL_LIGHT1, GL_POSITION, posicion_luz);
    // Definir direcci�n y �ngulo del spotlight
    GLfloat direccion_luz[] = { 0.0f, -1.0f, 0.0f };  // Direcci�n hacia abajo
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direccion_luz);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f);    // �ngulo del foco (45 grados)
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0f);   // Atenuaci�n del spotlight
    // Habilitar el sombreado suave
    glShadeModel(GL_SMOOTH);
}
void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example4::Idle()
{
}