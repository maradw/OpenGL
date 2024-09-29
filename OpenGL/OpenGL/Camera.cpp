#include "Camera.h"
#include "IncludeGL.h"


Vector3 position; // Posici�n de la c�mara
Vector3 direction; // Direcci�n en la que mira
float speed;
Camera::Camera()
{
}
void Camera::SetPosition(Vector3 _position)
{
    position = _position;
}
Vector3 Camera::GetPosition()
{
    return position;
}
void Camera::SetDirection(Vector3 _direction)
{
    direction = _direction;
}
Vector3 Camera::GetDirection()
{
    return Vector3();
}
void Camera::Init()
{
   
}
void Camera::Update()
{
   //glLoadIdentity();
   // glClearDepth(1.0);

    gluLookAt(position.x,
        position.y,
        position.z,
        0,
        0,
        0,
        0, 1, 0);
    //glMatrixMode(GL_MODELVIEW);

}
/*void MoveForward() {
    position.x += direction.x * speed;
    position.z += direction.z * speed;
}

void MoveBackward() {
    position.x -= direction.x * speed;
    position.z -= direction.z * speed;
}

void StrafeLeft() {
    position.x -= direction.z * speed; // Mover a la izquierda
    position.z += direction.x * speed; // Ajustar la direcci�n
}

void StrafeRight() {
    position.x += direction.z * speed; // Mover a la derecha
    position.z -= direction.x * speed; // Ajustar la direcci�n
}

void Rotate(float angle) {
    // Rotaci�n en el plano XZ
    direction.x = cos(angle);
    direction.z = sin(angle);
}
*/
void Camera::LookAt(Vector3)
{
}

void Camera::KeyboardFunc(unsigned char key, int X, int Y)
{
   // direction.print();
}




/*
#include "Camera.h"
#include "IncludeGL.h"

// Constructor
Camera::Camera() : position(0, 0, 0), direction(0, 0, -1), speed(0.1f) {}

// Establecer posici�n de la c�mara
void Camera::SetPosition(Vector3 _position)
{
    position = _position;
}

// Obtener posici�n de la c�mara
Vector3 Camera::GetPosition()
{
    return position;
}

// Establecer direcci�n de la c�mara
void Camera::SetDirection(Vector3 _direction)
{
    direction = _direction.normalize();  // Aseg�rate de normalizar la direcci�n
}

// Obtener direcci�n de la c�mara
Vector3 Camera::GetDirection()
{
    return direction;
}

// Inicializar (podr�as agregar m�s cosas aqu� si lo necesitas)
void Camera::Init()
{
    // Cualquier configuraci�n inicial que necesites
}

// Actualizar la c�mara
void Camera::Update()
{
    // Calculamos el punto al que mira la c�mara basado en su direcci�n
    Vector3 lookAtPoint = position + direction; // Miras hacia donde est� orientada la c�mara

    // Restablecemos la matriz de modelo-vista
    glLoadIdentity();

    // Configuramos la vista de la c�mara con gluLookAt
    gluLookAt(position.x, position.y, position.z,
        lookAtPoint.x, lookAtPoint.y, lookAtPoint.z,  // Ahora mira hacia "lookAtPoint"
        0, 1, 0);  // Up vector
}


// Control de la c�mara con teclado
void Camera::KeyboardFunc(unsigned char key, int x, int y)
{
   switch (key)
    {
    case 'w': // Mover hacia adelante
        MoveForward();
        break;
    case 's': // Mover hacia atr�s
        MoveBackward();
        break;
    case 'a': // Mover a la izquierda (strafe)
        StrafeLeft();
        break;
    case 'd': // Mover a la derecha (strafe)
        StrafeRight();
        break;
    case 'q': // Rotar a la izquierda
        Rotate(-0.1f);
        break;
    case 'e': // Rotar a la derecha
        Rotate(0.1f);
        break;
    }
    
}

void Camera::MoveForward()
{
    position = position + (direction * speed);  // Avanzar en la direcci�n actual
}

void Camera::MoveBackward()
{
    position = position - (direction * speed);  // Retroceder en la direcci�n actual
}

void Camera::StrafeLeft()
{
    Vector3 left = direction.cross(Vector3(0, 1, 0)).normalize();  // Vector hacia la izquierda
    position = position - (left * speed);
}

void Camera::StrafeRight()
{
    Vector3 right = direction.cross(Vector3(0, 1, 0)).normalize(); // Vector hacia la derecha
    position = position + (right * speed);
}

void Camera::Rotate(float angle)
{
    // Rotar la c�mara alrededor del eje Y (plano XZ)
    float cosAngle = cos(angle);
    float sinAngle = sin(angle);

    Vector3 newDirection;
    newDirection.x = direction.x * cosAngle - direction.z * sinAngle;
    newDirection.z = direction.x * sinAngle + direction.z * cosAngle;
    newDirection.y = direction.y;  // Mantener el componente Y (evitar que cambie el pitch)

    direction = newDirection.normalize(); // Normalizar la direcci�n
}
*/
