#pragma once
#include "Unit.h"
class Horse: public Unit{
public:
	int number = 5;//����� ����
	int move(int board[8][8]);
};