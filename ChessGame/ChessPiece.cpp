#include "ChessPiece.h"
#include <string>

using namespace std;

int x = 0;
int y = 0;
std::string type;

//team 1 = white, team 0 = black
//Under the chess rule, the white team goes first
int team = 1;
bool isCaptured = false;

ChessPiece::ChessPiece()
{
}


ChessPiece::~ChessPiece()
{
}
