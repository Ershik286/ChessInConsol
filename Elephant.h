#pragma once
#include "Unit.h"
class Elephant: public Unit{
private:
public:
	int color; //1 - �����, -1 - ������
	int number = 4;//����� �����
	int move(int board[8][8]);
	int check(int board[8][8]);
};