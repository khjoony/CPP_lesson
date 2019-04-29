#include <iostream>
#include <time.h>
#include <iomanip>
#include "MyLib.h"

enum LINE_NUM
{
	LN_H1 = 0,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};
using namespace std;
static int iStarIndex, iAiNoneStarCnt;
void CreateNum(int* pArr, int size)
{

	for (int i = 0; i < size; ++i)
	{
		pArr[i] = i + 1;
	}
}

void Shuffle(int* pArr, int iCol, int size)
{
	srand((unsigned int)time(0));
	int iTemp, iIndex1, iIndex2;
	for (int i = 0; i < size * iCol; ++i)
	{
		iIndex1 = rand() % size;
		iIndex2 = rand() % size;

		// Swap
		iTemp = pArr[iIndex1];
		pArr[iIndex1] = pArr[iIndex2];
		pArr[iIndex2] = iTemp;
	}
}

void PrintNum(int* pArr, int iCol, int sizeTot)
{
	for (int i = 0; i < sizeTot; ++i)
	{
		if (pArr[i] == INT_MAX)
		{
			cout << setw(5) << "*";
			iStarIndex = i;
		}

		else
		cout << setw(5) << pArr[i];
		if (i % iCol == iCol -1)
			cout << endl << endl;
	}
}

void PrintNum(int* pArr, int size)
{
	cout << "AI's  number is ";
	for (int i = 0; i < size; ++i)
	{
		cout << setw(5) << "*";
	}
	cout << endl;
}

int UserInput(int* pArr, int size, int& iEnd)
{
	for (int i = 0; i < size; ++i)
	{
		cin >> pArr[i];
		if (pArr[i] == 0)
			return iEnd = 0;
	}
	cout << " Your number is ";
	for (int i = 0; i < size; ++i)
	{
		cout << setw(5) << pArr[i];
	}
	cout << endl;
	return 0;
}

void MaxStar(int* pArr, int sizeStar, int& max)
{
	cout << "sizeStar : " << sizeStar << endl;
	int temp = 0;
	for (int i = 0; i < sizeStar; ++i) {
		if (pArr[i] < 5 && pArr[i] > temp)
		{
			temp = pArr[i];
			max = i;
		}
		cout << endl;
	}
}

void AiInput(int* pArr1, int* pArr2, int iCol, int sizeTot)
{
	int iAiNoneSelectCnt = 0;
	for (int i = 0; i < sizeTot; ++i)
	{
		if (pArr1[i] != INT_MAX)
		{
			pArr2[iAiNoneSelectCnt] = pArr1[i];
			++iAiNoneSelectCnt;
		}
	}
	cout << "iAiNoneSelectCnt = " << iAiNoneSelectCnt << endl;
	srand((unsigned int)time(0));
	int iIdx = rand() % (iAiNoneSelectCnt + 1);
	cout << "iIdx = " << iIdx << endl;
	pArr2[0] = pArr2[iIdx];
}

void AiInput(int* pArr1, int* pArr2, int iCol, int sizeTot, int max)
{
	switch (max)
	{
	case LN_H1:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i] != INT_MAX)
			{
				pArr2[0] = pArr1[i];
			}
		}
		break;
	case LN_H2:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i + iCol] != INT_MAX)
			{
				pArr2[0] = pArr1[i + iCol];
			}
		}
		break;
	case LN_H3:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i + iCol * 2] != INT_MAX)
			{
				pArr2[0] = pArr1[i + iCol *2];
			}
		}
		break;
	case LN_H4:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i + iCol * 3] != INT_MAX)
			{
				pArr2[0] = pArr1[i + iCol * 3];
			}
		}
		break;
	case LN_H5:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i + iCol * 4] != INT_MAX)
			{
				pArr2[0] = pArr1[i + iCol * 4];
			}
		}
		break;
	case LN_V1:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i * iCol ] != INT_MAX)
			{
				pArr2[0] = pArr1[i * iCol];
			}
		}
		break;
	case LN_V2:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i * iCol +1] != INT_MAX)
			{
				pArr2[0] = pArr1[i * iCol + 1];
			}
		}
		break;
	case LN_V3:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i * iCol +2] != INT_MAX)
			{
				pArr2[0] = pArr1[i * iCol + 2];
			}
		}
		break;
	case LN_V4:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i * iCol + 3] != INT_MAX)
			{
				pArr2[0] = pArr1[i * iCol + 3];
			}
		}
		break;
	case LN_V5:
		for (int i = 0; i < iCol; ++i)
		{
			if (pArr1[i * iCol + 4] != INT_MAX)
			{
				pArr2[0] = pArr1[i * iCol + 4];
			}
		}
		break;
	case LN_LT:
		for (int i = 0; i < sizeTot; i += (iCol + 1))
		{
			if (pArr1[i] != INT_MAX)
			{
				pArr2[0] = pArr1[i];
			}
		}
		break;
	case LN_RT:
		for (int i = 4; i < sizeTot - (iCol -1); i += (iCol - 1))
		{
			if (pArr1[i] != INT_MAX)
			{
				pArr2[0] = pArr1[i];
			}
		}
		break;
	}

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

