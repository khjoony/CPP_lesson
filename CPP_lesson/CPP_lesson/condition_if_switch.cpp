// Condition if , switch, enum, while
#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;
enum UPGRADE{UPGRADE_1 = 1, UPGRADE_2, UPGRADE_3, UPGRADE_4, UPGRADE_5, UPGRADE_6, UPGRADE_7, UPGRADE_8, UPGRADE_9, UPGRADE_10, UPGRADE_11,
UPGRADE_12, UPGRADE_13, UPGRADE_14, UPGRADE_15};

int main()
{
	int iBuff;
	char cInput1, cInput2;

	const int iAttack = 0x00000001;
	const int iArmor = 0x00000002;
	const int iHP = 0x00000004;
	const int iMP = 0x00000008;
	const int iCritical = 0x00000010;

	iBuff = iAttack | iArmor | iHP | iCritical;

	// if condition
	if ((iBuff & iAttack) != 0)
	{
		cout << "It has a buff of Attack " << endl;
	}
	else {
		cout << "It hasn't a buff of Attack" << endl;
	}

	if ((iBuff & iArmor) != 0)
	{
		cout << "It has a buff of Armor " << endl;
	}

	if ((iBuff & iHP) != 0)
	{
		cout << "It has a buff of HP " << endl;
	}

	if ((iBuff & iMP) != 0)
	{
		cout << "It has a buff of MP " << endl;
	}
	else if ((iBuff & iMP) == 0) {
		cout << "It hasn't buff of MP" << endl;
	}
	if ((iBuff & iCritical) != 0)
	{
		cout << "It has a buff of Critical " << endl;
	}
	// Create a random value
	srand((unsigned int)time(0));
	int iUpgrade;
	float fPercent;
	cout << "Input Upgrade level what you want :";
	cin >> iUpgrade;

	cout << (rand() % 5 +100) << endl;
	fPercent = (rand() % 10000 / 100.f);
	cout << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "Congratulation" << endl;
	else if (4 <= iUpgrade && iUpgrade <= 7)
	{
		if (fPercent <= 40.f)
			cout << "Congratulation !" << endl;
		else
			cout << "Sorry !" << endl;
	}
	else if (8 <= iUpgrade && iUpgrade <= 10)
	{
		if (fPercent <= 10.f)
			cout << "Congratulation 2!" << endl;
		else
			cout << "Sorry !" << endl;
	}
	else if (11 <= iUpgrade && iUpgrade <= 13)
	{
		if (fPercent <= 1.f)
			cout << "Congratulation 3!" << endl;
		else
			cout << "Sorry !" << endl;
	}
	else if (14 <= iUpgrade && iUpgrade <= 15)
	{
		if (fPercent <= 0.1f)
			cout << "Congratulation 4!" << endl;
		else
			cout << "Sorry !" << endl;
	}

	// Switch Condition
	switch (iUpgrade)
	{
	case UPGRADE_1:
	case UPGRADE_2:
	case UPGRADE_3:
		cout << "The probability of upgrade is 100% " << endl;
		break;
	case UPGRADE_4:
	case UPGRADE_5:
	case UPGRADE_6:
	case UPGRADE_7:
		cout << "The probability of upgrade is 40% " << endl;
		break;
	case UPGRADE_8:
	case UPGRADE_9:
	case UPGRADE_10:
		cout << "The probability of upgrade is 10 % " << endl;
		break;
	case UPGRADE_11:
	case UPGRADE_12:
	case UPGRADE_13:
		cout << "The probability of upgrade is 1 % " << endl;
		break;
	case UPGRADE_14:
	case UPGRADE_15:
		cout << "The probability of upgrade is 0.1 % " << endl;
		break;
	}
	return 0;
}