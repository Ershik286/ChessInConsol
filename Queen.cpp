#include "Queen.h"
#include <iostream>
#include <conio.h>

using namespace std;

int errorQueen = 0;
int error2Queen = 0;
int error3Queen = 0;
int error4Queen = 0;

int Queen::move(int board[8][8]) {

	int startY, startX, endY, endX;
	if (endI >= startI) {
		startY = startI;
		endY = endI;
	}
	else {
		startY = endI;
		endY = startI;
	}
	if (endJ >= startJ) {
		startX = startJ;
		endX = endJ;
	}
	else {
		startX = endJ;
		endX = startJ;
	}

	//cout << "Start x/y : " << startY << startX << endl;
	//cout << "End x/y: " << endY << endX << endl;
	//cout << errorQueen << endl;
	//int k = _getch();

	//errorQueen = checkShah(board);
	if (errorQueen == 0) {
		if (startI == endI && startJ != endJ) {//перемещение по строке
			errorQueen = checkLine(board, startX, endX, startY);
			if (errorQueen == 1) {
				//cout << errorQueen << " - 1 Не гойда " << endl;
				//int k = _getch();
				return errorQueen;
			}
			errorQueen = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
			if (errorQueen == 1) {
				//cout << "1" << endl;
				//int k = _getch();
				return errorQueen;
			}
			moving(board);
			bool k = is_checkmate(board, number);
			if (k == true) {
				return 5;
			}
			return errorQueen;
		}

		if (startI != endI && startJ == endJ) {//перемещение по столбику
			errorQueen = checkColon(board, startY, endY, startX);
			if (errorQueen == 1) {
				//cout << errorQueen << " - 2 Не гойда " << endl;
				//int k = _getch();
				return errorQueen;
			}
			errorQueen = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
			if (errorQueen == 1) {
				//cout << "2" << endl;
				//int k = _getch();
				return errorQueen;
			}
			moving(board);
			bool k = is_checkmate(board, number);
			if (k == true) {
				return 5;
			}
			return errorQueen;
		}
		
		if (abs(startI - endI) == abs(startJ - endJ)) {//перемещение по диагонали
			errorQueen = checkDiagonal(board);
			if (errorQueen == 1) {
				//cout << errorQueen << " - 3 Не гойда " << endl;
				//int k = _getch();
				return errorQueen;
			}
			//cout << "Проверка диагонали: " << errorQueen << endl;
			errorQueen = checkShahMove(board, number, endI, endJ, startI, startJ, 1);
			//cout << "Проверка на шах" << errorQueen << endl;
			//int k = _getch();
			if (errorQueen == 1) {
				//cout << "3" << endl;
				//int k = _getch();
				return errorQueen;
			}
			moving(board);
			bool k = is_checkmate(board, number);
			if (k == true) {
				return 5;
			}
			return errorQueen;
		}
		errorQueen = 1;
		return errorQueen;
	}
}

int Queen::checkLine(int board[8][8], int startX, int endX, int startI) {
	for (int x = startX + 1; x < endX; x++) {
		if (board[startI][x] != 1 && board[startI][x] != -1) {
			//cout << "Точка ошибки Line " << startI << "/" << x << endl;
			//int k = _getch();
			error2Queen = 1;
			return error2Queen;
		}
	}
	return error2Queen;
}

int Queen::checkColon(int board[8][8], int startY, int endY, int startJ){
	for (int y = startY + 1; y < endY; y++) {
		if (board[y][startJ] != 1 && board[y][startJ] != -1) {
			//cout << "Точка ошибки Colon " << y + 1 << "/" << startJ + 1 << endl;
			//int k = _getch();
			error3Queen = 1;
			return error3Queen;
		}
	}
	return error3Queen;
}

int Queen::checkDiagonal(int board[8][8]) {

	int startY = 0;
	int endY = 0;
	int startX = 0;
	int endX = 0;

	startY = startI;
	startX = startJ;


	if (endI >= startI && endJ >= startJ) {//идет вниз вправо
		while (startY < endI - 1 && startX < endJ - 1) {
			startY++;
			startX++;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Queen = 1;
				//cout << "1 d" << endl;
				//cout << startY << "/" << startX << endl;
				//int k = _getch();
				break;
			}
		}
	}
	if (endI < startI && endJ <= startJ) {//идет вверх влево
		while (startY > endI + 1 && startX > endJ + 1) {
			startY--;
			startX--;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Queen = 1;
				//cout << "2 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}

	if (endI >= startI && endJ < startJ) {//идет вниз влево
		while (startY < endI - 1 && startX > endJ + 1) {
			startY++;
			startX--;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Queen = 1;
				//cout << "3 d" << endl;
				//int k = _getch();
				break;
			}
		}
	}
	if (endI < startI && endJ >= startJ) {//идет вверх вправо
		while (startY > endI + 1 && startX < endJ - 1) {
			startY--;
			startX++;
			if (board[startY][startX] != -1 && board[startY][startX] != 1) {
				error2Queen = 1;
				//cout << "4 d" << endl;
				//cout << startY << "/" << startX << endl;
				//int k = _getch();
				break;
			}
		}
	}
	//cout << "Проверка по диагонали: " << endl;
	//cout << error2Queen << endl;
	//int k = _getch();
	return error2Queen;
}

void Queen::moving(int board[8][8]){
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
