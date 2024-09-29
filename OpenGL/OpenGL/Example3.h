#pragma once
#include "Example.h"
#include "Camera.h"
#include "Polígono.h"
class Example3 : public Example
{
private:
	Camera* camera; // Puntero a la instancia de la Cámara
	Polígono* polygon;
public:
	Example3(Camera* _camera) : camera(_camera) {}
	Example3(Polígono* _polygon) : polygon(_polygon) {}
	//Camera* camera;
	//Polígono* polygon;
public:
	Example3();

	virtual void init()override;

	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	
	virtual void Idle()override;

	
};


