#pragma once
#include "Example.h"
#include "Camera.h"
#include "Pol�gono.h"
class Example3 : public Example
{
private:
	Camera* camera; // Puntero a la instancia de la C�mara
	Pol�gono* polygon;
public:
	Example3(Camera* _camera) : camera(_camera) {}
	Example3(Pol�gono* _polygon) : polygon(_polygon) {}
	//Camera* camera;
	//Pol�gono* polygon;
public:
	Example3();

	virtual void init()override;

	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	
	virtual void Idle()override;

	
};


