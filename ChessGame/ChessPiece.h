#pragma once
#include <string>
#include "LTextureClass.h";

class ChessPiece
{
public:
	ChessPiece();
	~ChessPiece();
	int x;
	int y;
	int getWidth();
	int getHeight();
	std::string type;
	std::string team;
	bool isCaptured;
	LTextureClass * texture;
	bool isInsideBoundingBox(int x, int y);
	bool isSelected;
	void Draw();
};



