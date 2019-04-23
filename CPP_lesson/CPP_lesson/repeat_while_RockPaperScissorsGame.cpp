// Make a RockPaperScissorsGame using a Repeat while statement.
#include <iostream>
#include <time.h>

using namespace std;
#define MACROSTR(k)
typedef enum SRP
{
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_END
};

static const char *srpStr[] =
{
	"Scissors", "Rock", "Paper"
};
int main()
{
	int iSRP, aiSRP;
	SRP srp;
	srand((unsigned int)time(0));

	cout << "[1:Scissors, 2:Rock, 3:Paber, 4:End]";
	aiSRP = rand() % 3 + 1;

	while (true)
	{
	cout << "Select SRP  :";
	cin >> iSRP;
		if (1 > iSRP || iSRP > 4)
		{
			cout << "It is wrong number, please choice a number between 1 and 4\n";
			continue;
		}
		else if(1 <= iSRP && iSRP <= 4)
		{
			switch (iSRP)
			{
			case SRP_S:
				cout << "YOU : Scissors\nAI : " << srpStr[aiSRP-1] << endl;
				if (SRP_S == aiSRP)
				{
					cout << "Draw\n";
				}
				else if (SRP_S + 2  == aiSRP)
				{
					cout << "YOU WIN!\n";
				}
				else if (SRP_S +1 == aiSRP)
				{
					cout << "YOU LOSE!\n";
				}
				break;
			case SRP_R:
				cout << "YOU : Rock\nAI : " << srpStr[aiSRP] << endl;
				if (SRP_R == aiSRP)
				{
					cout << "Draw\n";
				}
				else if (SRP_R == aiSRP + 1)
				{
					cout << "YOU WIN!\n";
				}
				else if (SRP_R == aiSRP - 1)
				{
					cout << "YOU LOSE!\n";
				}
				break;
			case SRP_P:
				cout << "YOU : Paper\nAI : " << srpStr[aiSRP] << endl;
				if (SRP_P == aiSRP)
				{
					cout << "Draw\n";
				}
				else if (SRP_P == aiSRP + 1)
				{
					cout << "YOU WIN!\n";
				}
				else if (SRP_P == aiSRP + 2)
				{
					cout << "YOU LOSE!\n";
				}
				break;
			case SRP_END:
				break;
			}
		break;
		}
	}
	return 0;
}