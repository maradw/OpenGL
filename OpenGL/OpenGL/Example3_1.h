#pragma once
#include "Example.h"
#include "Camera.h"
#include "Pol�gono.h"

class Example3_1 : public Example
{
private:
    Camera* camera;
    Pol�gono* polygon;

public:
    Example3_1();
    void init() override;  // Implementaci�n de los m�todos puros de Example
    void Render() override;
    void KeyboardFunc(unsigned char key, int x, int y) override;
    void Idle() override;
};

