#pragma once
class TextureLoader
{
protected:
	GLuint texture;
	unsigned int width, height;
	unsigned char* data;
public:
	TextureLoader();
	virtual GLuint LoadParameter();
};

