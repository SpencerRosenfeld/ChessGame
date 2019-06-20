#include "ChessPiece.h"
#include <string>

ChessPiece::ChessPiece()
{
	isSelected = false;
}


ChessPiece::~ChessPiece()
{
	
}

int ChessPiece::getWidth() 
{
	return texture->getWidth();
}

int ChessPiece::getHeight()
{
	return texture->getHeight();
}

void ChessPiece::Draw()
{
	this->texture->render(this->x, this->y);
}

bool ChessPiece::isInsideBoundingBox(int x, int y) 
{
	int cX = this->x;
	int cY = this->y;
	int cW = this->texture->getWidth();
	int cH = this->texture->getHeight();
	if (x >= cX && x < cX + cW && y >= cY && y < cY + cH) 
	{
		return true;
	}
	return false;
}