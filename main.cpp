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
