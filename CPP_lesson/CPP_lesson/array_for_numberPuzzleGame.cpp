// array_ for _numberPuzzle Game
#include <iostream>
#include <iomanip>

#include <conio.h>

#include "MyLib.h"

using namespace std;
#define PUZZLE 25
#define COL 5

void CreateNum(int* pArr, int size);
void Shuffle(int* pArr, int size);
void PrintNum(int* pArr, int iCol, int sizeTot);
void MoveUp(int* pArr, int iCol, int sizeTot);
void MoveDown(int* pArr, int iCol, int sizeTot);
void MoveLeft(int* pArr, int iCol, int sizeTot);
void MoveRight(int* pArr, int iCol, int sizeTot);
int main()
{
	int iPuzzle[PUZZLE] = { 0, };
	int* pPuzzle = iPuzzle;

	CreateNum(pPuzzle, PUZZLE);
	iPuzzle[PUZZLE -1] = INT_MAX;
	Shuffle(pPuzzle, PUZZLE-1);
	while (true)
	{
		system("cls");
		PrintNum(pPuzzle, COL, PUZZLE);

		bool  bWin = true;

		for (int i = 0; i < PUZZLE - 1; ++i)
		{
			if (iPuzzle[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}
		if (bWin == true)
		{
			cout << "Congratulation !!" << endl;
			break;
		}
		cout << "w : up  s : down  a : left  d : right  q : quit  : ";
		char cInput = _getch();
		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			MoveUp(pPuzzle, COL, PUZZLE);
			break;
		case 's':
		case 'S':
			MoveDown(pPuzzle, COL, PUZZLE);
			break;
		case 'a':
		case 'A':
			MoveLeft(pPuzzle, COL, PUZZLE);
			break;
		case 'd':
		case 'D':
			MoveRight(pPuzzle, COL, PUZZLE);
			break;
		}
	}


	cout << "\n Bye ~~~~~~~~~\n";
	return 0;
}

