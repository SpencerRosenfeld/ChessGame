#include "ChessPiece.h"
#include <string>

ChessPiece::ChessPiece()
{
	//team 1 = white, team 0 = black
	//Under the chess rule, the white team goes first
	team = 1;

	x = 0;
	y = 0;
	isCaptured = false;
}


ChessPiece::~ChessPiece()
{
	free();
}
