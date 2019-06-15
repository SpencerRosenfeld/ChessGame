#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600; 

class LTexture {
public:
	//Initialize variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Load image at a specified path
	bool loadFromFile(std::string path);

	//Deallocates texture
	void free();

	//Render texture at a given point
	void render(int x, int y);

	//Get image dimensions
	int getWidth();
	int getHeight();
	void setWidth(int);
	void setHeight(int);

private:
	SDL_Texture * texture;

	int width;
	int height;
};

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
SDL_Surface * surface = NULL; 

bool init();
bool loadMedia();
void close();

LTexture pieceTexture;
LTexture boardTexture;

int main(int argc, char * args [] )
{
	init();

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	bool quit = false;

	SDL_Event ev;

	while (!quit) {
		while (SDL_PollEvent(&ev) != 0) {
			if (ev.type == SDL_QUIT) {
				quit = true;
			}

		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		boardTexture.render(0, 0);

		pieceTexture.render(0, 0);

		SDL_RenderPresent(renderer);
	}

	close();

	return 0;
}

LTexture::LTexture() {
	//Initialize
	texture = NULL;
	width = 0;
	height = 0;
}

LTexture::~LTexture() {
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path) {
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

void LTexture::free() {
	if (texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void LTexture::render(int x, int y) {
	SDL_Rect renderQuad = { x, y, width, height };
	SDL_RenderCopy(renderer, texture, NULL, &renderQuad);
}

int LTexture::getWidth() {
	return width;
}

int LTexture::getHeight() {
	return height;
}

void LTexture::setWidth(int w) {
	width = w;
}

void LTexture::setHeight(int h) {
	height = h;
}

bool init()
{
	bool success = true; 

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
		}

		window = SDL_CreateWindow("Chess Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		
		if (window == NULL)
		{
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL)
			{
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia() {
	bool success = true;

	if (!pieceTexture.loadFromFile("..\\b_bishop_2x_ns.png")) {
		success = false;
	}
	return success;
}

void close() {
	boardTexture.free();
	pieceTexture.free();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