void Compare(int* pArr1, int* pArr2, int iCol, int sizeTot)
{
	for (int i = 0; i < sizeTot; ++i)
	{
		for (int j = 0; j < iCol; ++j)
		{
			if (pArr1[i] == pArr2[j])
			{
				pArr1[i] = INT_MAX;
			}
		}
	}
}

void MoveUp(int* pArr, int iCol, int sizeTot)
{
	if (iStarIndex > iCol)
	{
		pArr[iStarIndex] = pArr[iStarIndex - iCol];
		pArr[iStarIndex - iCol] = INT_MAX;
	}
	else
	{
		pArr[iStarIndex] = pArr[iStarIndex + sizeTot - iCol];
		pArr[iStarIndex + sizeTot - iCol] = INT_MAX;
	}
}

void MoveDown(int* pArr, int iCol, int sizeTot)
{
	if (iStarIndex < sizeTot - iCol)
	{
		pArr[iStarIndex] = pArr[iStarIndex + iCol];
		pArr[iStarIndex + iCol] = INT_MAX;
	}
	else
	{
		pArr[iStarIndex] = pArr[iStarIndex - sizeTot + iCol];
		pArr[iStarIndex - sizeTot + iCol] = INT_MAX;
	}
}

void MoveLeft(int* pArr, int iCol, int sizeTot)
{
	if (iStarIndex % iCol != 0 )
	{
		pArr[iStarIndex] = pArr[iStarIndex - iCol/iCol];
		pArr[iStarIndex - iCol/iCol] = INT_MAX;
	}
	else
	{
		pArr[iStarIndex] = pArr[iStarIndex + iCol-1];
		pArr[iStarIndex +iCol -1] = INT_MAX;
	}
}

void MoveRight(int* pArr, int iCol, int sizeTot)
{
	if (iStarIndex % iCol != 4)
	{
		pArr[iStarIndex] = pArr[iStarIndex + iCol/iCol];
		pArr[iStarIndex + iCol/iCol] = INT_MAX;
	}
	else
	{
		pArr[iStarIndex] = pArr[iStarIndex - iCol +1];
		pArr[iStarIndex - iCol +1] = INT_MAX;
	}
}

void Count(int* pArr1, int* pArr2, int iCol, int sizeTot, int& iCnt)
{
	int iStarrX = 0, iStarlX = 0, iStarR = 0, iStarC = 0;
	iCnt = 0;
	for (int i = 0; i < iCol; ++i)
	{
		iStarR = iStarC = 0;
		for (int j = 0; j < iCol; ++j)
		{
			// Row Bingo
			if (pArr1[i * iCol + j] == INT_MAX)
			{
				++iStarR;
			}
			// Column Bingo
			if (pArr1[j * iCol + i] == INT_MAX)
			{
				++iStarC;
			}

		}
		pArr2[i] = iStarR;
		pArr2[i + iCol] = iStarC;
		if (iStarR == iCol)
			++iCnt;
		if (iStarC == iCol)
			++iCnt;
	}

	// Right Down Bingo
	for (int i = 0; i < sizeTot; i+= (iCol + 1))
	{
		if (pArr1[i] == INT_MAX)
			++iStarrX;
	}
	pArr2[10] = iStarrX;
	if (iStarrX == iCol)
		++iCnt;

	// Left Down Bingo
	for (int i = 4; i < sizeTot-1; i += (iCol - 1))
	{
		if (pArr1[i] == INT_MAX)
			++iStarlX;
	}
	pArr2[11] = iStarlX;
	if (iStarlX == iCol)
		++iCnt;
}