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

void InitializeBoard (char gameboard[3][3])
{
system("color 30");
	for (int i= 0;i< 3;i++)
        {
		for(int j= 0;j< 3;j++)
		{
			gameboard[i][j] = '.';
		}
	}
}


void PrintBoard(char gameboard[3][3])
{
	for(int i=0;i<3;i++)
        {
		cout << endl;
		for (int j=0;j<3; j++)
		 {
			cout << "  ";
			cout << gameboard[i][j];
		}
	}
	cout << endl << endl;
}

bool Question() {

	while (1)
	{ /**se repeta la infinit**/
		while (1)
            {
			string choice;
			int players = 0;
			cout << "Would you like to play with 2 players or against a computer?" << endl;
			cout << "Enter 1 for one player or 2 for two players: ";
			cin >> choice;
			cout << endl;
			players = atoi(choice.c_str()); /**functia interpreteaza stringul ca fiind un numar intreg, care va fi returnat ca o valoare de tip int**/
			if (players != 1 && players != 2)
			{
				cout << "Please enter either a 1 or a 2." << endl << endl;
			}
			else if (players == 1)
				return false;
			else if (players == 2)
				return true;
			break;
		}
	}
}

