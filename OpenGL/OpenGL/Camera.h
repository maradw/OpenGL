#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;  // Posición de la cámara
    Vector3 direction; // Dirección en la que mira
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

    // Métodos para mover y rotar la cámara
    //void MoveForward();
    //void MoveBackward();
    //void StrafeLeft();
    //void StrafeRight();
    //void Rotate(float angle);
};
