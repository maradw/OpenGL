#pragma once
class Polígono
{
public:
	Polígono();
	virtual void init() = 0;
	virtual void Render() = 0;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) = 0;
	virtual void Idle() = 0;

	void DrawCube(int x, int y, int z);
	void DrawSphere(int x, int y, int z);
	void DrawCone(int x, int y, int z);
};

