#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;  // Posici�n de la c�mara
    Vector3 direction; // Direcci�n en la que mira
    float speed;       // Velocidad de movimiento

public:
    Camera();
    void SetPosition(Vector3 _position);
    Vector3 GetPosition();
    void SetDirection(Vector3 _direction);
    Vector3 GetDirection();
    void Init();
    void Update();
    void LookAt(Vector3 target);
    void KeyboardFunc(unsigned char key, int X, int Y);

    // M�todos para mover y rotar la c�mara
    //void MoveForward();
    //void MoveBackward();
    //void StrafeLeft();
    //void StrafeRight();
    //void Rotate(float angle);
};
