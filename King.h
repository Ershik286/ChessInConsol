#pragma once
#include "Unit.h"
class King: public Unit{
public:
	int color; //1 - �����, -1 - ������
	int number = 2;
	int moving(int board[8][8]);
	void checkShah(int board[8][8]);
};