#pragma once
#include "Unit.h"
class Pehota: public Unit {
public:
	int number = 7;//номер пешки
	int moving(int board[8][8]);
	void cabin(int board[8][8]);
	int checkMoving(int board[8][8]);
	int checkCabin(int board[8][8]);
};