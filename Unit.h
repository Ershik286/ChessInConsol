#pragma once
class Unit{
public:
	int number;
	int startI;
	int startJ;
	int endI;
	int endJ;
	int color;
	void SimulatedShah(int BoardCheck[8][8], int startI, int startJ, int endI, int endJ, int number);
	int checkShahMove(int board[8][8], int number, int endI, int endJ, int startI, int startJ, int simulation);
	bool is_checkmate(int board[8][8], int number);
	int checkPate(int board[8][8], int number, int startI, int startJ, int endI, int endJ);
private:
	struct Move {
		int start_row;
		int start_col;
		int end_row;
		int end_col;
	};
};