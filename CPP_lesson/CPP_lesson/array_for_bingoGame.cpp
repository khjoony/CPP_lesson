// Let's play bingo Game
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "MyLib.h"

using namespace std;
#define MATRIX 25
#define BINGO 5

void CreateNum(int* pArr, int sizeTot);
void Shuffle(int* pArr, int sizeTot);
void PrintNum(int* pArr, int iCol, int sizeTot);
int UserInput(int* pArr, int iCol, int& iEnd);
void Compare(int* pArr, int* iInput, int iCol, int sizeTot);
void Count(int* pArr, int iCol, int sizeTot, int& iCnt);
int main()
{
	int iMatrix[MATRIX] = { 0, };
	int iBingo[BINGO] = { 0, };
	int iInput[BINGO] = { 0, };

	int* pMatrix = iMatrix;
	int* pBingo = iBingo;
	int* pInput = iInput;
	int iCnt = 0, iEnd = 1;

	CreateNum(pMatrix, MATRIX);
	Shuffle(pMatrix, MATRIX);
	PrintNum(pMatrix, BINGO, MATRIX);
	while (true)
	{		
		cout << "Input number 1 to 25, Please [include 0 = Exit] : ";
		UserInput(pInput, BINGO, iEnd);
		if (iEnd == 0)
			break;
		system("cls");
		Compare(pMatrix, pInput, BINGO, MATRIX);
		PrintNum(pMatrix, BINGO, MATRIX);
		Count(pMatrix, BINGO, MATRIX, iCnt);
		cout << "BINGO = " << iCnt << endl;
		if (iCnt >= 4)
		{
			cout << "\n B.I.N.G.O ! !  Congratulation ~ ~ ! !" << endl;
			break;
		}
	}
	cout << "\n Bye ~ Bye ~ ~ ~" << endl;
	return 0;
}

