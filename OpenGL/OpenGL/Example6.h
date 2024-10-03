#pragma once
#include "Example.h"
class Example6 : public Example
{
public: 
	Example6();
	int cubeList;
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void CreateCubeDisplayList();
};

