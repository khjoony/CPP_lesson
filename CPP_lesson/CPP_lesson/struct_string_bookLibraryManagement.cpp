// Book Library Management
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum BOOKMAX {BOOK = 1000, NAME = 25, DESCRIPTION = 500 };
enum MENU {MENU_EXIT, MENU_CREATE, MENU_READ, MENU_UPDATE, MENU_SEARCH, MENU_DELETE };
enum ITEM { ITEM_PRICE = 1, ITEM_RENTAL };

struct _Book {
	long lID;
	char strName[NAME];
	char strAuthor[NAME];
	char strPubli[NAME];
	char strNation[NAME];
	char strDescript[DESCRIPTION];
	int iPrice;
	int bRental;
};

void PrintAll(int iBookCnt, _Book _book[]);
void Print(int iExistID, _Book _book[]);
long Search(char strNameUpdate[],long iSelectID, int iBookCount, _Book _book[]);
void Update(long iSelectedID, _Book _book[]);
void Delete(int iExistID, int& iBookCount, _Book _book[]);
int main()
{
	_Book _book[BOOK] = {};
	int iBookCount = 0;
	int iBookID = 1;
	while (true)
	{
		cout << "0: EXIT" << endl;
		cout << "1: CREATE" << endl;
		cout << "2: READ" << endl;
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
		cin.ignore(INT_MAX, '\n');
		long iSelectID = 0, iExistID = 0;

		switch (iMenu)
		{
		case MENU_CREATE:
			system("cls");
			cout << "================ Create a student info ================" << endl;
			if (iBookCount == BOOK)
			{
				cout << "Can't add a book any more.";
				break;
			}
			cout << "Book Name : ";	cin.getline( _book[iBookCount].strName, NAME-1);
			_book[iBookCount].lID = iBookID;
			//cin.ignore(NAME, '\n');
			cout << "Author : ";	cin.getline(_book[iBookCount].strAuthor, NAME-1);
			cout << "Dedcription : ";	cin.getline(_book[iBookCount].strDescript, DESCRIPTION);
			//cin.ignore(DESCRIPTION, '\n');
			cout << "Publisher : ";		cin.getline(_book[iBookCount].strPubli, NAME-1);
			//cin.ignore(NAME, '\n');
			cout << "Nation : ";	cin.getline(_book[iBookCount].strNation, NAME-1);
			//cin.ignore(NAME, '\n');
			cout << "Price :";  cin >> _book[iBookCount].iPrice;
			while (true)
			{
				cout << "IsRental [1: yes, 0: no] :"; cin >> _book[iBookCount].bRental;
				if (_book[iBookCount].bRental == 1 || _book[iBookCount].bRental == 0)
				{
					break;
				}
				else {
					cout << "It's wrong number !" << endl;
					continue;
				}
			}
			cout.setf(ios::left);
			++iBookID;
			++iBookCount;


			break;
		case MENU_READ:
			system("cls");
			PrintAll(iBookCount, _book);

			break;
		case MENU_UPDATE:
			system("cls");
			char strNameUpdate[NAME];

			while (true)
			{
				system("cls");
				cout << "================ Update a student info ================" << endl;
				cout << "Book Name : ";  cin.getline(strNameUpdate, NAME-1);
				cout << "ID : ";		cin >> iSelectID;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
				}
				iExistID = Search(strNameUpdate, iSelectID, iBookCount, _book);

				Update(iExistID, _book);

				cout << "Do you keep updating? [y: Continue, n: Exit] : ";
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
				cout << "BookName : "; cin >> strNameSearch;
				cout << "ID : "; cin >> iSelectID;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "It's wrong ! Try again !\n";
					continue;
				}

				iExistID = Search(strNameSearch, iSelectID, iBookCount, _book);
				Print(iExistID, _book);
				cout << endl << "Do you looking for ohter book's info again?  " << endl;
				cout << "[Y | y] : Researching" << endl;
				cout << "[N | n] : Exit" << endl;
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
				iExistID = Search(strNameDelete, iSelectID, iBookCount, _book);
				if (iExistID == 0)
				{
					char cYorN;
					cout << "It is not exist book.\n";
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
					Delete(iExistID, iBookCount, _book);
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
	return 0;
}

void PrintAll(int iBookCnt, _Book _book[])
{
	for (int i = 0; i < iBookCnt; ++i)
	{

		cout << "================ Readding a student info [" << i + 1 << "] ================" << endl;
		cout << setw(25) << "Name" << ": " << _book[i].strName << endl;
		cout << setw(25) << "BookID" << ": " << _book[i].lID << endl;
		cout << setw(25) << "Author" << ": " << _book[i].strAuthor << endl;
		cout << setw(25) << "Description" << ": " << _book[i].strDescript << endl;
		cout << setw(25) << "Publisher" << ": " << _book[i].strPubli << endl;
		cout << setw(25) << "Nation" << ": " << _book[i].strNation << endl;
		cout << setw(25) << "Rental Price" << ": " << _book[i].iPrice << endl;
		if (_book[i].bRental == 1)
		{
			cout << setw(25) << "Rental status" << ": " << "On loan" << endl;
		}
		else if (_book[i].bRental == 0)
		{
			cout << setw(25) << "Loan status" << ": " << "Rentable" << endl;
		}
	}
}

void Print(int iExistID, _Book _book[])
{
	int iNum = iExistID - 1;
		cout << "================ Readding a student info [" << iNum + 1 << "] ================" << endl;
		cout << setw(25) << "Name" << ": " << _book[iNum].strName << endl;
		cout << setw(25) << "BookID" << ": " << _book[iNum].lID << endl;
		cout << setw(25) << "Author" << ": " << _book[iNum].strAuthor << endl;
		cout << setw(25) << "Description" << ": " << _book[iNum].strDescript << endl;
		cout << setw(25) << "Publisher" << ": " << _book[iNum].strPubli << endl;
		cout << setw(25) << "Nation" << ": " << _book[iNum].strNation << endl;
		cout << setw(25) << "Rental Price" << ": " << _book[iNum].iPrice << endl;
		if (_book[iNum].bRental == 1)
		{
			cout << setw(25) << "Rental status" << ": " << " On loan" << endl;
		}
		else if (_book[iNum].bRental == 0)
		{
			cout << setw(25) << "Loan status" << ": " << " Rentable" << endl;
		}

}

long Search(char strNameUpdate[], long iSelectID, int iBookCount, _Book _book[])
{
	long lSelectedID;
	int isExist = 0;
	for (int i = 0; i < iBookCount; ++i)
	{
		if (strcmp(strNameUpdate, _book[i].strName) == 0 && iSelectID == _book[i].lID)
		{
			lSelectedID = _book[i].lID;
			isExist = 1;
		}
	}
	if (isExist == 1)
		return lSelectedID;
	else if (isExist == 0)
		return 0;
}

void Update(long iSelectedID, _Book _book[])
{
	while (true)
	{
		system("cls");
		int iItem = NULL;
		cout << "1: Price" << endl;
		cout << "2: IsRental" << endl;
		cout << "Select a item to update :"; cin >> iItem;


		switch (iItem)
		{
		case ITEM_PRICE:
			cout << "New Price :";  cin >> _book[iSelectedID - 1].iPrice;
			cout << endl << "Changed Price : " << _book[iSelectedID - 1].iPrice << endl;
			break;
		case ITEM_RENTAL:
			cout << "IsRental ? [1: yes, 0: no] :";  cin >> _book[iSelectedID - 1].bRental;
			cout << endl << "Changed IsRental : " << _book[iSelectedID - 1].bRental << endl;
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


void Delete(int iExistID, int& iBookCount, _Book _book[])
	{
		cout << "Deleted " << _book[iExistID].strName << "'s data. \n";
		for (int i = iExistID; i < iBookCount; ++i)
		{
			_book[i] = _book[i + 1];
		}
		--iBookCount;

	}

