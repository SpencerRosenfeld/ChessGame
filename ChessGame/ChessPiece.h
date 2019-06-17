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
	std::string team;
	bool isCaptured;
};



