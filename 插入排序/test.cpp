#define _CRT_SECURE_NO_WARNINGS 1
//1.稳定性，排序排好之后和之前顺序一样是稳定的，反之亦然
//2.内部排序 小规模排序：插入排序 / 选择排序 /交换排序
//3.外部排序 大规模排序：归并排序
//4.
//#include<stdio.h>
//#include<stdlib.h>
#include<iostream>
using namespace std;
//void sort(int a[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		for (int j = 0; j < sz - i - 1 ; j++)
//		{
//			if (a[j + 1] < a[j])
//			{
//				int tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//}
//直接插入排序  稳定的排序  时间复杂度O(n^2)  空间复杂度O(1)
//适用场景：数据量比较小，接近有序
//void Insertsort(int* array,int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = array[i];
//		int end = i - 1;
//		//找待插入的位置  O(n)
//		while (end >= 0 && key < array[end])
//		{
//			array[end + 1] = array[end];
//			--end;
//		}
//		//插入数据
//		array[end + 1] = key;
//	}
//}
//int main()
//{
//	int arr[] = { 1,5,2,6,9,7,4,3,10 };
//	int size = sizeof(arr) / sizeof(int);
//	Insertsort(arr, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//目前数据场景： 数据量大，非常杂乱----按照插入数据思想进行排序

//希尔排序 不稳定
//gap = gap / 3 +1;这样性能比较好
//时间复杂度：O(N^1.25 - 1.6N^1.25)
//空间复杂度：O(1)
//由于多次插入排序，我们知道一次插入排序是稳定的，不会改变相同元素的相对顺序，但在不同的插入排序过程中，相同的元素可能在各自的插入排序中移动，最后其稳定性就会被打乱，所以shell排序是不稳定的。
//场景：数据量大  杂乱的排序
void Shellsort(int* array, int sz)
{
	int gap = sz; // 10  4  2  1
	//while (gap != gap / 3 + 1)
	while(gap > 1)
	{  
		gap = gap / 3 + 1;
		for (int i = gap; i < sz; i++)
		{
			int key = array[i];
			int end = i - gap;
			//找待插入的位置  O(n)
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			//插入数据
			array[end + gap] = key;
		}
	}
}
int main()
{
	int arr[] = { 1,5,2,6,9,7,4,3,10 };
	int size = sizeof(arr) / sizeof(int);
	Shellsort(arr, size);
	/*for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}*/
	for (auto i : arr)
	cout << i << endl;
	printf("\n");
	system("pause");
	return 0;
}