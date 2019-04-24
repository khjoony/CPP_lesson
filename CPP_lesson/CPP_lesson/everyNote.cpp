//
#include <iostream>

using namespace std;
int main()
{
	// Arrary====================
	int iArray[10] = { 0, };
	int iArray2[10][20] = { {0,},{0,} };


	for (int i = 0; i < sizeof(iArray) / sizeof(int); ++i)
	{
		iArray[i] = i;
		cout << "iArray [" << i << "] : " << iArray[i] << endl;
	}
	cout << iArray[1 + 2] << endl;
	int iValue = 0;
	for (int i = 0; i < sizeof(iArray2) / sizeof(iArray2[0]); ++i)
	{
		for (int j = 0; j < sizeof(iArray2[0]) / sizeof(int); ++j)
		{
			iValue++;
			iArray2[i][j] = iValue;
			cout << iArray2[i][j] << endl;
		}
	}
	return 0;
}