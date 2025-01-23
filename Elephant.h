#pragma once
#include "Unit.h"
class Elephant: public Unit{
private:
public:
	int color; //1 - белый, -1 - черный
	int number = 4;//номер слона
	int move(int board[8][8]);
	int check(int board[8][8]);
};