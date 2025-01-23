#include "Horse.h"
#include <iostream>

int Horse::move(int board[8][8]) {//по строка - 2 столбец +- 1, строка + 2 столбец +- 1, столбец + 2 строка +- 1, столбец - 2, столбец +-1

	int errorHorse = 0;

	errorHorse = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
	if (errorHorse == 1) {
		return errorHorse;
	}

	if (abs(startI - endI) == 2 && (startJ + 1 == endJ || startJ - 1 == endJ)) {
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

		bool k = is_checkmate(board, number);
		if (k == true) {
			return 5;
		}
		return errorHorse;
	}

	if (abs(startJ - endJ) == endJ && (startI + 1 == endI || startI - 1 == endI)) {
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

		bool k = is_checkmate(board, number);
		if (k == true) {
			return 5;
		}
		return errorHorse;
	}
}