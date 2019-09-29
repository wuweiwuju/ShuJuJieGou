#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
//1.插入排序
//直接插入排序
//时间复杂度 1+2+3+4+...+n  O(n^2)
//最好：顺序有序  最好O(n) 逆序最坏：  O(n^2)
//空间复杂度 O(1)
//#include<stdio.h>
//void InsertSort(int* a, int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + 1] = tmp;
//	}
//}
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int array[] = { 2,5,1,8,6,9,3,4,7 };
//	InsertSort(array, sizeof(array)/sizeof(int));
//	PrintArray(array, sizeof(array) / sizeof(int));
//	return 0;
//}
//希尔排序
//先预排序 -- 接近于顺序有序
//插入排序

//2.选择排序
//选择排序
//最好最坏的情况都是O(n^2)
//堆排序

//3.交换排序
//冒泡排序
//快速排序

//4.归并排序
//归并排序