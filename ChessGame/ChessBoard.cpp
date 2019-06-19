#include "ChessBoard.h"
#include "LTextureClass.h"

ChessBoard::ChessBoard()
{
	darkTile = NULL;
	lightTile = NULL;
}

ChessBoard::ChessBoard(LTextureClass * darkTile, LTextureClass * lightTile)
{
	this->darkTile = darkTile;
	this->lightTile = lightTile;
}

void ChessBoard::SetLightTile(LTextureClass * tileTexture)
{
	this->lightTile = tileTexture;
}

void ChessBoard::SetDarkTile(LTextureClass * tileTexture)
{
	this->darkTile = tileTexture;
}
void ChessBoard::DrawBoard()
{
	int u, v, scale;

	scale = darkTile->getWidth(); // The tiles are square, so we assume that their width and height are the same

	for (int i = 1; i < 64; i++)
	{
		u = i % 8;
		v = i / 8;

		if ( (i + i/8) % 2  == 0)
		{
			darkTile->render(u * scale, v * scale);
		}
		else
		{
			lightTile->render(u * scale, v * scale);
		}
	}
}

void ChessBoard::DrawBoard(int x, int y)
{
	int u, v, scale;

	scale = darkTile->getWidth(); // The tiles are square, so we assume that their width and height are the same

	for (int i = 0; i < 64; i++)
	{
		u = i % 64;
		v = i / 64;

		if (i % 2 == 0)
		{
			darkTile->render(u * scale + x, v * scale + y);
		}
		else
		{
			lightTile->render(u * scale + x, v * scale + y);
		}
	}
}