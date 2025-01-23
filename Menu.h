#pragma once
class Menu{
private:
	const int len = 8;
	const int colomn = 8;

	const int BlackBoard = -1;
	const int WhiteBoard = 1;

	//    || Белые: || 
	const int WhitePawn = 7; //белая пешка
	const int WhiteRook = 6; //ладья
	const int WhiteHorse = 5;//конь
	const int WhiteElephant = 4;//слон
	const int WhiteQeen = 3;//королева
	const int WhiteKing = 2;//король


	//     || Черные ||

	const int BlackPawn = -7;//черная пешка
	const int BlackRook = -6;//ладья
	const int BlackHorse = -5;//конь
	const int BlackElephant = -4;//слон
	const int BlackQeen = -3;//королева
	const int BlackKing = -2;//король

	const int Black = 240;
	const int White = 255;

public:
	int board[8][8];//массив с полем

	int tempFigure = 0;//выбранная фигура
	int tempLine = 0;//выбранная линия
	int tempColon = 0;//выбранный столбец

	int move = 1; //ходы

	//1 - белая клетка, -1 - черная, 
	// белые: 2 - король, 3 - Ферзь, 4 - Слон, 5 - конь, 6 - ладья, 7 - пешка
	//Черные: -2 - король, -3 - ферзь, -4 - слон, -5 - конь, -6 - ладья, -7 - пешка

	//196 - красный, 123 - синий, фон, темно-серый - 240, белый - 255, -1 - черная клетка, 1 - белая

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