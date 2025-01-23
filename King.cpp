#include "King.h"
#include <iostream>

using namespace std;

int error1King = 0;
int error2King = 0;
int error3King = 0;
int error4King = 0;

int King::moving(int board[8][8]) {

	error1King = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
	if (error1King == 1) {
		return error1King;
	}

	if (number == 2) {
		if (abs(startI - endI) <= 1 && abs(startJ - endJ) <= 1) {//сместился на 1 клетку
			if (board[endI][endJ] == -1 || board[endI][endJ] == 1 || board[endI][endJ] < -1) {

				error1King = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
				if (error1King == 1) {
					return error1King;
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

			}
			else {
				error1King = 1;
				return error1King;
			}
		}
		else {
			error1King = 1;
			return error1King;
		}
	}
	else {
		if (abs(startI - endI) <= 1 && abs(startJ - endJ) <= 1) {//сместился на 1 клетку
			if (board[endI][endJ] == -1 || board[endI][endJ] == 1 || board[endI][endJ] > 1) {
				error1King = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
				if (error1King == 1) {
					return error1King;
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
			}
			else {
				error1King = 1;
				return error1King;
			}
		}
		else {
			error1King = 1;
			return error1King;
		}
	}
	return error1King;
}

void King::checkShah(int board[8][8]) {

}