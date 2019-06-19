#include "LTextureClass.h"

class ChessBoard
{
public : 
	ChessBoard();
	ChessBoard(LTextureClass * darkTile, LTextureClass * lightTile);
	void SetLightTile(LTextureClass * tileTexture);
	void SetDarkTile(LTextureClass * tileTexture);
	void DrawBoard();
	void DrawBoard(int x, int y);
private :
	LTextureClass * darkTile;
	LTextureClass * lightTile;
};