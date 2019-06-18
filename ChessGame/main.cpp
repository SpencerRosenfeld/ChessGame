#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "LTextureClass.h"
#include "ChessPiece.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600; 

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
SDL_Surface * surface = NULL; 

bool init();
void close();
bool loadPawnTextureAndPiece();

LTextureClass pawnTexture;
ChessPiece pawnPiece;

int main(int argc, char * args [] )
{
	init();
	loadPawnTextureAndPiece();
	bool quit = false;

	SDL_Event ev;

	while (!quit) 
	{
		while (SDL_PollEvent(&ev) != 0) 
		{
			if (ev.type == SDL_QUIT) 
			{
				quit = true;
			}

		}
		SDL_RenderClear(renderer);
//		pawnPiece.texture->render(50, 50);

		pawnTexture.render(5, 5);

		SDL_RenderPresent(renderer);
	}



	close();

	return 0;
}

bool loadPawnTextureAndPiece() 
{
	bool success = true;

	pawnTexture.SetRenderer(renderer);

	
	if (pawnTexture.loadFromFile("C:\\Users\\marvi\\source\\repos\\SpencerRosenfeld\\ChessGame\\ChessGame\\Images\\b_bishop_2x_ns.bmp")) 
	{
		pawnTexture.setWidth(50);
		pawnTexture.setHeight(50);

		pawnPiece.texture = & pawnTexture ;
	}
	else
	{
		success = false;
	}


	return success;
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
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	IMG_Quit();
	SDL_Quit();
}
