#include "Pehota.h"
#include <iostream>
#include <conio.h>

using namespace std;

int error1Pawn = 0;

int Pehota::moving(int board[8][8]) {
	if (number == 7) {//ходит красный
		if (startJ - endJ == 0) {
			if (startI - endI == 2) {
				if (startI == 6 && number == 7) {
					checkMoving(board);
					if (error1Pawn == 1) {
						return error1Pawn;
					}
					if (board[endI + 1][endJ] != -1 && board[endI + 1][endJ] != 1) {
						error1Pawn = 1;
						return error1Pawn;
					}

					board[startI][startJ] = board[endI][endJ];
					startI = endI;
					startJ = endJ;
					board[startI][startJ] = number;
					error1Pawn = 0;
					return error1Pawn;
				}
				else {
					error1Pawn = 1;
					return error1Pawn;
				}
			}
			if (startI - endI == 1) {
				checkMoving(board);
				if (error1Pawn == 1) {
					return error1Pawn;
				}

				board[startI][startJ] = board[endI][endJ] * -1;
				startI = endI;
				startJ = endJ;
				board[startI][startJ] = number;
				error1Pawn = 0;
				return error1Pawn;
			}
			else {
				error1Pawn = 1;
				return error1Pawn;
			}
		}
		if (abs(startJ - endJ) == 1 && startI - endI == 1) {
			cabin(board);
			return error1Pawn;
		}
		else {
			error1Pawn = 1;
			return error1Pawn;
		}
	}
	else { //ход синего
		if (startJ - endJ == 0) {
			if (startI - endI == -2) {
				if (startI == 1 && number == -7) {
					checkMoving(board);
					if (error1Pawn == 1) {
						return error1Pawn;
					}

					if (board[endI - 1][endJ] != -1 && board[endI - 1][endJ] != 1) { //проверяем точку между стартовой и итоговой
						error1Pawn = 1;
						return error1Pawn;
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

					bool k = is_checkmate(board, number);
					if (k == true) {
						return 5;
					}
					return error1Pawn;
				}
				else {
					error1Pawn = 1;
					return error1Pawn;
				}
			}
			if (startI - endI == -1) {
				checkMoving(board);
				if (error1Pawn == 1) {
					return error1Pawn;
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

				bool k = is_checkmate(board, number);
				if (k == true) {
					return 5;
				}
				return error1Pawn;
			}
			else {
				error1Pawn = 1;
				return error1Pawn;
			}
		}
		if (abs(startJ - endJ) == 1 && startI - endI == -1) {
			cabin(board);
			return error1Pawn;
		}
		else {
			error1Pawn = 1;
			return error1Pawn;
		}
	}
}

void Pehota::cabin(int board[8][8]) {
	checkCabin(board);

	if (error1Pawn == 0) {

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
		startI = endI;
		startJ = endJ;
		board[startI][startJ] = number;
	}
}

int Pehota::checkMoving(int board[8][8]) {
	error1Pawn = checkShahMove(board, number, endI, endJ, startI, startJ, 1);//проверяем на шах
	if (error1Pawn == 1) {
		system("pause");
		return error1Pawn;
	}

	if (board[endI][endJ] != 1 && board[endI][endJ] != -1) {
		error1Pawn = 1;
	}
	else {
		error1Pawn = 0;
	}
	return error1Pawn;
}

int Pehota::checkCabin(int board[8][8]) {
	error1Pawn = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
	if (error1Pawn == 1) {
		return error1Pawn;
	}

	if (board[endI][endJ] * number < 0 && board[endI][endJ] != 1 && board[endI][endJ] != -1) { // если фигуры разные, то знак при умножении будет отрицательный
		error1Pawn = 0;
	}
	else {
		error1Pawn = 1;
	}
	return error1Pawn;
}