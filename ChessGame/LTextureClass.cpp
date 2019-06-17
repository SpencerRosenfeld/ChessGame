#include "LTextureClass.h"

LTextureClass::LTextureClass()
{
	texture = NULL;
	width = 0;
	height = 0;
	renderer = NULL;
	window = NULL;
	surface = NULL;
}


LTextureClass::~LTextureClass()
{
	free();
}

bool LTextureClass::loadFromFile(std::string path) {
	//Remove pre-existing texture
	free();

	SDL_Texture * newTexture = NULL;

	SDL_Surface * loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL) {
		IMG_GetError();
	}

	else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL) {
			SDL_GetError();
		}
		else {
			//Get image dimensions
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		//Remove old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	texture = newTexture;
	return texture != NULL;
}

void LTextureClass::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void LTextureClass::render(int x, int y) {
	SDL_Rect renderQuad = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

int LTextureClass::getWidth() {
	return width;
}

int LTextureClass::getHeight() {
	return height;
}

void LTextureClass::setWidth(int w) {
	width = w;
}

void LTextureClass::setHeight(int h) {
	height = h;
}

void LTextureClass::SetRenderer(SDL_Renderer * r)
{
	renderer = r;
}