#define _CRT_SECURE_NO_WARNINGS 1
//—°‘Ò≈≈–Ú
#include<stdio.h>
#include<stdlib.h>
void swap(int*& x1, int*& x2)
{
	int tmp = x1;
	x1 = x2;
	x2 = tmp;
}
void SelectSort(int* array,int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		int maxPos = 0;
		for (int i = 1; i < size - j; i++)
		{
			if (array[i] > array[maxPos])
			{
				maxPos = i;
			}
		}
		swap(array[maxPos], array[size - j - 1]);
	}

}
int main()
{
	int array[] = { 1,2,5,6,4,9,7,8,12,16,13 };
	int size = sizeof(array) / sizeof(int);
	SelectSort(array, size);
	system("pause");
	return 0;
}
//∂—≈≈–Ú