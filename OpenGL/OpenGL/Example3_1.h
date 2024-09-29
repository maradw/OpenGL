#pragma once
#include "Example.h"
#include "Camera.h"
#include "Polígono.h"

class Example3_1 : public Example
{
private:
    Camera* camera;
    Polígono* polygon;

public:
    Example3_1();
    void init() override;  // Implementación de los métodos puros de Example
    void Render() override;
    void KeyboardFunc(unsigned char key, int x, int y) override;
    void Idle() override;
};

