#pragma once
#include "Example.h"
class Example5 : public Example
{
public:
	Example5();

	virtual void init()override;

	virtual void Render()override;
	void DrawTriangle();
	void DrawQuad();
	void DrawCube();
	void DrawSphere();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;

	void Draw(unsigned char key);

	//void Figures(unsigned char key);
	virtual void Idle()override;
};

