#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
//直接插入排序
void InsertSort(int* a,int n)
{
	//分为有序 和  无序两个区间
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int temp = end + 1;
		while (end >= 0)
		{
			if (a[end] > a[temp])
			{
				swap(a[end], a[temp]);
				temp--;
			}
			else
			{
				break;
			}
			end--;
		}
	}
}
//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int temp = end + gap;
			while (end >= 0)
			{
				if (a[end] > a[temp])
				{
					swap(a[end], a[temp]);
					temp -= gap;
				}
				else
				{
					break;
				}
				end -= gap;
			}
		}
	}
}

void PrintSort(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int a[10] = { 1,3,5,7,9,2,4,6,8,0 };
	int size = sizeof(a)/sizeof(int);
	//InsertSort(a, size);
	ShellSort(a, size);
	PrintSort(a, size);
	return 0;
}