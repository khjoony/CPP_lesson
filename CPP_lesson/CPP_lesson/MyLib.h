#pragma once
#ifdef _MYLIB_H_
#define _MYLIB_H_

void CreateNum(int* pArr, int size);
void Shuffle(int* pArr, int iCol, int size);
void PrintNum(int* pArr, int iCol, int sizeTot);
void PrintNum(int* pArr, int size);
int UserInput(int* pArr, int size, int& iEnd);
void MaxStar(int* pArr, int sizeStar, int& max);
void AiInput(int* pArr1, int* pArr2, int iCol, int sizeTot);
void AiInput(int* pArr1, int* pArr2, int iCol, int sizeTot, int max);
void Compare(int* pArr1, int* pArr2,int* pStr, int size);
void Compare(int* pArr1, int* pArr2, int iCol, int sizeTot);
void MoveUp(Int* pArr, int iCol, int sizeTot);
void MoveDown(int* pArr, int iCol, int sizeTot);
void MoveLeft(int* pArr, int iCol, int sizeTot);
void MoveRight(int* pArr, int iCol, int sizeTot);
void Count(int* pArr1, int* pArr2 int iCol, int sizeTet, int& iCnt);

#endif