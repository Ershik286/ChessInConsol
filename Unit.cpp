#include "Unit.h"
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int Shah = 0;

int LeftLineShah = 0; //угроза слева
int RightLineShah = 0; //угроза справа
int ForwardLineShah = 0; //угроза сверху
int DownLineShah = 0; //угроза снизу

int ForwardLeftDiagonal = 0;
int ForwardRightDiagonal = 0;
int DownLeftDiagonal = 0;
int DownRightDiagonal = 0;

//int Simulation = 0;

void Unit::SimulatedShah(int BoardCheck[8][8], int startI, int startJ, int endI, int endJ, int number) {
	BoardCheck[endI][endJ] = number;

	if (startI % 2 != 0) {
		if (startJ % 2 == 0) {
			BoardCheck[startI][startJ] = -1;//клетки поля
		}
		else {
			BoardCheck[startI][startJ] = 1;
		}
	}
	else {
		if (startJ % 2 != 0) {
			BoardCheck[startI][startJ] = -1;
		}
		else {
			BoardCheck[startI][startJ] = 1;
		}
	}
}

int Unit::checkShahMove(int board[8][8], int number, int endI, int endJ, int startI, int startJ, int Simulation) {
	//можно сделать копию массива и проверить на нём то что нам надо
	int BoardCheck[8][8];

	for (int y = 0; y < 8; y++) {//создаем копию массива
		for (int x = 0; x < 8; x++) {
			BoardCheck[y][x] = board[y][x];
		}
	}
	if (Simulation == 1) {
		BoardCheck[endI][endJ] = number;

		if (startI % 2 != 0) {
			if (startJ % 2 == 0) {
				BoardCheck[startI][startJ] = -1;//клетки поля
			}
			else {
				BoardCheck[startI][startJ] = 1;
			}
		}
		else {
			if (startJ % 2 != 0) {
				BoardCheck[startI][startJ] = -1;
			}
			else {
				BoardCheck[startI][startJ] = 1;
			}
		}
	}

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (BoardCheck[y][x] * number > 0 && (BoardCheck[y][x] == 2 || BoardCheck[y][x] == -2)) {//нашли союзного короля
				int numberKingAlly = BoardCheck[y][x];
				int posY = y;//позиция союзного короля
				int posX = x;//позиция союзного короля
				int yCheck = posY;//копии для проверки
				int xCheck = posX;
				int tempY = posY;
				int tempX = posX;

				//для проверки по главной диагонали мы вычитаем из номеров по единице. Если вышли по строке, то это 7 - предыдущая колонка (смотри чертеж)
				//Если вышли по столбцу, то 7 - предыдущая строка
				
				//вначале проверим на увеличение по Y, по столбцу проверяем, изменяем y

				int plitY = 0;
				int plitOstalos = 8 - posY;
				for (int i = posY + 1; i < 8; i++) {//проверка по столбцу на увеличение
					if (BoardCheck[i][posX] == 1 || BoardCheck[i][posX] == -1) {
						plitY++;
					}
					if ((BoardCheck[i][posX] == 6 || BoardCheck[i][posX] == -6) && BoardCheck[i][posX] * numberKingAlly < 0) {//нашли вражескую ладью
						if (plitY == (i - posY) - 1) {//нашли ладью с её свободным доступом к королю
							Shah = 1;
							DownLineShah = 1;
							//cout << "Ошибка в Первой проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
					}

					if ((BoardCheck[i][posX] == 3 || BoardCheck[i][posX] == -3) && BoardCheck[i][posX] * numberKingAlly < 0) {//нашли вражеского ферзя
						if (plitY == (i - posY) - 1) {
							Shah = 1;
							DownLineShah = 1;
							//cout << "Ошибка во второй проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
					}
				}

				for (int i = posY - 1; i > -1; i--) {//проверка по столбцу на уменьшение

					if (BoardCheck[i][posX] == 1 || BoardCheck[i][posX] == -1) {
						plitY++;
					}
					if ((BoardCheck[i][posX] == 6 || BoardCheck[i][posX] == -6) && BoardCheck[i][posX] * numberKingAlly < 0) {//нашли вражескую ладью
						if (plitY == abs(i - posY) - 1) {//нашли ладью с её свободным доступом к королю
							Shah = 1;
							ForwardLineShah = 1;
							//cout << "Ошибка в третьей проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[i][posX] == 3 || BoardCheck[i][posX] == -3) && BoardCheck[i][posX] * numberKingAlly < 0) {//нашли вражеского ферзя
						if (plitY == abs(i - posY) - 1) {
							Shah = 1;
							ForwardLineShah = 1;
							//cout << "Ошибка в 4-й проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}




				for (int j = posX + 1; j < 8; j++) {//проверка по строке на увеличение
					if (BoardCheck[posY][j] == 1 || BoardCheck[posY][j] == -1) {
						plitY++;
					}
					if ((BoardCheck[posY][j] == 6 || BoardCheck[posY][j] == -6) && BoardCheck[posY][j] * numberKingAlly < 0) {//нашли вражескую ладью
						if (plitY == (j - posY)) {//нашли ладью с её свободным доступом к королю
							Shah = 1;
							RightLineShah = 1;
							//cout << "Ошибка в 5-й проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[posY][j] == 3 || BoardCheck[posY][j] == -3) && BoardCheck[posY][j] * numberKingAlly < 0) {//нашли вражеского ферзя
						if (plitY == (j - posY) - 1) {
							Shah = 1;
							RightLineShah = 1;
							//cout << "Ошибка в 6-й проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}

				for (int j = posX -1; j > -1; j--) {//проверка по строке на уменьшение
					if (BoardCheck[posY][j] == 1 || BoardCheck[posY][j] == -1) {
						plitY++;
					}
					if ((BoardCheck[posY][j] == 6 || BoardCheck[posY][j] == -6) && BoardCheck[posY][j] * numberKingAlly < 0) {//нашли вражескую ладью
						if (plitY == abs(j - posY) - 1) {//нашли ладью с её свободным доступом к королю
							Shah = 1;
							LeftLineShah = 1;
							//cout << "Ошибка в 7-й проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[posY][j] == 3 || BoardCheck[posY][j] == -3) && BoardCheck[posY][j] * numberKingAlly < 0) {//нашли вражеского ферзя
						if (plitY == abs(j - posY) - 1) {//нашли ферзя с его свободным доступом к королю
							Shah = 1;
							LeftLineShah = 1;
							//cout << "Ошибка в 8-й проверке на ладью" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}

				//начинается проверка по диагоналям, вначале считаем по главной диагонали на увеличение, затем на уменьшение, потом по младшей диагонали аналогично
				//Считаем количество клеток попавших в нашу диагональ, если попали - копим, также копим параллельно количество пустых клеток, 
				//если нашли не слона или ферзя - выходим из проверки => мы выяснили, что король прикрыт чем-то.
				//если нашли вражеского слона или ферзя на диагонали, то сравниваем количество пустых клеток на диагонали и количество клеток на диагонали


				//надо проверить на 4 направления
				int plitZero = 0;
				int plitDiagonal = 0;
				posY = y + 1;
				posX = x + 1;
				while (posY < 8 && posX < 8) {//проверяем вниз - вправо (на увеличение по обеим осям)
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//нашли рядом пешку
						Shah = 1;
						DownRightDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 ||
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {//проверяем является ли фигура вражеским слоном или ферзём
						if (plitZero == plitDiagonal) {
							Shah = 1;
							DownRightDiagonal = 1;
							//cout << "Ошибка в 1-й проверке на слона" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
					posY++;
					posX++;
					plitDiagonal++;
				}
				posY = y + 1;
				posX = x - 1;
				plitZero = 0;
				plitDiagonal = 0;
				//cout << posY << "/" << posX << endl;
				while (posY < 8 && posX > 0) {//проверяем вниз - влево (y увеличивается, x уменьшается)
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//нашли рядом пешку
						Shah = 1;
						DownLeftDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 ||
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {
						if (plitZero == plitDiagonal) {
							Shah = 1;
							DownLeftDiagonal = 1;
							//cout << "Ошибка в 2-й проверке на слона" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
					posY++;
					posX--;
					plitDiagonal++;
				}
				posY = y - 1;//
				posX = x - 1;
				plitZero = 0;
				plitDiagonal = 0;

				while (posY > 0 && posX >= 0) {//проверяем вверх - влево (y уменьшается, x уменьшается)  *Работает*
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//нашли рядом пешку
						Shah = 1;
						ForwardLeftDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 || 
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {
						if (plitZero == plitDiagonal) {
							Shah = 1;
							ForwardLeftDiagonal = 1;
							//cout << "Ошибка в 3-й проверке на слона" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
					posY--;
					posX--;
					plitDiagonal++;
				}
				posY = y;//
				posX = x;
				plitZero = 0;
				plitDiagonal = 0;

				while (posY > 0 && posX < 8) {//проверяем вверх - вправо (y уменьшается, x увеличивается)
					posY--;
					posX++;
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 1 || plitDiagonal == 1) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//нашли рядом пешку
						Shah = 1;
						ForwardRightDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 ||
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {
						//cout << posY << "/" << posX << endl;
						//cout << plitZero << "/" << plitDiagonal << endl;
						//system("pause");
						if (plitZero == plitDiagonal) {
							Shah = 1;
							ForwardRightDiagonal = 1;
							//cout << "Ошибка в 4-й проверке на слона" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
					//cout << posY << "/" << posX << endl;
					plitDiagonal++;
					//system("pause");
				}
				break;
			}
		}
	}
	return Shah;
}

bool Unit::is_checkmate(int board[8][8], int number) {
	// 1. Найти короля на доске.
	int king_color;
	if (number < 0) {
		king_color = 2;
	}
	else {
		king_color = -2;
	}
	int king_row = -1;
	int king_col = -1;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {

			if (board[i][j] == 2 || board[i][j] == -2 && (board[i][j] * number > 0)) {
				king_row = i;
				king_col = j;
				break;
			}
		}
		if (king_row != -1) break;
	}

	// Если король не найден, это ошибка (но в реальной игре не должно происходить).
	if (king_row == -1) {
		cerr << "Ошибка: Король не найден на доске!" << std::endl;
		return false; // Или другое подходящее действие
	}

	// 2. Проверить, находится ли король под шахом.

	int shah = checkShahMove(board, number * -1, king_row, king_col, king_row, king_col, 0);

	// 3. Проверить, может ли король сделать ход, чтобы выйти из-под шаха.
	// Перебираем все возможные ходы короля (8 направлений).
	int possible_moves[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
	};

	for (int i = 0; i < 8; ++i) {
		int new_row = king_row + possible_moves[i][0];
		int new_col = king_col + possible_moves[i][1];

		// Проверить, что новая позиция находится в пределах доски.
		if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
			// Создаем ход
			Move move = { king_row, king_col, new_row, new_col };
			// Временно делаем ход на доске
			int temp = board[new_row][new_col];
			board[new_row][new_col] = board[king_row][king_col];

			if (king_row % 2 != 0) {
				if (king_col % 2 == 0) {
					board[king_row][king_col] = -1;//клетки поля
				}
				else {
					board[king_row][king_col] = 1;
				}
			}
			else {
				if (startJ % 2 != 0) {
					board[king_row][king_col] = -1;
				}
				else {
					board[king_row][king_col] = 1;
				}
			}

			// Проверяем, не находится ли король под атакой после хода.
			int is_safe = checkShahMove(board, number * -1, endI, endJ, startI, startJ, 0);

			// Отменяем ход
			board[king_row][king_col] = board[new_row][new_col];
			board[new_row][new_col] = temp;
			if (is_safe == 0) {
				// Если король может уйти из-под шаха, это не мат.
				return false;
			}
		}
	}
	// 4. Проверить, может ли какая-либо другая фигура заблокировать шах или съесть атакующую фигуру.
	// (Этот шаг требует более сложной логики и зависит от вашей реализации игры)
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] != 1 && board[row][col] != -1 && ((king_color == 2 && board[row][col] > 0) || (king_color == -2 && board[row][col] < 0))) {
				//Перебираем все ходы этой фигуры
				for (int i = 0; i < 8; ++i) {
					int new_row = row + possible_moves[i][0];
					int new_col = col + possible_moves[i][1];

					// Проверить, что новая позиция находится в пределах доски.
					if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
						// Создаем ход
					    Move move = { row, col, new_row, new_col };

						// Временно делаем ход на доске
						int temp = board[new_row][new_col];
						board[new_row][new_col] = board[row][col];
						if (row % 2 != 0) {
							if (col % 2 == 0) {
								board[row][col] = -1;//клетки поля
							}
							else {
								board[row][col] = 1;
							}
						}
						else {
							if (startJ % 2 != 0) {
								board[row][col] = -1;
							}
							else {
								board[row][col] = 1;
							}
						}

						//Если после хода короля нет шаха, то это не мат
						int k1 = checkShahMove(board, number, king_row, king_col, startI, startJ, 1);
						if (k1 == 0) {
							// Отменяем ход
							board[row][col] = board[new_row][new_col];
							board[new_row][new_col] = temp;
							return false;
						}
						// Отменяем ход
						board[row][col] = board[new_row][new_col];
						board[new_row][new_col] = temp;
					}
				}
			}
		}
	}

	// 5. Если ни один из вышеперечисленных способов не помогает, это мат.
	return true;
}

int Unit::checkPate(int board[8][8], int number, int startI, int startJ, int endI, int endJ){
	//// 1. Проверить, не находится ли король под шахом.
	//int current_color;
	//if (number > 0) {
	//	current_color = 1;
	//}
	//else {
	//	current_color = -1;
	//}
	//int king_row = -1;
	//int king_col = -1;
	//for (int i = 0; i < 8; ++i) {
	//	for (int j = 0; j < 8; ++j) {
	//		if (board[i][j] == 2 || board[i][j] == -2 && ((current_color == 1 && board[i][j] > 0) || (current_color == -1 && board[i][j] < 0))) {
	//			king_row = i;
	//			king_col = j;
	//			break;
	//		}
	//	}
	//	if (king_row != -1) break;
	//}
	//int opponent_color = (current_color == 1) ? -1 : 1;
	//if (checkShahMove(board, board[king_row][king_col], king_row, king_col, king_row, king_col, 0) == 1) return false;

	//// 2. Проверить все возможные ходы всех фигур текущего игрока.
	//for (int row = 0; row < 8; ++row) {
	//	for (int col = 0; col < 8; ++col) {
	//		if (board[row][col] != EMPTY && ((current_color == 1 && board[row][col] > 0) || (current_color == -1 && board[row][col] < 0))) {
	//			// Получить все возможные ходы для данной фигуры (реализация зависит от вашей игры)
	//			//  Замените  get_possible_moves на вашу реализацию
	//			std::vector<Move> possible_moves = get_possible_moves(board, row, col, current_color);

	//			for (const auto& move : possible_moves) {
	//				// Проверить, является ли ход допустимым
	//				if (is_valid_move(board, move, current_color)) {
	//					// Если хотя бы один ход возможен, то пата нет
	//					return false;
	//				}
	//			}
	//		}
	//	}
	//}
	return 0;
}
