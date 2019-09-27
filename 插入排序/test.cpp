#define _CRT_SECURE_NO_WARNINGS 1
//1.�ȶ��ԣ������ź�֮���֮ǰ˳��һ�����ȶ��ģ���֮��Ȼ
//2.�ڲ����� С��ģ���򣺲������� / ѡ������ /��������
//3.�ⲿ���� ���ģ���򣺹鲢����
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
//ֱ�Ӳ�������  �ȶ�������  ʱ�临�Ӷ�O(n^2)  �ռ临�Ӷ�O(1)
//���ó������������Ƚ�С���ӽ�����
//void Insertsort(int* array,int sz)
//{
//	for (int i = 1; i < sz; i++)
//	{
//		int key = array[i];
//		int end = i - 1;
//		//�Ҵ������λ��  O(n)
//		while (end >= 0 && key < array[end])
//		{
//			array[end + 1] = array[end];
//			--end;
//		}
//		//��������
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
//Ŀǰ���ݳ����� �������󣬷ǳ�����----���ղ�������˼���������

//ϣ������ ���ȶ�
//gap = gap / 3 +1;�������ܱȽϺ�
//ʱ�临�Ӷȣ�O(N^1.25 - 1.6N^1.25)
//�ռ临�Ӷȣ�O(1)
//���ڶ�β�����������֪��һ�β����������ȶ��ģ�����ı���ͬԪ�ص����˳�򣬵��ڲ�ͬ�Ĳ�����������У���ͬ��Ԫ�ؿ����ڸ��ԵĲ����������ƶ���������ȶ��Ծͻᱻ���ң�����shell�����ǲ��ȶ��ġ�
//��������������  ���ҵ�����
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
			//�Ҵ������λ��  O(n)
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			//��������
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