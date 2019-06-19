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
	std::string type;
	std::string team;
	bool isCaptured;
	LTextureClass * texture;
};



