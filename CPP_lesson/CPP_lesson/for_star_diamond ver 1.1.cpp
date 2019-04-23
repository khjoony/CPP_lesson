// Create a for_star_diamond ver 1.1
// iLayer = input star number of line
// iCount = counter of layer
// dotSpace = number of space's dot

#include <iostream>

using namespace std;
void makeDiamond(int iLayer, int iCount);
#define EVEN 2
int main()
{
	int iLayer, iCount = 0;

	while (true)
	{
		cout << " Please input a oddynary number :";
		cin >> iLayer;

		if (iLayer % EVEN == 1)
		{
			makeDiamond(iLayer, iCount);
			break;
		}
		else
		{
			cout << "It is not a oddynary number !" << endl;
			cin.ignore(INT_MAX, '\n');
			continue;
		}
	}
	//system("pause");
	return 0;
}

void makeDiamond(int iLayer, int iCount)
{
	cout << "****** This is " << iLayer << "s layer star Diamond ******" << endl;
	int dotSpace = (iLayer < 20) ? 4 : (iLayer / 10) * (iLayer / 10);
	for (int i = 0; i < iLayer; ++i)
	{
		iCount = i;
		if (iCount > iLayer / EVEN)
		{
			iCount = iLayer - i - 1;
		}
			for (int j = 0; j <iLayer/EVEN - iCount + dotSpace; ++j)
			{
				cout << ".";
			}
			for (int k = 0; k < iCount * EVEN + 1; ++k)
			{
				cout << "*";
			}
			for (int j = 0; j <iLayer/EVEN - iCount + dotSpace; ++j)
			{
				cout << ".";
			}
			cout << endl;

		
	}
}