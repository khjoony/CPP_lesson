// What is there a operator
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int iInput1, iInput2;
	double dInput1, dInput2;
	// 사칙연산
	// +,-,*,ㅗ,%
	// 연산의 우선순위는 () */  +- 관계연산  논리연산  대입연산(=)
	// 두개의 실수를 입력을 받아서 사칙연산을 실행해보자
	cout << "두개의 정수를 입력하세요: ";
	cin >> dInput1 >> iInput1 >> iInput2;
	
	cout << "dInput + iInput = " << dInput1 + iInput2 << endl;
	cout << "dInput / iInput = " << dInput1 / iInput2 << endl;
	cout << "dInput - iInput = " << dInput1 - iInput2 << endl;
	cout << "dInput * iInput = " << dInput1 * iInput2 << endl;
	cout << "dInput % iInput = " << iInput1 % iInput2 << endl;

	// 관계연산
	// >, < , >=, <= , != , ==
	cout << "dInput1 >  iInpput2 = " << (dInput1 > iInput2) << endl;
	cout << "dInput1 <  iInpput2 = " << (dInput1 < iInput2) << endl;
	cout << "dInput1 >= iInpput2 = " << (dInput1 >= iInput2) << endl;
	cout << "dInput1 <= iInpput2 = " << (dInput1 <= iInput2) << endl;
	cout << "dInput1 != iInpput2 = " << (dInput1 != iInput2) << endl;
	cout << "dInput1 ==iInpput2 = "  << (dInput1 == iInput2) << endl;
	// 논리연산
	// AND(&&) , OR(||), NOT(!)
	
	if (10 <= dInput1 and 20 >= dInput1)
	{
		cout << "입력되는 숫자는 10보다 크고 20보다 작아야 합니다.";
	}
	else
	{
		cout << " 입련된 숫자중의 하나 이상이 10보다 크고 20보다 작은 숫자입니다.";
	}

	return 0;
}