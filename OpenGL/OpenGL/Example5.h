/*#pragma once
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
};*/
#pragma once
#include "Example.h"
#include "Figura.h"
#include "Vector3.h"
#include "TextureLoader.h"
class Example5 :
	public Example
{
	Figura* shape;
	Vector3 pos;
	TextureLoader* _TextureLoader;
	GLuint texture;
public:
	Example5();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawShape();
};

