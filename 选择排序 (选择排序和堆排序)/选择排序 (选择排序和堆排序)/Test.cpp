#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
using namespace std;
//—°‘Ò≈≈–Ú
// ±º‰∏¥‘”∂» «O£®N*N£©
void SelectSort(int *a, int n)
{
	int min_index = 0;
	int max_index = 0;
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[min_index])
				min_index = i;
			if (a[i] > a[max_index])
				max_index = i;
		}

		swap(a[left], a[min_index]);
		if (left == max_index)
			max_index = min_index;
		swap(a[right], a[max_index]);

		++left;
		--right;

		min_index = left;
		max_index = right;
	}
}
void AdjustDown(int* a,int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while(child < n)
	{
		if (child + 1 < n)
		{
			if (a[child] < a[child + 1])
				swap(a[child], a[child + 1]);
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//∂—≈≈–Ú
void HeapSort(int *a, int n)
{
	//Ω®¥Û∂—
	for (int i = (n-2)/2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	//≈≈–Ú
	int end = n - 1;
	while(end > 0)
	{
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void PrintSort(int *a,int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main()
{
	int array[9] = { 9,1,2,5,4,3,6,7,8 };
	int size = sizeof(array) / sizeof(int);
	SelectSort(array, size);
	//HeapSort(array, size);
	PrintSort(array, size);
	return 0;
}