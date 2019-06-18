#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class LTextureClass
{
public:
	//Initialize variables
	LTextureClass();

	//Deallocates memory
	~LTextureClass();

	//Load image at a specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Render texture at a given point
	void render(int x, int y);

	void SetRenderer(SDL_Renderer * r);

	//Get image dimensions
	int getWidth();
	int getHeight();
	void setWidth(int);
	void setHeight(int);

private:
	SDL_Texture * texture;
	SDL_Renderer * renderer;
	int width;
	int height;
};

