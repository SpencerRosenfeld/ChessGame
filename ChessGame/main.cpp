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

	return 0;
}

LTexture::LTexture() {
	//Initialize
	texture = NULL;
	width = 0;
	height = 0;
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
