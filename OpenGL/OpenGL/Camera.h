#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;    // Posici�n de la c�mara
    Vector3 forward;     // Direcci�n a la que apunta la c�mara
    Vector3 up;          // Vector "up" para la orientaci�n de la c�mara
    float speed;         // Velocidad de movimiento
    float sensitivity;   // Sensibilidad para rotaciones
public:
    Camera();
    void SetPosition(Vector3);
    Vector3 GetPosition();
    void Init();
    void Update();
    void LookAt(Vector3 target, float distance);
    void MoveForward();
    void MoveBackward();
    void StrafeLeft();
    void StrafeRight();
    void Rotate(float angleX, float angleY);
};