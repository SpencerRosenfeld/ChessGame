#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "LTextureClass.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600; 

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
SDL_Surface * surface = NULL; 

bool init();
void close();
bool loadPawnTextureAndPiece();

LTextureClass blackPawnTexture;
LTextureClass whitePawnTexture;
LTextureClass blackKnightTexture;
LTextureClass whiteKnightTexture;
LTextureClass blackBishopTexture;
LTextureClass whiteBishopTexture;
LTextureClass blackKingTexture;
LTextureClass whiteKingTexture;
LTextureClass blackQueenTexture;
LTextureClass whiteQueenTexture;
LTextureClass blackRookTexture;
LTextureClass whiteRookTexture;
LTextureClass lightBrownTexture;
LTextureClass darkBrownTexture;
LTextureClass lightGrayTexture;
LTextureClass darkGrayTexture;

ChessPiece blackPawnPiece;

int main(int argc, char * args [] )
{
	init();
	loadPawnTextureAndPiece();
	ChessBoard board = ChessBoard(& darkBrownTexture, & lightBrownTexture);

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

		board.DrawBoard();
		blackRookTexture.render(100, 100);
		blackPawnTexture.render(100, 0);
		whitePawnTexture.render(0, 0);

		SDL_RenderPresent(renderer);
	}

	close();

	return 0;
}

bool loadPawnTextureAndPiece() 
{
	bool success = true;

	// Set the renderers for the textures
	blackPawnTexture.SetRenderer(renderer);
	whitePawnTexture.SetRenderer(renderer);
	blackBishopTexture.SetRenderer(renderer);
	whiteBishopTexture.SetRenderer(renderer);
	blackKingTexture.SetRenderer(renderer);
	whiteKingTexture.SetRenderer(renderer);
	blackQueenTexture.SetRenderer(renderer);
	whiteQueenTexture.SetRenderer(renderer);
	blackRookTexture.SetRenderer(renderer);
	whiteRookTexture.SetRenderer(renderer);
	lightBrownTexture.SetRenderer(renderer);
	darkBrownTexture.SetRenderer(renderer);
	lightGrayTexture.SetRenderer(renderer);
	darkGrayTexture.SetRenderer(renderer);

	// Load the images for the textures from the appropraite files
	blackPawnTexture.loadFromFile("b_pawn_2x_ns.bmp");
	whitePawnTexture.loadFromFile("w_pawn_2x_ns.bmp");
	blackBishopTexture.loadFromFile("b_bishop_2x_ns.bmp");
	whiteBishopTexture.loadFromFile("w_bishop_2x_ns.bmp");
	blackKingTexture.loadFromFile("b_king_2x_ns.bmp");
	whiteKingTexture.loadFromFile("w_king_2x_ns.bmp");
	blackQueenTexture.loadFromFile("b_queen_2x_ns.bmp");
	whiteQueenTexture.loadFromFile("w_queen_2x_ns.bmp");
	blackRookTexture.loadFromFile("b_rook_2x_ns.bmp");
	whiteRookTexture.loadFromFile("w_rook_2x_ns.bmp");
	lightBrownTexture.loadFromFile("square brown light_2x_ns.bmp");
	darkBrownTexture.loadFromFile("square brown dark_2x_ns.bmp");
	lightGrayTexture.loadFromFile("square gray light_2x_ns.bmp");
	darkGrayTexture.loadFromFile("square gray dark_2x_ns.bmp");

	// Set the width and height of each texture
	blackPawnTexture.setWidth(50);
	blackPawnTexture.setHeight(50);
	//blackPawnPiece.texture = &blackPawnTexture;
	whitePawnTexture.setWidth(50);
	whitePawnTexture.setHeight(50);
	//whitePawnPiece
	blackBishopTexture.setWidth(50);
	blackBishopTexture.setHeight(50);

	whiteBishopTexture.setWidth(50);
	whiteBishopTexture.setHeight(50);

	blackKingTexture.setWidth(50);
	blackKingTexture.setHeight(50);

	whiteKingTexture.setWidth(50);
	whiteKingTexture.setHeight(50);

	blackQueenTexture.setWidth(50);
	blackQueenTexture.setHeight(50);

	whiteQueenTexture.setWidth(50);
	whiteQueenTexture.setHeight(50);

	blackRookTexture.setWidth(50);
	blackRookTexture.setHeight(50);

	whiteRookTexture.setWidth(50);
	whiteRookTexture.setHeight(50);

	blackKnightTexture.setWidth(50);
	blackKnightTexture.setHeight(50);

	whiteKnightTexture.setWidth(50);
	whiteKnightTexture.setHeight(50);

	lightBrownTexture.setWidth(50);
	lightBrownTexture.setHeight(50);

	darkBrownTexture.setWidth(50);
	darkBrownTexture.setHeight(50);

	lightGrayTexture.setWidth(50);
	lightGrayTexture.setHeight(50);
	
	darkGrayTexture.setWidth(50);
	darkGrayTexture.setHeight(50);

/*	
	if (blackPawnTexture.loadFromFile("b_pawn_2x_ns.bmp")) 
	{
		blackPawnTexture.setWidth(50);
		blackPawnTexture.setHeight(50);

		blackPawnPiece.texture = & blackPawnTexture ;
	}
	if ()
	else
	{
		success = false;
	}
	*/
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
			if (renderer == NULL)
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
