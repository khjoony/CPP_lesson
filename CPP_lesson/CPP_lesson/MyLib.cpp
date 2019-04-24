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
