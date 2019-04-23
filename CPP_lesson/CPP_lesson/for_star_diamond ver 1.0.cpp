// Make a diamond by *
/*
 ......*......
 .....***.....
 ....*****....
 ...*******...
 ....*****....
 .....***.....
 ......*......
*/
#include <iostream>

using namespace std;

void makeDiamond(int iIput);
int main()
{
	long long iInput, iCount;
	while (true)
	{
		cout << "Please enter odd number of layer : ";
		cin >> iInput;
		if (iInput % 2 == 1)
		{
			cout << "\nYour number is " << iInput << endl;
			makeDiamond(iInput);
			break;
		}
		else
		{
			cout << "Your Number is wrong number\n";
			cin.ignore(INT_MAX, '\n');
			continue;
		}
	}
	return 0;
}

void makeDiamond(int iInput)
{
	cout << "======= This is " << iInput << " layers diamond !! =======" << endl;
	// space iInput/2 iInput/2-1 iInput/2-2 ... 0 ... iInput/2-2 iInput/2-1 iInput/2
	// *     1  2 ... iInput/2-2 iInput/2-1  iInpu7   iInput/2-1 iInput/2-1  ... 2 1
	int dotSpace = (iInput < 20) ? 4 : (iInput / 10) * (iInput / 10);
	for (int i = 0; i < iInput / (2); ++i)
	{
		for (int j = 0; j < iInput / (2) - i - 1 + dotSpace; ++j)
		{
			cout << ".";
		}
		for (int k = iInput / (i + 2); k > iInput / (i + 2) - i * 2 - 1; --k)
		{
			cout << "*";
		}
		for (int j = iInput / (2) - i - 1 + dotSpace; j > 0; --j)
		{
			cout << ".";
		}

		cout << endl;
	}

	for (int i = iInput / 2; i >= 0; --i)
	{

		for (int j = iInput / (2) - i - 1 + dotSpace; j > 0; --j)
		{
			cout << ".";
		}
		for (int k = iInput / (i + 2) - i * 2 - 1; k < iInput / (i + 2); ++k)
		{
			cout << "*";
		}

		for (int j = 0; j < iInput / (2) - i - 1 + dotSpace; ++j)
		{
			cout << ".";
		}

		cout << endl;
	}
}