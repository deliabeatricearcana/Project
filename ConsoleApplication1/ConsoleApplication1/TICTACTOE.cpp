#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct TICTACTOE
{
	char gameboard[3][3];
	char player1;
	char player2;
	char cpu;
};

void initialize_board(char gameboard[3][3])
{
	system("color 53");
	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			gameboard[i][j] = '.';/**umplem toate cele 9 spatii din tabla de joc cu puncte**/
		}
	}
}

void print_board(char gameboard[3][3])
{
	for (int i = 0; i<3; i++)
	{
		cout << endl;
		for (int j = 0; j<3; j++)
		{
			cout << "  ";
			cout << gameboard[i][j]; //imprimam tabla de joc
		}
	}
	cout << endl << endl;
}

int main()
{

	TICTACTOE game;
	initialize_board(game.gameboard);
	return 0;
}