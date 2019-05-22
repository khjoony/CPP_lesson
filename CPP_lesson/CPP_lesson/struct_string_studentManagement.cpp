
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum MAX	 {NAME = 16, ADDR = 128, PHONE = 14, STUDENT = 10};
enum MENU	 {MENU_EXIT, MENU_CREATE, MENU_READ, MENU_UPDATE, MENU_SEARCH, MENU_DELETE};
enum ITEM  	{ITEM_ADDR = 1, ITEM_PHONE, ITEM_MARK};

struct _Name {
	char strfName[NAME], strmName[NAME], strlName[NAME];
};
struct _Mark {
	float fKor, fEng, fMath, fTotal , fAvg;
};

struct _Student {
	_Name _name;
	_Mark _mark;
	long lId;
	char strAddr[ADDR];
	char strPhonNumber[PHONE];
};



long Search(char strName[], int iSelectID, int iStudentCnt, _Student _std[]);
void PrintAll(int iStudentCnt, _Student _std[]);
void Print(int iExistID, _Student _student[]);
void Update(long lSelectedID, _Student _std[]);
void Delete(int iExistID, int& iStudentCount, _Student _student[]);
int main()
{
	_Student _student[STUDENT] = {};
	int iStudentCount = 0;
	int iStudentID = 1;
	while (true)
	{
		cout << "0: EXIT"	<< endl;
		cout << "1: CREATE" << endl;
		cout << "2: READ"	<< endl;
		cout << "3: UPDATE" << endl;
		cout << "4: SEARCH" << endl;
		cout << "5: DELETE" << endl; 
		cout << "Select number of menu : ";
		int iMenu;
		cin >> iMenu;
		if (cin.fail())
		{
			cin.clear();

			cin.ignore(INT_MAX, '\n');

			system("cls");

			cout << "It's wrong !! Try again.\n";

			continue;
		}
		if (iMenu == MENU_EXIT)
		{
			break;
		}
		long iSelectID = 0, iExistID = 0;

		switch (iMenu)
		{
		case MENU_CREATE:
			system("cls");
			cout << "================ Create a student info ================" << endl;
			if (iStudentCount == STUDENT)
			{
				cout << "Can't add a student any more.";
				break;
			}
			cout << "First Name : ";	cin >> _student[iStudentCount]._name.strfName;
			cout << "Middle Name : ";	cin >> _student[iStudentCount]._name.strmName;
			cout << "Last Name : ";		cin >> _student[iStudentCount]._name.strlName;
			cin.ignore(INT_MAX, '\n');
			cout << "Address : ";		cin.getline(_student[iStudentCount].strAddr, ADDR);
			cout << "Phone Number : ";	cin >> _student[iStudentCount].strPhonNumber;
			cout << "Korean : ";		cin >> _student[iStudentCount]._mark.fKor;
			cout << "English : ";		cin >> _student[iStudentCount]._mark.fEng;
			cout << "Mathmatics : ";	cin >> _student[iStudentCount]._mark.fMath;
			_student[iStudentCount].lId = iStudentID;
			_student[iStudentCount]._mark.fTotal = _student[iStudentCount]._mark.fKor
				+ _student[iStudentCount]._mark.fEng
				+ _student[iStudentCount]._mark.fMath;
			_student[iStudentCount]._mark.fAvg = _student[iStudentCount]._mark.fTotal / 3.f;
			cout.setf(ios::left);
			++iStudentID;
			++iStudentCount;


			break;
		case MENU_READ:
			system("cls");
			PrintAll(iStudentCount, _student);

			break;
		case MENU_UPDATE:
			system("cls");
			char strNameUpdate[NAME];

			while (true)
			{
				system("cls");
				cout << "================ Update a student info ================" << endl;
				cout << "FirstName : ";  cin >> strNameUpdate;
				cout << "ID : ";		cin >> iSelectID;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				iExistID = Search(strNameUpdate, iSelectID, iStudentCount, _student);

				Update(iExistID, _student);

				cout << "Do you keep updating? [y: Continue, n: Exit select student] : ";
				char cYorN;
				cin >> cYorN;
				switch (cYorN)
				{
				case 'y':
				case 'Y':
					continue;
				case 'n':
				case 'N':
					break;
				}
				break;
			}
			break;
		case MENU_SEARCH:
			system("cls");
			char strNameSearch[NAME];

			while (true)
			{
				system("cls");
				cout << "================ Searching a student info ================" << endl;
				cout << "FirstName : "; cin >> strNameSearch;
				cout << "ID : "; cin >> iSelectID;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "It's wrong ! Try again !\n";
					continue;
				}

				iExistID = Search(strNameSearch, iSelectID, iStudentCount, _student);
				Print(iExistID, _student);
				cout << endl << "Do you looking for ohter student's info again?  " << endl;
				cout << "[Y | y] : Researching" << endl;
				cout << "[N | n] : Exit searching" << endl;
				char cYorN;
				cout << "Input : ";  cin >> cYorN;
				switch (cYorN)
				{
				case 'Y':
				case 'y':
					continue;
				case 'N':
				case 'n':
					break;
				}
				break;
			}
			break;
		case MENU_DELETE:
			system("cls");
			char strNameDelete[NAME];

			while (true)
			{
				system("cls");
				cout << "================ Update a student info ================" << endl;
				cout << "FirstName : ";  cin >> strNameDelete;
				cout << "ID : ";		cin >> iSelectID;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				iExistID = Search(strNameDelete, iSelectID, iStudentCount, _student);
				if (iExistID == 0)
				{
					char cYorN;
					cout << "It is not exist student.\n";
					cout << "Y : Continue,  N : Exit : ";
					cin >> cYorN;
					switch (cYorN)
					{
					case 'Y':
					case 'y':
						continue;
					case 'N':
					case 'n':
						break;
					}
				}
				else {
					Delete(iExistID, iStudentCount, _student);
				}
				break;
			}
			break;
		default:
			cout << "It's wrong number.  Try again~";
			break;
		}
		system("pause");
		system("cls");
	}
	cout << " MAX.NAME =" << ADDR << endl;
	return 0;
}

