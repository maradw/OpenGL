#include "Example3.h"
#include <GL/glut.h>
#include <iostream>
#include "IncludeGL.h"

//#include <iostream>
//#include <cmath>
Example3::Example3()
{
    camera = new Camera();
}
void Example3::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0);
    camera->Init();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}
void Example3::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DrawAxis(80);

}
/*
// Posición inicial de la cámara
float cameraX = 0.0f, cameraY = 1.5f, cameraZ = 5.0f;
float centerX = 0.0f, centerY = 1.5f, centerZ = 0.0f; // Punto al que mira la cámara
float upX = 0.0f, upY = 1.0f, upZ = 0.0f;

// Variables para controlar la rotación de la cámara
float yaw = -90.0f;  // Horizontal (Eje Y)
float pitch = 0.0f;  // Vertical (Eje X)
float sensitivity = 0.05f;

// Velocidad de movimiento
float speed = 0.1f;

// Última posición del mouse
int lastX, lastY;
bool firstMouse = true;


void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

// Función para manejar la cámara con el teclado
void handleKeypress(unsigned char key, int x, int y) {
    // Dirección de la cámara
    float cameraSpeed = speed;

    float frontX = cosf(yaw *M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);
    float frontY = sinf(pitch * M_PI / 180.0f);
    float frontZ = sinf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);

    float directionX = frontX * cameraSpeed;
    float directionZ = frontZ * cameraSpeed;

    switch (key) {
    case 'w': // Adelante
        cameraX += directionX;
        cameraZ += directionZ;
        break;
    case 's': // Atrás
        cameraX -= directionX;
        cameraZ -= directionZ;
        break;
    case 'a': // Izquierda
        cameraX -= cosf((yaw - 90) * M_PI / 180.0f) * cameraSpeed;
        cameraZ -= sinf((yaw - 90) * M_PI / 180.0f) * cameraSpeed;
        break;
    case 'd': // Derecha
        cameraX += cosf((yaw - 90) * M_PI / 180.0f) * cameraSpeed;
        cameraZ += sinf((yaw - 90) * M_PI / 180.0f) * cameraSpeed;
        break;
    case 27: // Esc para salir
        exit(0);
    }
    glutPostRedisplay(); // Volver a dibujar la escena
}

// Función para manejar el movimiento del mouse
void handleMouseMovement(int x, int y) {
    if (firstMouse) {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    int xOffset = x - lastX;
    int yOffset = lastY - y;  // Invertir el movimiento vertical
    lastX = x;
    lastY = y;

    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // Limitar el ángulo de la cámara para no voltear completamente
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    // Actualizar el punto de vista de la cámara
    centerX = cameraX + cosf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);
    centerY = cameraY + sinf(pitch * M_PI / 180.0f);
    centerZ = cameraZ + sinf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);

    glutPostRedisplay(); // Volver a dibujar la escena
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Configurar la vista con gluLookAt
    gluLookAt(cameraX, cameraY, cameraZ,   // Posición de la cámara
        centerX, centerY, centerZ,   // Hacia donde mira
        upX, upY, upZ);              // Vector "arriba"

// Dibujar un plano
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, -5.0f);
    glVertex3f(5.0f, 0.0f, 5.0f);
    glVertex3f(-5.0f, 0.0f, 5.0f);
    glEnd();

    // Dibujar un cubo como referencia
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Control de Cámara con Teclado y Mouse");

    init();

    // Función de display
    glutDisplayFunc(display);

    // Función de teclado
    glutKeyboardFunc(handleKeypress);

    // Función para controlar el mouse
    glutPassiveMotionFunc(handleMouseMovement);

    glutMainLoop();
    return 0;
}
*/

