#include "Menu.h"
#include "Unit.h"
#include "King.h"
#include "queen.h"
#include "Rook.h"
#include "Horse.h"
#include "Elephant.h"
#include "Pehota.h"

#include "Window.h"

#include <iostream>
#include <conio.h>
#include <Math.h>

using namespace std;

int error1 = 0;//âûáðàíà íå ïðàâèëüíàÿ ôèãóðà
int error2 = 0;
int error3 = 0;
int error4 = 0;
int error5 = 0;

const int win = 5;

void Menu::set_console_color(int textColor, int backgroundColor) { //èçìåíåíèå öâåòà èñõîäÿ èç ïîäàííûõ àðãóìåíòîâ
	cout << "\033[48;5;" << backgroundColor << ";38;5;" << textColor << "m"; //ñëåâà öâåò ôîíà, ñïðàâà òåêñòà
}

void Menu::reset_console_color() {
	cout << "\033[0m";
}

void Menu::complFigure() {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < colomn; j++) {
			if (i == 1) {
				board[i][j] = BlackPawn;
				continue;
			}
			if (i == 6) {
				board[i][j] = 7;
				continue;
			}

			if (i % 2 != 0) {
				if (j % 2 == 0) {
					board[i][j] = BlackBoard;//êëåòêè ïîëÿ
				}
				else {
					board[i][j] = WhiteBoard;
				}
			}
			else {
				if (j % 2 != 0) {
					board[i][j] = BlackBoard;
				}
				else {
					board[i][j] = WhiteBoard;
				}
			}
		}
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < colomn; j++) {
			if (i == 0 || i == 7) {
				if (j == 0 || j == 7) {
					board[i][j] = BlackRook;
				}
				if (j == 1 || j == 6) {
					board[i][j] = BlackHorse;
				}
				if (j == 2 || j == 5) {
					board[i][j] = BlackElephant;
				}
				if (j == 4) {
					board[i][j] = BlackKing;
				}
				if (j == 3) {
					board[i][j] = BlackQeen;
				}
			}
			if (i == 7) { //åñëè ñíèçó, òî óìíîæàåì íàøè ïîñòàâëåííûå ôèãóðû íà -1
				board[i][j] = board[i][j] * -1;
			}
		}
	}
}

void Menu::print(int line, int colon, int error) {
	int colorBoard = 0;
	int colorText = 0;
	cout << "     Äëÿ çàâåðøåíèÿ íàæìèòå Esc" << endl;
	if (move % 2 != 0) {
		colorText = 196;
		set_console_color(colorText, colorBoard);
		cout << "            Õîä êðàñíîãî " << endl;
		reset_console_color();
	}
	else {
		colorText = 123;
		set_console_color(colorText, colorBoard);
		cout << "             Õîä ñèíåãî " << endl;
		reset_console_color();
	}
	cout << "===================================" << endl;
	char A = 'A';
	cout << " |";
	for (int i = 0; i < colomn; i++) {
		cout << "  " << A << "|";
		A++;
	}
	cout << endl;
	cout << "===================================" << endl;

	for (int i = 0; i < len; i++) {
		colorBoard = 255;
		colorText = 255;
		cout << i + 1 << "|";
		for (int j = 0; j < colomn; j++) {
			colorText = 0;

			if (i % 2 + j % 2 == 1) {
				colorBoard = Black;
			}
			else {
				colorBoard = White;
			}
			if ((i == line && j == colon) || (i == tempLine && j == tempColon)) {
				set_console_color(colorText, colorBoard);
				cout << ">";
				if (board[i][j] >= 1) {
					cout << " ";
				}
				reset_console_color();
			}
			if (board[i][j] > 0) {
				colorText = 196;
			}
			if (board[i][j] < -1) {
				colorText = 123;
			}
			if (board[i][j] == 1) {
				colorText = 255;
			}
			if (board[i][j] == -1) {
				colorText = 240;
			}
			set_console_color(colorText, colorBoard);
			if (board[i][j] >= 1 && ((i != line || j != colon) && (i != tempLine || j != tempColon))) {
				cout << "  ";
			}
			if (board[i][j] <= -1 && ((i != line || j != colon) && (i != tempLine || j != tempColon))) {
				cout << " ";
			}

			cout << board[i][j] << "";
			colorText = 0;
			if ((i == line && j == colon) || (i == tempLine && j == tempColon)) {
				reset_console_color();
				set_console_color(colorText, colorBoard);
				cout << "<";
				reset_console_color();
			}
			else {
				cout << " ";
			}
			reset_console_color();
		}
		cout << endl;
	}
	cout << "===================================" << endl;

	int SumRed = 0;
	int SumBlue = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] > 2) {
				SumRed = sumMaterials(board[i][j], SumRed);
			}
			if (board[i][j] < -2) {
				SumBlue = sumMaterials(board[i][j], SumBlue);
			}
		}
	}

	cout << "    Ñîîòíîøåíèå ìàòåðèàëà "; 
	colorText = 196;
	colorBoard = 0;
	set_console_color(colorText, colorBoard);
	cout << SumRed;
	reset_console_color();
	cout << "/";
	colorText = 123;
	set_console_color(colorText, colorBoard);
	cout << SumBlue << endl;
	reset_console_color();

	if (error == 1) {
		cout << "Íå âåðíûé õîä! " << endl;
		error = 0;
	}
	if (error == 2) {
		cout << "Íà ïóòè ñîþçíàÿ ôèãóðà! Îøèáêà " << endl;
		error = 0;
	}
	if (error == 3) {
		cout << "Íå âåðíûé õîä, íà ïóòè ôèãóðà! " << endl;
		error = 0;
	}
	if (error1 == 1) {
		cout << "Íå ïðàâèëüíî âûáðàíà ôèãóðà! Íå ïðàâèëüíûé öâåò" << endl;
		error1 = 0;
	}
}

