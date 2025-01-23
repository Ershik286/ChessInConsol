#include "Elephant.h"
#include <iostream>
#include <conio.h>

using namespace std;

int error1Elephant = 0;
int error2Elephant = 0;

int Elephant::move(int board[8][8]) {
	if (abs(startI - endI) == abs(startJ - endJ)) {
		error1Elephant = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
		if (error1Elephant == 1) {
			return error1Elephant;
		}
		if (error1Elephant == 0) {
			error1Elephant = check(board);
			if (error1Elephant == 1) {
				return error1Elephant;
			}
			board[endI][endJ] = number;
			if (startI % 2 != 0) {
				if (startJ % 2 == 0) {
					board[startI][startJ] = -1;//клетки поля
				}
				else {
					board[startI][startJ] = 1;
				}
			}
			else {
				if (startJ % 2 != 0) {
					board[startI][startJ] = -1;
				}
				else {
					board[startI][startJ] = 1;
				}
			}
			return error1Elephant;
		}
		else {
			return error1Elephant;
		}
	}
	else {
		error1Elephant = 1;
		return error1Elephant;
	}
}

int Elephant::check(int board[8][8]) {

	int startY = 0;
	int endY = 0;
	int startX = 0;
	int endX = 0;

	if (endI >= startI && endJ >= startJ) {//идет вниз вправо
		while (startY < endI && startX < endJ) {
			startY++;
			startX++;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Elephant = 1;
				//cout << "1 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}
	if (endI < startI && endJ <= startJ) {//идет вверх влево
		while (startY > endI && startX > endJ) {
			startY--;
			startX--;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Elephant = 1;
				//cout << "2 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}

	if (endI >= startI && endJ < startJ) {//идет вниз влево
		while (startY < endI && startX > endJ) {
			startY++;
			startX--;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Elephant = 1;
				//cout << "3 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}
	if (endI < startI && endJ >= startJ) {//идет вверх вправо
		while (startY > endI && startX < endJ) {
			startY--;
			startX++;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Elephant = 1;
				//cout << "4 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}
	//cout << "Проверка по диагонали: " << endl;
	//cout << error2Queen << endl;
	//int k = _getch();
	return error2Elephant;
}
