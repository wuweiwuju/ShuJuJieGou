#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
//1.��������
//ֱ�Ӳ�������
//ʱ�临�Ӷ� 1+2+3+4+...+n  O(n^2)
//��ã�˳������  ���O(n) �������  O(n^2)
//�ռ临�Ӷ� O(1)
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
//ϣ������
//��Ԥ���� -- �ӽ���˳������
//��������

//2.ѡ������
//ѡ������
//�������������O(n^2)
//������

//3.��������
//ð������
//��������

//4.�鲢����
//�鲢����