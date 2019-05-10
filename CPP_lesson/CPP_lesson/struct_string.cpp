#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define NAME_SIZE  24


struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};
int main()
{
	char strName[NAME_SIZE] = {};
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};
	tStudent.iKor = 100;

	strcpy_s(tStudent.strName, "C");
	strcat_s(tStudent.strName, "++");
	cout << "Length of strName = " << strlen(tStudent.strName) << endl;
	cout << "Input language to find, Please : ";
	cin >> strName;
	
	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "Find it !!" << endl;
	}
	else
		cout << "There it isn't!" << endl;

	cout << setw(10) << "name : " << tStudent.strName << endl;
	cout << setw(10) << "number : " << tStudent.iNumber << endl;
	cout << setw(10) << "Kor : " << tStudent.iKor << endl;
	cout << setw(10) << "Eng : " << tStudent.iEng << endl;
	cout << setw(10) << "Math : " << tStudent.iMath << endl;
	cout << setw(10) << "Total : " << tStudent.iTotal << endl;


	return 0;
}