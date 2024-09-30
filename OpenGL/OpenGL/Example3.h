#pragma once
#include "Example.h"
#include "Camera.h"
#include "Pol�gono.h"

class Example3 : public Example
{
    Camera* camera;
    Pol�gono* polygon;
public:
    Example3();
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void SpecialFunc(int key, int X, int Y); // Teclas especiales (flechas)
    virtual void Idle() override;
};

