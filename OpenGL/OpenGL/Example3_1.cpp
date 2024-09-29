#include "Example3_1.h"
#include "IncludeGL.h"
#include <GL/glut.h>

// Constructor
Example3_1::Example3_1()
{
    camera = new Camera();
    polygon = new Pol�gono();
}

// Inicializaci�n de la escena
void Example3_1::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Color de fondo
    glClearDepth(1.0);                     // Profundidad del buffer

    glEnable(GL_DEPTH_TEST);               // Habilitar test de profundidad

    // Inicializar la c�mara
    camera->Init();
    camera->SetPosition(Vector3(5, 2, 5));  // Posici�n inicial de la c�mara
    camera->SetDirection(Vector3(0, 0, -1)); // Direcci�n inicial (mirando hacia el eje Z negativo)

    glMatrixMode(GL_MODELVIEW);
    glFlush();
}


// M�todo para renderizar la escena
void Example3_1::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiar el buffer de color y profundidad

    // Actualizar la c�mara antes de renderizar las geometr�as
    camera->Update();

    // Dibujar los ejes y la cuadr�cula (funciones heredadas de Example)
    DrawAxis(30, 2);
    DrawGrids(1);

    // Dibujar algunos objetos
    polygon->DrawCube(5, 0, -5);   // Dibuja un cubo en la posici�n (5, 0, -5)
    polygon->DrawSphere(-5, 0, 5); // Dibuja una esfera en la posici�n (-5, 0, 5)
    polygon->DrawCone(3, 0, -7);   // Dibuja un cono en la posici�n (3, 0, -7)

    // Dibujar un tri�ngulo como ejemplo adicional
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

// Funci�n para manejar la entrada del teclado
void Example3_1::KeyboardFunc(unsigned char key, int x, int y)
{
    // Llama al m�todo de la c�mara que maneja los controles de teclado
    camera->KeyboardFunc(key, x, y);

    // Redistribuir la escena despu�s de mover la c�mara
    glutPostRedisplay();
}

// Funci�n de "Idle" para actualizar la escena si es necesario
void Example3_1::Idle()
{
    // Aqu� puedes actualizar cualquier cosa adicional si es necesario (animaciones, etc.)
    glutPostRedisplay();
}
