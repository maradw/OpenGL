#pragma once
#include "Figura3D.h"
#include "Cuadrado.h"
class Cubo :
    public Figura3D
{
public:
    Cuadrado quad;
    Cubo(const std::string& name, int w, float r, float g, float b);
    void CalculateVolume() override;  // Sobrescribe el cálculo de volumen
};

