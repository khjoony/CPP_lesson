// Let's play bingo Game
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "MyLib.h"

using namespace std;
#define MATRIX 25
#define BINGO 5
enum AI_MODE
{
	EASY = 1, HARD
};

void CreateNum(int* pArr, int sizeTot);
void Shuffle(int* pArr, int iCol, int sizeTot);
void PrintNum(int* pArr, int iCol, int sizeTot);
int UserInput(int* pArr, int iCol, int& iEnd);
void AiInput(int* pArr1, int* pArr2, int iCol, int sizeTot);
void Compare(int* pArr, int* iInput, int iCol, int sizeTot);
void Count(int* pArr, int iCol, int sizeTot, int& iCnt);
int main()
{
	int iCnt = 0, iAiCnt = 0, iEnd = 1, iAiMode;
	int iMatrix[MATRIX] = { 0, }, iAiMatrix[MATRIX] = { 0, };
	int iBingo[BINGO] = { 0, }, iAiBingo[BINGO] = { 0, };
	int iInput[BINGO] = { 0, }, iAiInput[MATRIX] = { 0, };

	int* pMatrix = iMatrix;
	int* pAiMatrix = iAiMatrix;
	int* pBingo = iBingo;
	int* pAiBingo = iAiBingo;
	int* pInput = iInput;
	int* pAiInput = iAiInput;
	
	while (true)
	{
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "Select mode : ";
		cin >> iAiMode;
		if (iAiMode >= EASY_MODE && iAiMode <= HARD_MODE)
			break;
	}

	CreateNum(pMatrix, MATRIX);
	Shuffle(pMatrix, BINGO, MATRIX);
	CreateNum(pAiMatrix, MATRIX);
	Shuffle(pAiMatrix, BINGO +1, MATRIX);
	cout << "========== User's Matrix ==========" << endl;
	PrintNum(pMatrix, BINGO, MATRIX);
	cout << "==========  AI's Matrix  ==========" << endl;
	PrintNum(pAiMatrix, BINGO, MATRIX);
	while (true)
	{		
		switch (iAiMode)
		{
		case EASY:
			cout << "Input number 1 to 25, Please [include 0 = Exit] : ";
			UserInput(pInput, BINGO / BINGO, iEnd);
			if (iEnd == 0)
				break;
			system("cls");
			Compare(pMatrix, pInput, BINGO / BINGO, MATRIX);
		    Compare(pAiMatrix, pInput, BINGO/BINGO, MATRIX);
			AiInput(pAiMatrix, pAiInput, BINGO/BINGO, MATRIX);
			Compare(pAiMatrix, pAiInput, BINGO/BINGO, MATRIX);
		    Compare(pMatrix, pAiInput, BINGO/BINGO, MATRIX);
			cout << "========== User's Matrix ==========" << endl;
		    PrintNum(pMatrix, BINGO, MATRIX);
			Count(pMatrix, BINGO, MATRIX, iCnt);
			cout << "User's Bingo line = " << iCnt << endl << endl;
			cout << "==========  AI's Matrix  ==========" << endl;
			PrintNum(pAiMatrix, BINGO, MATRIX);
			Count(pAiMatrix, BINGO, MATRIX, iAiCnt);
			cout << " AI's Bingo line =  " << iAiCnt << endl;
			break;

		case HARD:
			break;
		}

		if (iCnt >= 4)
		{
			cout << "\n You Win ! !  Congratulation ~ ~ ! !" << endl;
			break;
		}
		else if(iAiCnt >= 4)
		{
			cout << "\m AI Win ! !  We are sorry....." << endl;
			break;
		}
	}
	cout << "\n Bye ~ Bye ~ ~ ~" << endl;
	return 0;
}

