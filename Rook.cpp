#include <iostream>
#include "Rook.h"

using namespace std;

int error2Rook = 0;//������ ������� ������� ������ �� ����
int error3Rook = 0;//������ ������� �����

int checkAllyFigure = 0;

int startMoveY;
int endMoveY;

int startMoveX;
int endMoveX;
 
int Rook::moving(int board[8][8], int number) {
	if (number == 6) {//����� �������
		if (((startI - endI == 0 && startJ - endJ != 0)) || (startJ - endJ == 0 && startI - endI != 0) ) {//���� ��������� �� ������, ���� �� �������
			if (startI < endI) { //���������� ������������, ����� ������, �� ������ �������� ����������
				startMoveY = startI;
				endMoveY = endI;
			}
			else {
				startMoveY = endI;
				endMoveY = startI;
			}

			if (startJ < endJ) {
				startMoveX = startJ;
				endMoveX = endJ;
			}
			else {
				startMoveX = endJ;
				endMoveX = startJ;
			}

			checkAllyFigure = checkNoAlly(board);
			if (checkAllyFigure == 1) {
				error2Rook = 2;
				return 2;
			}
			if (error3Rook == 1) {
				error3Rook == 3;
				return error3Rook;
			}
			error3Rook = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
			if (error3Rook == 1) {
				return error3Rook;
			}
			board[endI][endJ] = number;
			if (startI % 2 != 0) {
				if (startJ % 2 == 0) {
					board[startI][startJ] = -1;//������ ����
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
		}
		else {
			error2Rook = 1;
			return error2Rook;
		}
	}
	else { //��� ������
		if (((startI - endI == 0 && startJ - endJ != 0)) || (startJ - endJ == 0 && startI - endI != 0)) {//���� ��������� �� ������, ���� �� �������
			if (startI < endI) { //���������� ������������, ����� ������, �� ������ �������� ����������
				startMoveY = startI;
				endMoveY = endI;
			}
			else {
				startMoveY = endI;
				endMoveY = startI;
			}

			if (startJ < endJ) {
				startMoveX = startJ;
				endMoveX = endJ;
			}
			else {
				startMoveX = endJ;
				endMoveX = startJ;
			}

			checkAllyFigure = checkNoAlly(board);
			if (checkAllyFigure == 1) {
				error2Rook = 2;
				return 2;
			}
			if (error3Rook == 1) {
				error3Rook == 3;
				return error3Rook;
			}
			error3Rook = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
			if (error3Rook == 1) {
				return error3Rook;
			}
			board[endI][endJ] = number;
			if (startI % 2 != 0) {
				if (startJ % 2 == 0) {
					board[startI][startJ] = -1;//������ ����
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
		}
		else {
			error2Rook = 1;
			return error2Rook;
		}
	}
}

int Rook::checkNoAlly(int board[8][8]) {
	checkAllyFigure = 0;
	for (int y = startMoveY; y <= endMoveY; y++) { //�������� � <=
		for (int x = startMoveX; x <= endMoveX; x++) {
			if (number == 6) {//��� ��������
				if (board[y][x] >= 2) { //������� ������
					checkAllyFigure = 1;
					if (y == startI && x == startJ) {
						checkAllyFigure = 0;
						continue;
					}
					return checkAllyFigure;
				}
			}
			else { //��� ������
				if (board[y][x] <= -2) {
					checkAllyFigure = 1;
					if (y == startI && x == startJ) {
						checkAllyFigure = 0;
						continue;
					}
					return checkAllyFigure;
				}
			}
		}
	}

	for (int y = startMoveY; y <= endMoveY; y++) {
		for (int x = startMoveX; x <= endMoveX; x++) {
			if (number == 6) {
				if (board[y][x] <= -2) { //���������
					error3Rook = 1;
					if (y == endI && x == endJ) {
						error3Rook = 0;
					}
				}
			}
			else {
				if (board[y][x] > 1) { //���������
					error3Rook = 1;
					if (y == endI && x == endJ) {
						error3Rook = 0;
					}
				}
			}
		}
	}
	if (error3Rook == 0) {
		board[endI][endJ] = number;
	}

	//�������� ��������� �������
	if (startI % 2 != 0) {
		if (startJ % 2 == 0) {
			board[startI][startJ] = -1;//������ ����
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
	return checkAllyFigure;
}