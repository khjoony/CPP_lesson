// Create a game Lotto
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

#define LOTTO 45
int main()
{
	srand((unsigned int)time(0));
	
	int iLotto[LOTTO] = {};
	
	for (int i = 0; i < LOTTO; ++i)
	{
		iLotto[i] = i + 1;
	}

	// Shuffle
	int iTemp, iIndex1, iIndex2;
	int iRandomline;
	for (int i = 0; i < LOTTO * 4; ++i)
	{
		iIndex1 = rand() % LOTTO;
		iIndex2 = rand() % LOTTO;

		// Swap
		iTemp = iLotto[iIndex1];
		iLotto[iIndex1] = iLotto[iIndex2];
		iLotto[iIndex2] = iTemp;
	}

	for (int i = 0; i < LOTTO; ++i)
	{
		cout << setw(5) << iLotto[i];
		if (i % 6 == 5)
			cout << endl;
	}
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