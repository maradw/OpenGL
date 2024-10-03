#pragma once
#include <string>
class Figura
{
protected:
	std::string nameF;
	int width;
	float color[3];//float
public:
	Figura(const std::string& name, int w, float r, float g, float b);
	void init();
	void Draw();
};
