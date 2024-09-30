#pragma once
class Polígono
{
public:
	Polígono();
	virtual void init() = 0;
	virtual void Render() = 0;
	virtual void KeyboardFunc(unsigned char key, int X, int Y) = 0;
	virtual void Idle() = 0;

	void DrawCube(int a, int b, int c);
	void DrawSphere(int x, int y, int z);
	void DrawCone(int x, int y, int z);
	void DrawOrthohedron(int x, int y, int z);
	void DrawPiramid(int x, int y, int z);
	void DrawFrustum(int x, int y, int z);
	void DrawIcosahedron(int x, int y, int z);
};

