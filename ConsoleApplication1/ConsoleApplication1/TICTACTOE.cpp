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

void InitializeBoard(char gameboard[3][3])
{
	system("color 53");
	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j< 3; j++)
		{
			gameboard[i][j] = '.';
		}
	}
}

void PrintBoard(char gameboard[3][3])
{
	for (int i = 0; i<3; i++)
	{
		cout << endl;
		for (int j = 0; j<3; j++)
		{
			cout << "  ";
			cout << gameboard[i][j]; 
		}
	}
	cout << endl << endl;
}

int main()
{

	TICTACTOE game;
	InitializeBoard(game.gameboard);
	return 0;
}