int Menu::sumMaterials(int Figure, int sum) {
	if (abs(Figure) == 3) {
		sum += 9;
	}
	if (abs(Figure) == 4) {
		sum += 3;
	}
	if (abs(Figure) == 5) {
		sum += 3;
	}
	if (abs(Figure) == 6) {
		sum += 5;
	}
	if (abs(Figure) == 7) {
		sum += 1;
	}
	return sum;
}

void Menu::Game() {//çàãîòîâêà äëÿ îáðàáîòêè õîäîâ
    int line = 0;
    int colon = 0;
	int select = 0;
	int error = 0;

	//Window Window;
	//Window.win(board);

    while (true) {
        system("cls");
        int k = 0;
        print(line, colon, error);

	int SumRed = 0;
	int SumBlue = 0;

        int key = _getch();
        if (key == 0xE0) {
            while (k == 0) {
                key = _getch();
                switch (key)
                {
                case 72: //ñòðåëî÷êà ââåðõ
                    line--; //âû÷èñëåíèå ñòðîêè è ñòîëáöà ìîæíî ñäåëàòü ïðÿìî çäåñü
					line = line < 0 ? 7 : line;
                    break;
                case 75://ñòðåëî÷êà âëåâî
                    colon--;
					colon = colon < 0 ? 7 : colon;
                    break;
                case 77://ñòðåëî÷êà âïðàâî
                    colon++;
					colon = colon > 7 ? 0 : colon;
                    break;
                case 80://ñòðåëî÷êà âíèç
                    line++;
					line = line > 7 ? 0 : line;
                    break;
                case 8:
                    break;
                default:
                    continue;
                }

                break;
            }
        }
		if (key == 27) {
			return;
		}

        if (key == 13) {//Enter

			if ((board[line][colon] == 1 || board[line][colon] == -1) && select == 0) {
				continue;
			}

			if (board[line][colon] != -1 && board[line][colon] != 1 && select == 0) {
				if (move % 2 != 0 && board[line][colon] < -1) {
					error1 = 1;
					continue;
				}
				if (move % 2 == 0 && board[line][colon] > 1) {
					error1 = 1;
					continue;
				}
				tempFigure = board[line][colon];
				tempLine = line;
				tempColon = colon;
				select = 1;
				continue;
			}

			if (select == 1 && tempFigure * board[line][colon] > 0 && board[line][colon] != 1 && board[line][colon] != -1) {//ñîþçíèê, ïåðåñòàâëÿåì âûáðàííóþ ôèãóðó
				tempLine = line;
				tempColon = colon;
				tempFigure = board[line][colon];
				int k = _getch();
				continue;
			}

            if (select == 1) {//åñëè k2 == 1, òî øàøêà áûëà âûáðàíà
				if (tempFigure == BlackKing || tempFigure == WhiteKing) {
					King King;
					King.startI = tempLine;
					King.startJ = tempColon;
					King.number = tempFigure;
					King.endI = line;
					King.endJ = colon;
					error = King.moving(board);
					select = 0;
				}
				if (tempFigure == BlackQeen || tempFigure == WhiteQeen) {
					Queen Queen;
					Queen.startI = tempLine;
					Queen.startJ = tempColon;
					Queen.number = tempFigure;
					Queen.endI = line;
					Queen.endJ = colon;
					error = Queen.move(board);
					select = 0;
				}
				if (tempFigure == BlackRook || tempFigure == WhiteRook) {
					Rook Rook;
					Rook.startI = tempLine;
					Rook.startJ = tempColon;
					Rook.number = tempFigure;
					Rook.endI = line;
					Rook.endJ = colon;
					error = Rook.moving(board, Rook.number);
					select = 0;
				}
				if (tempFigure == BlackHorse || tempFigure == WhiteHorse) {
					Horse Horse;
					Horse.startI = tempLine;
					Horse.startJ = tempColon;
					Horse.number = tempFigure;
					Horse.endI = line;
					Horse.endJ = colon;
					error = Horse.move(board);
					select = 0;
				}
				if (tempFigure == BlackElephant || tempFigure == WhiteElephant) {
					Elephant Elephant;
					Elephant.startI = tempLine;
					Elephant.startJ = tempColon;
					Elephant.number = tempFigure;
					Elephant.endI = line;
					Elephant.endJ = colon;
					error = Elephant.move(board);
					select = 0;
				}
				if (tempFigure == BlackPawn || tempFigure == WhitePawn) {
					Pehota Peshka;
					Peshka.startI = tempLine;
					Peshka.startJ = tempColon;
					Peshka.number = tempFigure;
					Peshka.endI = line;
					Peshka.endJ = colon;
					error = Peshka.moving(board);
					select = 0;
				}
            }
			//cout << error << endl;
			//int k = _getch();
			if (error == 0) {
				move++;
				tempLine = 15;
				tempColon = 15;
			}
			if (error == win) {
				system("cls");
				int colorBoard = 0;
				print(line, colon, error);
				if (move % 2 != 0) {
					int colorText = 196;
					set_console_color(colorText, colorBoard);
					cout << "Âûéãðàë êðàñíûé! Ñèíèì áûë ïîñòàâëåí ìàò!" << endl;
					reset_console_color();
				}
				else {
					int colorText = 123;
					set_console_color(colorText, colorBoard);
					cout << "Âûéãðàë ñèíèé! Êðàñíûì áûë ïîñòàâëåí ìàò!" << endl;
					reset_console_color();
				}
				return;
			}
        }
    }
}
