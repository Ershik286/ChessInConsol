#pragma once
#include "Unit.h"
class Horse: public Unit{
public:
	int number = 5;//номер коня
	int move(int board[8][8]);
};