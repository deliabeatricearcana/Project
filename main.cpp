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

char DeterminePlayerChoice (string s)
{

	while (1)
    {
    string name;
    cout<<"Player's name:"<<" ";
    cin>>name;
    s=name;
    string choice;
    cout<<s <<",what would you like your character to be? ";
    cin >> choice;
		if (choice.size() > 1) {
			cout << "You inputted more than one character. Please try again." << endl;
			continue;
		}
		cout << endl;
		return choice[0];
	}
}

char DetermineCpuChoice(char player1)
{

	char cpu;
	cout<< "Hello, I am the computer you will be playing." << endl;
	cout<< "If you chose x's, I will be o's. If you chose o's, I will be x's." << endl;
	cout<< "If you chose neither x or o, I will default to x." << endl << endl;

	if (player1== 'x'|| player1== 'X')
		cpu= 'o';

	else
		cpu= 'x';

	return cpu;
}

char CheckWin(char gameboard[3][3])
{ /**verificam daca elementele de pe orizontala, verticala si diagonala sunt egale cu elementul de pe linia 0 si coloana 0**/

	if (gameboard[0][0] != '.' &&
     (gameboard[0][0] == gameboard[0][1] && gameboard[0][0] == gameboard[0][2] ||
		gameboard[0][0] == gameboard[1][0] && gameboard[0][0] == gameboard[2][0] ||
		gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2]))

		return gameboard[0][0];

	if (gameboard[1][1] != '.' &&
     (gameboard[1][1] == gameboard[1][0] && gameboard[1][1] == gameboard[1][2] ||
		gameboard[1][1] == gameboard[0][1] && gameboard[1][1] == gameboard[2][1] ||
		gameboard[1][1] == gameboard[2][0] && gameboard[1][1] == gameboard[0][2]))

		return gameboard[1][1];

	if (gameboard[2][2] != '.' &&
     (gameboard[2][2] == gameboard[0][2] && gameboard[2][2] == gameboard[1][2] ||
		gameboard[2][2] == gameboard[2][0] && gameboard[2][2] == gameboard[2][1]))

		return gameboard[2][2];

	return 0;
}



void PlayerPlacement(char gameboard[3][3], char player)
{

	while (1)
        {/**Aceste instructiuni se vor executa repetat pana cand 1 va fi gasit ca fiind egal cu 0
            dar bineinteles ca 1 nu va fi niciodata egal cu 0, deci bucla se va repeta la infinit**/
		string stringrow, stringcol;
		int row= 0, col= 0;
		while (1)
		 {
			cout<< "Where would you like to play? " <<endl <<"Enter the row: ";
			cin >> stringrow;
			row = atoi(stringrow.c_str());

			if (row>=1 && row<=3)
				break;
			cout << "You need to enter a row on the board (between 1 and 3, inclusive)." << endl;
		}

		while (1)
		 {
			cout<< "Enter the column: ";
			cin>> stringcol;
			col= atoi(stringcol.c_str());

			if (col>= 1 && col<= 3)
				break;
			cout << "You need to enter a column on the board (between 1 and 3, inclusive)." << endl;
		}
		if (gameboard[row-1][col-1]== '.')
        {
			gameboard[row-1][col-1]= player;
			break;
		}
		else
			cout << "Someone already played there." << endl << endl;
	}
}

int BestMove(char gameboard[3][3], char player1, char player2)
 {

	int bestmovescore = -9999;
	int scoreforthismove = 0;

	if (CheckWin(gameboard) == player1)
		return 1000;

	else if (CheckWin(gameboard) == player2)
		return -1000;

	for (int r=0;r<3; r++)
        {
		for (int c= 0; c< 3; c++)
		 {
			if (gameboard[r][c] == '.')
			{
				gameboard[r][c]= player1;
				scoreforthismove= -(BestMove(gameboard, player2, player1));
				gameboard[r][c]= '.';
				if (scoreforthismove>=bestmovescore)
				 {
					bestmovescore= scoreforthismove;
				}
			}
		}
	}

	if (bestmovescore== -9999 || bestmovescore== 0)
		return 0;

	else if(bestmovescore<0)
		return bestmovescore+1;

	else if(bestmovescore>0)
		return bestmovescore-1;
/**Atata timp cat jocul se lungeste si recursia este cat mai complexa,
atunci mutarile sunt din ce in ce mai nefavorabile cu cat jocul se apropie de final**/
}

int PickBestMove(char gameboard[3][3],char player1,char player2)
{
	int bestmovescore= -9999;
	int bestmoverow= -9999;
	int bestmovecol= -9999;
	int scoreforthismove= 0;

	for(int r=0;r<3;r++)
        {
		for (int c=0; c<3; c++) {
			if (gameboard[r][c] == '.')
                {
				gameboard[r][c] = player1;
				scoreforthismove = -(BestMove(gameboard, player2, player1));
				gameboard[r][c] = '.';
				if (scoreforthismove >= bestmovescore) {
					bestmovescore = scoreforthismove;
					bestmoverow = r;
					bestmovecol = c;
				}
			}
		}
	}
	return (10*bestmoverow + bestmovecol);
}
