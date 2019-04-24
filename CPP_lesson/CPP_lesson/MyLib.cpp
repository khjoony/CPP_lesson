#include <iostream>
#include <time.h>
#include <iomanip>

#include "MyLib.h"

using namespace std;

void CreateNum(int* pArr, int size)
{

	for (int i = 0; i < size; ++i)
	{
		pArr[i] = i + 1;
	}
}

void Shuffle(int* pArr, int size)
{
	srand((unsigned int)time(0));
	int iTemp, iIndex1, iIndex2;
	for (int i = 0; i < size * 4; ++i)
	{
		iIndex1 = rand() % size;
		iIndex2 = rand() % size;

		// Swap
		iTemp = pArr[iIndex1];
		pArr[iIndex1] = pArr[iIndex2];
		pArr[iIndex2] = iTemp;
	}
}

void PrintNum(int* pArr, int sizeLine, int sizeTot)
{
	for (int i = 0; i < sizeTot; ++i)
	{
		cout << setw(5) << pArr[i];
		if (i % 6 == sizeLine -1)
			cout << endl;
	}
}

void PrintNum(int* pArr, int size)
{
	cout << "AI's  number is ";
	for (int i = 0; i < size; ++i)
	{
		//cout << setw(5) << pArr[i];
		cout << setw(5) << "*";
	}
	cout << endl;
}

void UserInput(int* pArr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> pArr[i];
	}
	cout << " Your number is ";
	for (int i = 0; i < size; ++i)
	{
		cout << setw(5) << pArr[i];
	}
	cout << endl;
}

void Compare(int* pArr1, int* pArr2,int* pStr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i == j && pArr1[i] == pArr2[j])
			{
				++pStr[0];
			}
			else if (i != j && pArr1[i] == pArr2[j])
			{
				++pStr[1];
			}
		}
	}
}