#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
public:
    int base;
    int height;
    void ChangeSize(int size);
};

