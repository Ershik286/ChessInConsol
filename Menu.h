#pragma once
class Menu{
private:
	const int len = 8;
	const int colomn = 8;

	const int BlackBoard = -1;
	const int WhiteBoard = 1;

	//    || �����: || 
	const int WhitePawn = 7; //����� �����
	const int WhiteRook = 6; //�����
	const int WhiteHorse = 5;//����
	const int WhiteElephant = 4;//����
	const int WhiteQeen = 3;//��������
	const int WhiteKing = 2;//������


	//     || ������ ||

	const int BlackPawn = -7;//������ �����
	const int BlackRook = -6;//�����
	const int BlackHorse = -5;//����
	const int BlackElephant = -4;//����
	const int BlackQeen = -3;//��������
	const int BlackKing = -2;//������

	const int Black = 240;
	const int White = 255;

public:
	int board[8][8];//������ � �����

	int tempFigure = 0;//��������� ������
	int tempLine = 0;//��������� �����
	int tempColon = 0;//��������� �������

	int move = 1; //����

	//1 - ����� ������, -1 - ������, 
	// �����: 2 - ������, 3 - �����, 4 - ����, 5 - ����, 6 - �����, 7 - �����
	//������: -2 - ������, -3 - �����, -4 - ����, -5 - ����, -6 - �����, -7 - �����

	//196 - �������, 123 - �����, ���, �����-����� - 240, ����� - 255, -1 - ������ ������, 1 - �����

	int startLine;
	int startColomn;
	int endLine;
	int endColomn;
	void complFigure();
	void set_console_color(int textColor, int backgroundColor);
	void reset_console_color();
	void print(int line, int colon, int error);
	void Game();
	int sumMaterials(int Figure, int sum);
};