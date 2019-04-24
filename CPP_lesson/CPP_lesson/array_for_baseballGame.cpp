// Create a BaseBall Game
#include <iostream>
#include <iomanip>

#include "MyLib.h"

using namespace std;
#define NINE 9
#define THREE 3


void CreateNum(int* pArr, int size);
void Shuffle(int* pArr, int size);
void PrintNum(int* pArr, int size);
void UserInput(int* pArr, int size);
void Compare(int* pArr1, int* PArr2,int* pStr, int size);
int main()
{
	int aiArray[NINE] = { 0, };
	int uiArray[THREE] = { 0, };
	int baseBall[THREE] = { 0, };
	int* apArray = aiArray;
	int* upArray = uiArray;
	int* pStr = baseBall;

	CreateNum(apArray, NINE);
	Shuffle(apArray, NINE);
	while (true)
	{
		//system("cls");
		baseBall[0] = baseBall[1] = 0;
		cout << "Input number 0 to 9, Please (0 : Exit) : ";
		UserInput(upArray, THREE);
		PrintNum(apArray, THREE);
		Compare(apArray, upArray, pStr, THREE);
		if (uiArray[0] * uiArray[1] * uiArray[2] == 0)
		{
		cout << "Bye Bye~ ";
		break;
		}
		else if (uiArray[0] < 0 || uiArray[0] > 9 || uiArray[1] < 0 || uiArray[1] > 9 || uiArray[2] < 0 || uiArray[2] > 9)
		{
			cout << "Input wrong number! \n";
			continue;
		}
		else if (uiArray[0] == uiArray[1] || uiArray[1] == uiArray[2] || uiArray[2] == uiArray[0])
		{
			cout << "Don't have to input same number! \n";
			continue;
		}
		else if (baseBall[0] < THREE)
		{
			cout << setw(5) << baseBall[0] << " STRIKE " << setw(7) << baseBall[1] << " BALL !!" << endl;
			continue;
		}
		else if (baseBall[0] == THREE)
		{
			cout << setw(5) << baseBall[0] << " STRIKE " << setw(7) << baseBall[1] << " BALL !!" << endl;
			cout << "AI's  number is ";
			for (int i = 0; i < THREE; ++i)
			{
				cout << setw(5) << aiArray[i];
			}
			cout << endl << "Congratulation !!";
			break;
		}
		
	}
	return 0;
}