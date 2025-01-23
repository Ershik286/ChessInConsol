#include "Unit.h"
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int Shah = 0;

int LeftLineShah = 0; //������ �����
int RightLineShah = 0; //������ ������
int ForwardLineShah = 0; //������ ������
int DownLineShah = 0; //������ �����

int ForwardLeftDiagonal = 0;
int ForwardRightDiagonal = 0;
int DownLeftDiagonal = 0;
int DownRightDiagonal = 0;

//int Simulation = 0;

void Unit::SimulatedShah(int BoardCheck[8][8], int startI, int startJ, int endI, int endJ, int number) {
	BoardCheck[endI][endJ] = number;

	if (startI % 2 != 0) {
		if (startJ % 2 == 0) {
			BoardCheck[startI][startJ] = -1;//������ ����
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
	//����� ������� ����� ������� � ��������� �� �� �� ��� ��� ����
	int BoardCheck[8][8];

	for (int y = 0; y < 8; y++) {//������� ����� �������
		for (int x = 0; x < 8; x++) {
			BoardCheck[y][x] = board[y][x];
		}
	}
	if (Simulation == 1) {
		BoardCheck[endI][endJ] = number;

		if (startI % 2 != 0) {
			if (startJ % 2 == 0) {
				BoardCheck[startI][startJ] = -1;//������ ����
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
			if (BoardCheck[y][x] * number > 0 && (BoardCheck[y][x] == 2 || BoardCheck[y][x] == -2)) {//����� �������� ������
				int numberKingAlly = BoardCheck[y][x];
				int posY = y;//������� �������� ������
				int posX = x;//������� �������� ������
				int yCheck = posY;//����� ��� ��������
				int xCheck = posX;
				int tempY = posY;
				int tempX = posX;

				//��� �������� �� ������� ��������� �� �������� �� ������� �� �������. ���� ����� �� ������, �� ��� 7 - ���������� ������� (������ ������)
				//���� ����� �� �������, �� 7 - ���������� ������
				
				//������� �������� �� ���������� �� Y, �� ������� ���������, �������� y

				int plitY = 0;
				int plitOstalos = 8 - posY;
				for (int i = posY + 1; i < 8; i++) {//�������� �� ������� �� ����������
					if (BoardCheck[i][posX] == 1 || BoardCheck[i][posX] == -1) {
						plitY++;
					}
					if ((BoardCheck[i][posX] == 6 || BoardCheck[i][posX] == -6) && BoardCheck[i][posX] * numberKingAlly < 0) {//����� ��������� �����
						if (plitY == (i - posY) - 1) {//����� ����� � � ��������� �������� � ������
							Shah = 1;
							DownLineShah = 1;
							//cout << "������ � ������ �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
					}

					if ((BoardCheck[i][posX] == 3 || BoardCheck[i][posX] == -3) && BoardCheck[i][posX] * numberKingAlly < 0) {//����� ���������� �����
						if (plitY == (i - posY) - 1) {
							Shah = 1;
							DownLineShah = 1;
							//cout << "������ �� ������ �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
					}
				}

				for (int i = posY - 1; i > -1; i--) {//�������� �� ������� �� ����������

					if (BoardCheck[i][posX] == 1 || BoardCheck[i][posX] == -1) {
						plitY++;
					}
					if ((BoardCheck[i][posX] == 6 || BoardCheck[i][posX] == -6) && BoardCheck[i][posX] * numberKingAlly < 0) {//����� ��������� �����
						if (plitY == abs(i - posY) - 1) {//����� ����� � � ��������� �������� � ������
							Shah = 1;
							ForwardLineShah = 1;
							//cout << "������ � ������� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[i][posX] == 3 || BoardCheck[i][posX] == -3) && BoardCheck[i][posX] * numberKingAlly < 0) {//����� ���������� �����
						if (plitY == abs(i - posY) - 1) {
							Shah = 1;
							ForwardLineShah = 1;
							//cout << "������ � 4-� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}




				for (int j = posX + 1; j < 8; j++) {//�������� �� ������ �� ����������
					if (BoardCheck[posY][j] == 1 || BoardCheck[posY][j] == -1) {
						plitY++;
					}
					if ((BoardCheck[posY][j] == 6 || BoardCheck[posY][j] == -6) && BoardCheck[posY][j] * numberKingAlly < 0) {//����� ��������� �����
						if (plitY == (j - posY)) {//����� ����� � � ��������� �������� � ������
							Shah = 1;
							RightLineShah = 1;
							//cout << "������ � 5-� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[posY][j] == 3 || BoardCheck[posY][j] == -3) && BoardCheck[posY][j] * numberKingAlly < 0) {//����� ���������� �����
						if (plitY == (j - posY) - 1) {
							Shah = 1;
							RightLineShah = 1;
							//cout << "������ � 6-� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}

				for (int j = posX -1; j > -1; j--) {//�������� �� ������ �� ����������
					if (BoardCheck[posY][j] == 1 || BoardCheck[posY][j] == -1) {
						plitY++;
					}
					if ((BoardCheck[posY][j] == 6 || BoardCheck[posY][j] == -6) && BoardCheck[posY][j] * numberKingAlly < 0) {//����� ��������� �����
						if (plitY == abs(j - posY) - 1) {//����� ����� � � ��������� �������� � ������
							Shah = 1;
							LeftLineShah = 1;
							//cout << "������ � 7-� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}

					if ((BoardCheck[posY][j] == 3 || BoardCheck[posY][j] == -3) && BoardCheck[posY][j] * numberKingAlly < 0) {//����� ���������� �����
						if (plitY == abs(j - posY) - 1) {//����� ����� � ��� ��������� �������� � ������
							Shah = 1;
							LeftLineShah = 1;
							//cout << "������ � 8-� �������� �� �����" << endl;
							//int key = _getch();
							return Shah;
						}
						else {
							break;
						}
					}
				}

				//���������� �������� �� ����������, ������� ������� �� ������� ��������� �� ����������, ����� �� ����������, ����� �� ������� ��������� ����������
				//������� ���������� ������ �������� � ���� ���������, ���� ������ - �����, ����� ����� ����������� ���������� ������ ������, 
				//���� ����� �� ����� ��� ����� - ������� �� �������� => �� ��������, ��� ������ ������� ���-��.
				//���� ����� ���������� ����� ��� ����� �� ���������, �� ���������� ���������� ������ ������ �� ��������� � ���������� ������ �� ���������


				//���� ��������� �� 4 �����������
				int plitZero = 0;
				int plitDiagonal = 0;
				posY = y + 1;
				posX = x + 1;
				while (posY < 8 && posX < 8) {//��������� ���� - ������ (�� ���������� �� ����� ����)
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//����� ����� �����
						Shah = 1;
						DownRightDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 ||
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {//��������� �������� �� ������ ��������� ������ ��� �����
						if (plitZero == plitDiagonal) {
							Shah = 1;
							DownRightDiagonal = 1;
							//cout << "������ � 1-� �������� �� �����" << endl;
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
				while (posY < 8 && posX > 0) {//��������� ���� - ����� (y �������������, x �����������)
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//����� ����� �����
						Shah = 1;
						DownLeftDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 ||
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {
						if (plitZero == plitDiagonal) {
							Shah = 1;
							DownLeftDiagonal = 1;
							//cout << "������ � 2-� �������� �� �����" << endl;
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

				while (posY > 0 && posX >= 0) {//��������� ����� - ����� (y �����������, x �����������)  *��������*
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 0 || plitDiagonal == 0) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//����� ����� �����
						Shah = 1;
						ForwardLeftDiagonal = 1;
						return Shah;
					}
					if ((BoardCheck[posY][posX] == 3 || BoardCheck[posY][posX] == -3 || 
						BoardCheck[posY][posX] == 4 || BoardCheck[posY][posX] == -4) && (BoardCheck[posY][posX] * numberKingAlly < 0)) {
						if (plitZero == plitDiagonal) {
							Shah = 1;
							ForwardLeftDiagonal = 1;
							//cout << "������ � 3-� �������� �� �����" << endl;
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

				while (posY > 0 && posX < 8) {//��������� ����� - ������ (y �����������, x �������������)
					posY--;
					posX++;
					if (BoardCheck[posY][posX] == 1 || BoardCheck[posY][posX] == -1) {
						plitZero++;
					}
					if ((plitZero == 1 || plitDiagonal == 1) && (board[posY][posX] == 7 || board[posY][posX] == -7) && board[posY][posX] * numberKingAlly < 0) {//����� ����� �����
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
							//cout << "������ � 4-� �������� �� �����" << endl;
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
	// 1. ����� ������ �� �����.
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

	// ���� ������ �� ������, ��� ������ (�� � �������� ���� �� ������ �����������).
	if (king_row == -1) {
		cerr << "������: ������ �� ������ �� �����!" << std::endl;
		return false; // ��� ������ ���������� ��������
	}

	// 2. ���������, ��������� �� ������ ��� �����.

	int shah = checkShahMove(board, number * -1, king_row, king_col, king_row, king_col, 0);

	// 3. ���������, ����� �� ������ ������� ���, ����� ����� ��-��� ����.
	// ���������� ��� ��������� ���� ������ (8 �����������).
	int possible_moves[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
	};

	for (int i = 0; i < 8; ++i) {
		int new_row = king_row + possible_moves[i][0];
		int new_col = king_col + possible_moves[i][1];

		// ���������, ��� ����� ������� ��������� � �������� �����.
		if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
			// ������� ���
			Move move = { king_row, king_col, new_row, new_col };
			// �������� ������ ��� �� �����
			int temp = board[new_row][new_col];
			board[new_row][new_col] = board[king_row][king_col];

			if (king_row % 2 != 0) {
				if (king_col % 2 == 0) {
					board[king_row][king_col] = -1;//������ ����
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

			// ���������, �� ��������� �� ������ ��� ������ ����� ����.
			int is_safe = checkShahMove(board, number * -1, endI, endJ, startI, startJ, 0);

			// �������� ���
			board[king_row][king_col] = board[new_row][new_col];
			board[new_row][new_col] = temp;
			if (is_safe == 0) {
				// ���� ������ ����� ���� ��-��� ����, ��� �� ���.
				return false;
			}
		}
	}
	// 4. ���������, ����� �� �����-���� ������ ������ ������������� ��� ��� ������ ��������� ������.
	// (���� ��� ������� ����� ������� ������ � ������� �� ����� ���������� ����)
	for (int row = 0; row < 8; ++row) {
		for (int col = 0; col < 8; ++col) {
			if (board[row][col] != 1 && board[row][col] != -1 && ((king_color == 2 && board[row][col] > 0) || (king_color == -2 && board[row][col] < 0))) {
				//���������� ��� ���� ���� ������
				for (int i = 0; i < 8; ++i) {
					int new_row = row + possible_moves[i][0];
					int new_col = col + possible_moves[i][1];

					// ���������, ��� ����� ������� ��������� � �������� �����.
					if (new_row >= 0 && new_row < 8 && new_col >= 0 && new_col < 8) {
						// ������� ���
					    Move move = { row, col, new_row, new_col };

						// �������� ������ ��� �� �����
						int temp = board[new_row][new_col];
						board[new_row][new_col] = board[row][col];
						if (row % 2 != 0) {
							if (col % 2 == 0) {
								board[row][col] = -1;//������ ����
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

						//���� ����� ���� ������ ��� ����, �� ��� �� ���
						int k1 = checkShahMove(board, number, king_row, king_col, startI, startJ, 1);
						if (k1 == 0) {
							// �������� ���
							board[row][col] = board[new_row][new_col];
							board[new_row][new_col] = temp;
							return false;
						}
						// �������� ���
						board[row][col] = board[new_row][new_col];
						board[new_row][new_col] = temp;
					}
				}
			}
		}
	}

	// 5. ���� �� ���� �� ����������������� �������� �� ��������, ��� ���.
	return true;
}

int Unit::checkPate(int board[8][8], int number, int startI, int startJ, int endI, int endJ){
	//// 1. ���������, �� ��������� �� ������ ��� �����.
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

	//// 2. ��������� ��� ��������� ���� ���� ����� �������� ������.
	//for (int row = 0; row < 8; ++row) {
	//	for (int col = 0; col < 8; ++col) {
	//		if (board[row][col] != EMPTY && ((current_color == 1 && board[row][col] > 0) || (current_color == -1 && board[row][col] < 0))) {
	//			// �������� ��� ��������� ���� ��� ������ ������ (���������� ������� �� ����� ����)
	//			//  ��������  get_possible_moves �� ���� ����������
	//			std::vector<Move> possible_moves = get_possible_moves(board, row, col, current_color);

	//			for (const auto& move : possible_moves) {
	//				// ���������, �������� �� ��� ����������
	//				if (is_valid_move(board, move, current_color)) {
	//					// ���� ���� �� ���� ��� ��������, �� ���� ���
	//					return false;
	//				}
	//			}
	//		}
	//	}
	//}
	return 0;
}
