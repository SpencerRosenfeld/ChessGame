#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <thread>
#include <chrono>
#include "LTextureClass.h"
#include "ChessPiece.h"
#include "ChessBoard.h"

// The SCREEN_WIDTH and SCREEN_HEIGHT should be at least 8 times TILE_WIDTH in order to show the entire chess board. 
const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400; 
const int TILE_WIDTH = 50;
const int TILE_HEIGHT = 50; // We want the tiles to be squares so TILE_WIDTH and TILE_HEIGHT should be the same. 

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
SDL_Surface * surface = NULL; 

bool init();
void close();
bool loadPawnTextureAndPiece();
int snap(int x, int scale);

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

	ChessPiece pawn;
	pawn.texture = & whitePawnTexture;
	pawn.x = 304;
	pawn.y = 220;


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
			else if (ev.type == SDL_MOUSEBUTTONDOWN) 
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (pawn.isSelected == true)
				{
					pawn.isSelected = false;
					pawn.x = snap(x, pawn.getWidth());
					pawn.y = snap(y, pawn.getHeight());
				}
				else
				{
					if (pawn.isInsideBoundingBox(x, y))
					{
						pawn.isSelected = true;
					}
				}

			}

		}
		SDL_RenderClear(renderer);

		board.DrawBoard();
		blackRookTexture.render(100, 100);
		blackPawnTexture.render(100, 0);
		whitePawnTexture.render(0, 0);

		int mousex, mousey;
		SDL_GetMouseState(& mousex,& mousey);
		if (pawn.isSelected == true)
		{
			pawn.x = mousex - pawn.getWidth()/3;
			pawn.y = mousey - pawn.getHeight()/3;
		}

		pawn.Draw();
		SDL_RenderPresent(renderer);
	}

	close();

	return 0;
}

// This function loads the resources for all the textures. 
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
	blackPawnTexture.setWidth(TILE_WIDTH);
	blackPawnTexture.setHeight(TILE_HEIGHT);
	//blackPawnPiece.texture = &blackPawnTexture;
	whitePawnTexture.setWidth(TILE_WIDTH);
	whitePawnTexture.setHeight(TILE_HEIGHT);
	//whitePawnPiece
	blackBishopTexture.setWidth(TILE_WIDTH);
	blackBishopTexture.setHeight(TILE_HEIGHT);

	whiteBishopTexture.setWidth(TILE_WIDTH);
	whiteBishopTexture.setHeight(TILE_HEIGHT);

	blackKingTexture.setWidth(TILE_WIDTH);
	blackKingTexture.setHeight(TILE_HEIGHT);

	whiteKingTexture.setWidth(TILE_WIDTH);
	whiteKingTexture.setHeight(TILE_HEIGHT);

	blackQueenTexture.setWidth(TILE_WIDTH);
	blackQueenTexture.setHeight(TILE_HEIGHT);

	whiteQueenTexture.setWidth(TILE_WIDTH);
	whiteQueenTexture.setHeight(TILE_HEIGHT);

	blackRookTexture.setWidth(TILE_WIDTH);
	blackRookTexture.setHeight(TILE_HEIGHT);

	whiteRookTexture.setWidth(TILE_WIDTH);
	whiteRookTexture.setHeight(TILE_HEIGHT);

	blackKnightTexture.setWidth(TILE_WIDTH);
	blackKnightTexture.setHeight(TILE_HEIGHT);

	whiteKnightTexture.setWidth(TILE_WIDTH);
	whiteKnightTexture.setHeight(TILE_HEIGHT);

	lightBrownTexture.setWidth(TILE_WIDTH);
	lightBrownTexture.setHeight(TILE_HEIGHT);

	darkBrownTexture.setWidth(TILE_WIDTH);
	darkBrownTexture.setHeight(TILE_HEIGHT);

	lightGrayTexture.setWidth(TILE_WIDTH);
	lightGrayTexture.setHeight(TILE_HEIGHT);
	
	darkGrayTexture.setWidth(TILE_WIDTH);
	darkGrayTexture.setHeight(TILE_HEIGHT);

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

// This function returns the largest multiple of scale which is less than x. We assume that x and scale are both positive. 
int snap(int x, int scale) {
	return (x / scale ) * scale;
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
