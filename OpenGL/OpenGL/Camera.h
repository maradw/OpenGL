#pragma once
#include "Vector3.h"
class Camera
{
private:
	Vector3 position;
	Vector3 direction;
public:
	Camera();
	void SetPosition(Vector3);
	Vector3 GetPosition();
	void SetDirection(Vector3);
	Vector3 GetDirection();
	void Init();
	void Update();
	void LookAt(Vector3);
	void KeyboardFunc(unsigned char key, int X, int Y);
};

