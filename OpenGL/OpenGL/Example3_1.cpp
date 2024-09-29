#include "Example3_1.h"
#include "IncludeGL.h"
#include <GL/glut.h>

// Constructor
Example3_1::Example3_1()
{
    camera = new Camera();
    polygon = new Polígono();
}

// Inicialización de la escena
void Example3_1::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Color de fondo
    glClearDepth(1.0);                     // Profundidad del buffer

    glEnable(GL_DEPTH_TEST);               // Habilitar test de profundidad

    // Inicializar la cámara
    camera->Init();
    camera->SetPosition(Vector3(5, 2, 5));  // Posición inicial de la cámara
    camera->SetDirection(Vector3(0, 0, -1)); // Dirección inicial (mirando hacia el eje Z negativo)

    glMatrixMode(GL_MODELVIEW);
    glFlush();
}


// Método para renderizar la escena
void Example3_1::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiar el buffer de color y profundidad

    // Actualizar la cámara antes de renderizar las geometrías
    camera->Update();

    // Dibujar los ejes y la cuadrícula (funciones heredadas de Example)
    DrawAxis(30, 2);
    DrawGrids(1);

    // Dibujar algunos objetos
    polygon->DrawCube(5, 0, -5);   // Dibuja un cubo en la posición (5, 0, -5)
    polygon->DrawSphere(-5, 0, 5); // Dibuja una esfera en la posición (-5, 0, 5)
    polygon->DrawCone(3, 0, -7);   // Dibuja un cono en la posición (3, 0, -7)

    // Dibujar un triángulo como ejemplo adicional
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // Color rojo
    glVertex3f(0.0, 1.0, -5.0);  // Punto superior
    glColor3f(0.0, 1.0, 0.0);  // Color verde
    glVertex3f(-1.0, -1.0, -5.0);  // Punto inferior izquierdo
    glColor3f(0.0, 0.0, 1.0);  // Color azul
    glVertex3f(1.0, -1.0, -5.0);  // Punto inferior derecho
    glEnd();

    glFlush();

    // Intercambiar buffers (doble buffer)
    glutSwapBuffers();
}

// Función para manejar la entrada del teclado
void Example3_1::KeyboardFunc(unsigned char key, int x, int y)
{
    // Llama al método de la cámara que maneja los controles de teclado
    camera->KeyboardFunc(key, x, y);

    // Redistribuir la escena después de mover la cámara
    glutPostRedisplay();
}

// Función de "Idle" para actualizar la escena si es necesario
void Example3_1::Idle()
{
    // Aquí puedes actualizar cualquier cosa adicional si es necesario (animaciones, etc.)
    glutPostRedisplay();
}
