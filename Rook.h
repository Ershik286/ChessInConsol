#pragma once
#include "Unit.h"
class Rook : public Unit {
public:
	int number = 6;//םמלונ כאהüט
	int moving(int board[8][8], int number);
	int checkNoAlly(int board[8][8]);
};