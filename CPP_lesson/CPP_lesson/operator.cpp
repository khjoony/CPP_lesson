// What is there a operator
#include <iostream>
#include <string>

using namespace std;
int main()
{
	int iInput1, iInput2;
	double dInput1, dInput2;
	// ��Ģ����
	// +,-,*,��,%
	// ������ �켱������ () */  +- ���迬��  ������  ���Կ���(=)
	// �ΰ��� �Ǽ��� �Է��� �޾Ƽ� ��Ģ������ �����غ���
	cout << "�ΰ��� ������ �Է��ϼ���: ";
	cin >> dInput1 >> iInput1 >> iInput2;
	
	cout << "dInput + iInput = " << dInput1 + iInput2 << endl;
	cout << "dInput / iInput = " << dInput1 / iInput2 << endl;
	cout << "dInput - iInput = " << dInput1 - iInput2 << endl;
	cout << "dInput * iInput = " << dInput1 * iInput2 << endl;
	cout << "dInput % iInput = " << iInput1 % iInput2 << endl;

	// ���迬��
	// >, < , >=, <= , != , ==
	cout << "dInput1 >  iInpput2 = " << (dInput1 > iInput2) << endl;
	cout << "dInput1 <  iInpput2 = " << (dInput1 < iInput2) << endl;
	cout << "dInput1 >= iInpput2 = " << (dInput1 >= iInput2) << endl;
	cout << "dInput1 <= iInpput2 = " << (dInput1 <= iInput2) << endl;
	cout << "dInput1 != iInpput2 = " << (dInput1 != iInput2) << endl;
	cout << "dInput1 ==iInpput2 = "  << (dInput1 == iInput2) << endl;
	// ������
	// AND(&&) , OR(||), NOT(!)
	
	if (10 <= dInput1 and 20 >= dInput1)
	{
		cout << "�ԷµǴ� ���ڴ� 10���� ũ�� 20���� �۾ƾ� �մϴ�.";
	}
	else
	{
		cout << " �Էõ� �������� �ϳ� �̻��� 10���� ũ�� 20���� ���� �����Դϴ�.";
	}

	return 0;
}