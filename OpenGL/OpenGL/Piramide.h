#pragma once
#include "Figura3D.h"
#include "Triangulo.h"
class Piramide :
    public Figura3D
{
public: 
    int heignt;
    //Triangulo tri;
    Piramide(const std::string& name, int w, float r, float g, float b);
    void CalculateVolume() override;  // Sobrescribe el c�lculo de volumen
    void Draw() override;
};

