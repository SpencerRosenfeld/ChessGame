#pragma once
#include <string>

class ChessPiece
{
public:
	ChessPiece();
	~ChessPiece();
	int x;
	int y;
	std::string type;
	int team;
	bool isCaptured;
};



