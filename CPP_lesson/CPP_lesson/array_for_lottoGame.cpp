// Create a game Lotto
#include <iostream>
#include <time.h>
#include <iomanip>

#include "MyLib.h"

using namespace std;

#define LOTTO 45
#define LOTNUM 6
void CreateNum (int* pArr, int size);
void Shuffle   (int* pArr, int size);
void PrintNum  (int* pArr, int sizeLine, int sizeTot);
int main()
{
	srand((unsigned int)time(0));

	int iLotto[LOTTO] = {};
	int *pLotto = iLotto;

	// Create number
	CreateNum(pLotto, LOTTO);

	// Shuffle
	int iRandomline;
	Shuffle(pLotto, LOTTO);

	// Print
	PrintNum(pLotto, LOTNUM, LOTTO);
	iRandomline = rand() % 7 + 1;
	cout << "\n This week's winning number is ";
	for (int i = 0; i < 6; ++i)
	{
		cout  <<setw(5) << iLotto[iRandomline + i] ;
		if (i == 5)
			cout << "\n Service Number is " << iLotto[iRandomline + i + 1];
	}
	return 0;
}