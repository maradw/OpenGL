#pragma once
#include "Pol�gono.h"
class Cube :  public Pol�gono
{
private:
	Vector3 position;
public:
	virtual void init() = 0;
	virtual void Render() = 0;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) = 0;
	virtual void Idle() = 0;

	//

	void MoveForward();   // M�todo para mover el cubo hacia adelante
    void MoveBackward();  // M�todo para mover el cubo hacia atr�s
    void StrafeLeft();    // M�todo para mover el cubo a la izquierda
    void StrafeRight();   // M�todo para mover el cubo a la derecha
	void DrawCube1();
};

