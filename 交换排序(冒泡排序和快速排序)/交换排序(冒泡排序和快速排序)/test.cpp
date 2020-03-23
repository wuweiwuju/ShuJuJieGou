#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
void InsertSort(int* array, int sz)
{
	for (int i = 1; i < sz; i++)
	{
		int key = array[i];
		int end = i - 1;
		//�Ҵ������λ��  O(n)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			--end;
		}
		//��������
		array[end + 1] = key;
	}
}

//ð������
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		//����ð��
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
				swap(a[i - 1], a[i]);
		}
		--end;
	}
}
//��������
//�����ʱ��ʱ��Ч����� O��N*N��
//�Ż�����
//1.����ȡ��
/*int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[right] < a[mid])
			return mid;
		else if (a[right] < a[left])
			return left;
		else
			return right;
	}
}*/
int GetMidIndex(int* input, int left, int right)
{
	int mid = (left + right) / 2;
	if (input[left] < input[mid])
	{
		if (input[right] > input[mid])
		{
			return mid;
		}
		else
		{
			if (input[left] > input[right])
				return left;
			else
				return right;
		}
	}
	else
	{
		if (input[right] < input[mid])
		{
			return mid;
		}
		else
		{
			if (input[left] < input[right])
				return left;
			else
				return right;
		}
	}
}
//����ָ�뷨
int PartSort1(int* a, int left,int right)
{
	//int mid = GetMidIndex(a, left, right);
	//swap(a[mid], a[right]);
	int key = a[right];
	//������¼Ҫ������λ��
	int keyindex = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;

		while (left < right && a[right] >= key)
			right--;

		if (left < right)
			swap(a[left], a[right]);
	}
	//����һ��������key�����˺����ͻ�����
	swap(a[left], a[keyindex]);
	return left;
}

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);
	int key = a[right];
	int keyindex = right;
	while (left < right)
	{
		//����Ҵ�ŵ��ұߵĿ�
		while (left < right && a[left] <= key)
		{
			++left;
		}
		if (left < right)
		{
			a[right] = a[left];
			keyindex = left;
		}
		//�ұ���С���ŵ���ߵĿ�
		while (left < right && a[right] >= key)
		{
			--right;
		}
		if (left < right)
		{
			a[left] = a[right];
			keyindex = right;
		}
	}
	swap(a[keyindex], a[keyindex]);
	return keyindex;
}
//ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	swap(a[mid], a[right]);
	int key = a[right];
	int cur = left;
	int prev = cur - 1;
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
			swap(a[prev], a[cur]);

		++cur;
	}
	++prev;
	swap(a[prev], key);
	return prev;
}
//�Ż� 2.
//�ݹ�
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return; 


		//int keyindex = PartSort1(a, left, right);
		//int keyindex = PartSort2(a, left, right);
		int keyindex = PartSort1(a, left, right);
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
}
//�ǵݹ�
void QuickSortNonR(int* a, int left, int right)
{
	stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();

		int keyindex = PartSort3(a, begin, end);

		if (keyindex - 1 > begin)
		{
			s.push(begin);
			s.push(keyindex - 1);
		}

		if (keyindex + 1 < end)
		{
			s.push(keyindex + 1);
			s.push(end);
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
	int array[8] = { 4,5,1,6,2,7,3,8 };
	int size = sizeof(array) / sizeof(int);
	//BubbleSort(array, size);
	QuickSort(array, 0, 7);
	//QuickSortNonR(array, 0, 9);
	PrintSort(array, size);
	return 0;
}