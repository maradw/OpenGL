#pragma once
#include <string>
class Figura
{
protected:
	std::string nameF;
	int width; //no relevante, agregar datos compartidos
	float color[3];//float
	int IDtexture;
public:
	Figura(const std::string& name, int w, float r, float g, float b);
	void init();
	virtual void Draw() = 0;
};
