#pragma once
class Pol�gono
{
public:
	Pol�gono();
	void init() ;
	void Render();
	 void KeyboardFunc(unsigned char key, int X, int Y);
	void Idle();

	void DrawCube(int x, int y, int z);
	void DrawSphere(int x, int y, int z);
	void DrawCone(int x, int y, int z);
};

