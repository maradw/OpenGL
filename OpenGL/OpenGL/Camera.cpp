#include "Camera.h"
#include "IncludeGL.h"

/*Vector3 position; // Posición de la cámara
Vector3 direction; // Dirección en la que mira
float speed;*/
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
   // glLoadIdentity();
   // glClearDepth(1.0);
    /*gluLookAt(position.x,
        position.y,
        position.z,
        direction.x,
        direction.y,
        direction.z,
        0, 1, 0);*/

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
    position.z += direction.x * speed; // Ajustar la dirección
}

void StrafeRight() {
    position.x += direction.z * speed; // Mover a la derecha
    position.z -= direction.x * speed; // Ajustar la dirección
}

void Rotate(float angle) {
    // Rotación en el plano XZ
    direction.x = cos(angle);
    direction.z = sin(angle);
}*/
void Camera::LookAt(Vector3)
{
}

void Camera::KeyboardFunc(unsigned char key, int X, int Y)
{
   // direction.print();
}