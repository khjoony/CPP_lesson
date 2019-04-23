// Bitwise logical operation in binary, octal, decimal, hexadecimal.
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
	int iInput1, iInput2;
	double dInput1, dInput2;

	/* 
	Octal  -> Binary -> Hexadecimal
	87 / 2 = 43 --1
	43 / 2 = 21 --1
	21 / 2 = 10 --1
	10 / 2 =  5 --0
	5  / 2 =  2 --1
	2  / 2 =  1 --0

	64 +0  +16 +0  +4  +2  +1 = 87  (decimal)
	1   0   1   0   1   1   1
    4  +0  +1 |	0  +4  +2  +1
	        5             +7  = 57  (hexadecimal)
	*/

	/* Bitwise logical operation
	 AND(&), OR(|), NOT(!), XOR(^)
	A   B  AND  OR  NOT(AND)  XOR
	0   0    0   0         1    0
	1   0    0   1         1    1
	0   1    0   1         1    1
	1   1    1   1         0    0

	83 -> binary -> 1010111
	 &              0010101  -> decimal -> 21    
	53 -> binary  ->0110101

	83 -> binary -> 1010111
	 |              1110111  -> decimal -> 119
	53 -> binary  ->0110101
	*/
	cout << "87 & 53 = " << (87 & 53) << endl;
	cout << "87 | 53 = " << (87 | 53) << endl;

	// Constants are expressions with a fixed value.
	// Because, must be assigned the value concurrently with the declaration.
	//        Buff       hexadecimal       binary
	const int iAttack   = 0x00000001;   // 00000001
	const int iArmor    = 0x00000002;   // 00000010
	const int iHP       = 0x00000004;   // 00000100
	const int iMP       = 0x00000008;   // 00001000
	const int iCritical = 0x00000010;   // 00010000

	int iBuff = iAttack | iHP | iCritical;	 // 00010101  <- OR (add buff)
	cout <<setw(12) << "Attack : "   << setw(4) << (iBuff & iAttack)   << endl;
	cout <<setw(12) << "Armor : "    << setw(4) << (iBuff & iArmor)    << endl;
	cout <<setw(12) << "HP : "       << setw(4) << (iBuff & iHP)       << endl;
	cout <<setw(12) << "MP : "       << setw(4) << (iBuff & iMP)       << endl;
	cout <<setw(12) << "Critical : " << setw(4) << (iBuff & iCritical) << endl;

	iBuff ^= iHP;     // 10101   XOR  00100 = 10001  ( subtract HP buff)
	iBuff ^= iHP;     // 10001   XOR  00100 = 10101  ( add HP buff)

	/* Shift operator
	                       << 2     << 3       <<4    (multiply)
	binary       10100     1010000   10100000   101000000
	decimal         20          80        160         320

	                       >> 2     >> 3       >> 4   (division)
	binary       10100     00101   00010   00001
	decimal         20         5       2       1
	*/

	int iHigh = 187;
	int iLow = 13560;
	int iTotal = iHigh; // 0000 0000 0000 0000 0000 0000 1011 1011
	iTotal <<= 16;      // 0000 0000 1011 1011 0000 0000 0000 0000
	iTotal |= iLow;     // 0000 0000 1011 1011 0011 0100 1111 1000

	cout << "High : " << (iTotal >> 16) << endl;
	cout << "Low : " << (iTotal & 0x0000ffff) << endl;

	// Increase , Decrease operator
	// transposition
	cout << setw(14) << "--iTotal : " << --iTotal << endl;
	cout << setw(14) << "iTotal : " << iTotal << endl;
	cout << setw(14) << "++iTotal : " << ++iTotal << endl;
	cout << setw(14) << "iTotal : " << iTotal << endl;
	// post 
	cout << setw(14) << "iTotal-- : " << iTotal-- << endl;
	cout << setw(14) << "iTotal : " << iTotal << endl;
	cout << setw(14) << "iTotal++ : " << iTotal++ << endl;
	cout << setw(14) << "iTotal : " << iTotal << endl;
	


	// post

	return 0;
}