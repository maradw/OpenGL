#include "Camera.h"
#include "IncludeGL.h"
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

    gluLookAt(position.x,
        position.y,
        position.z,
        direction.x,
        direction.y,
        direction.z,
        0, 1, 0);

}
void Camera::LookAt(Vector3)
{
}
void Camera::KeyboardFunc(unsigned char key, int X, int Y)
{
    direction.print();
}