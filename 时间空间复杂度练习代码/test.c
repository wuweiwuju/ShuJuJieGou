#define _CRT_SECURE_NO_WARNINGS 1
//¿Õ¼ä»»Ê±¼ä
#include<stdio.h>
#include<stdlib.h>
void search(int a[], int len)
{
	int sp[1000] = { 0 };
	int i = 0;
	int max = 0;
	for (i = 0; i < len; i++)
	{
		int index = a[i] - 1;
		sp[index]++;
	}
	for (i = 0; i < 1000; i++)
	{
		if (max < sp[i])
		{
			max = sp[i];
		}
	}
	for (i = 0; i < 1000; i++)
	{
		if (max == sp[i])
		{
			printf("%d\n", i + 1);
		}
	}

}
int main()
{
	int array[] = { 1,5,3,3,4,5,6,99,99,99,3,3,3 };
	int size = sizeof(array) / sizeof(int);
	search(array, size);
	system("pause");
	return 0;
}