long Search(char* strName, int iSelectID, int iStudentCnt, _Student _std[])
{
	long lSelectedID;
	int isExist = 0;
	for (int i = 0; i < iStudentCnt; ++i)
	{
		if (strcmp(strName ,_std[i]._name.strfName) == 0 && iSelectID == _std[i].lId)
		{
			lSelectedID = _std[i].lId;
			isExist = 1;
		}
	}
	if (isExist == 1)
		return lSelectedID;
	else if (isExist == 0)
		return 0;
}

void Print(int iExistID, _Student _student[])
{
	int iNum = iExistID - 1;
	cout << setw(25) << "Name" << ": " << _student[iNum]._name.strfName << " "
		<< _student[iNum]._name.strmName << " " << _student[iNum]._name.strlName << endl;
	cout << setw(25) << "StudentID" << ": " << _student[iNum].lId << endl;
	cout << setw(25) << "Address" << ": " << _student[iNum].strAddr << endl;
	cout << setw(25) << "Phone Number" << ": " << _student[iNum].strPhonNumber << endl;
	cout << setw(25) << "Korean" << ": " << _student[iNum]._mark.fKor << endl;
	cout << setw(25) << "EngliNumsh" << ": " << _student[iNum]._mark.fEng << endl;
	cout << setw(25) << "MathmatiNumcs" << ": " << _student[iNum]._mark.fMath << endl;
	cout << setw(25) << "Total" << ": " << _student[iNum]._mark.fTotal << endl;
	cout << setw(25) << "Average" << ": " << _student[iNum]._mark.fAvg << endl;
}


void PrintAll(int iStudentCount, _Student _student[])
{
	for (int i = 0; i < iStudentCount; ++i)
	{

		cout << "================ Readding a student info [" << i + 1 << "] ================" << endl;
		cout << setw(25) << "Name" << ": " << _student[i]._name.strfName << " "
			<< _student[i]._name.strmName << " " << _student[i]._name.strlName << endl;
		cout << setw(25) << "StudentID" << ": " << _student[i].lId << endl;
		cout << setw(25) << "Address" << ": " << _student[i].strAddr << endl;
		cout << setw(25) << "Phone Number" << ": " << _student[i].strPhonNumber << endl;
		cout << setw(25) << "Korean" << ": " << _student[i]._mark.fKor << endl;
		cout << setw(25) << "English" << ": " << _student[i]._mark.fEng << endl;
		cout << setw(25) << "Mathmatics" << ": " << _student[i]._mark.fMath << endl;
		cout << setw(25) << "Total" << ": " << _student[i]._mark.fTotal << endl;
		cout << setw(25) << "Average" << ": " << _student[i]._mark.fAvg << endl;
	}
}

void Update(long iSelectedID, _Student _std[])
{
	while (true)
	{
		system("cls");
		int iItem = NULL;
		cout << "1: Address" << endl;
		cout << "2: Phone Number" << endl;
		cout << "3: Mark" << endl;
		cout << "Select a item to update :"; cin >> iItem;

	
		switch (iItem)
		{
		case ITEM_ADDR:
			cout << "New address :";  cin.ignore(INT_MAX, '\n');
			cin.getline(_std[iSelectedID - 1].strAddr, ADDR);
			cout << endl << "Changed address : " << _std[iSelectedID - 1].strAddr << endl;
			break;
		case ITEM_PHONE:
			cout << "New phone number :"; cin >> _std[iSelectedID - 1].strPhonNumber;
			cout << endl << "Changed phone number : " << _std[iSelectedID - 1].strPhonNumber << endl;
			break;
		case ITEM_MARK:
			cout << "New mark of Korean :"; cin >> _std[iSelectedID - 1]._mark.fKor;
			cout << "New mark of English :"; cin >> _std[iSelectedID - 1]._mark.fEng;
			cout << "New mark of Mathmatics :"; cin >> _std[iSelectedID - 1]._mark.fMath;
			cout << endl << "Changed mark : " << endl
				<< "Korean :" << _std[iSelectedID - 1]._mark.fKor
				<< "English :" << _std[iSelectedID - 1]._mark.fEng
				<< "Mathmatics :" << _std[iSelectedID - 1]._mark.fMath << endl;
			break;
		default:
			break;
		}
		cout << "Do you keep updating other item? [y: Continue, n: Exit item] ";
		char cYorN;
		cin >> cYorN;
		switch (cYorN)
		{
		case 'y':
		case 'Y':
			continue;
		case 'n':
		case 'N':
			break;
		}
		break;
	}
}


void Delete(int iExistID, int& iStudentCount, _Student _student[])
{
	cout << "Deleted " << _student[iExistID]._name.strfName << "'s data. \n";
		for (int i = iExistID; i < iStudentCount; ++i)
		{
			_student[i] = _student[i + 1];
		}
		--iStudentCount;

}