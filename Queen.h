#pragma once
#include "Unit.h"
#include "Rook.h"
class Queen: public Unit{
public:
	int number = 3;//םמלונ כאהüט
	int move(int board[8][8]);
	int checkLine(int board[8][8], int startX, int endX, int startI);
	int checkColon(int board[8][8], int startY, int endY, int startJ);
	int checkDiagonal(int board[8][8]);
	void moving(int board[8][8]);
};