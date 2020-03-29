#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1.��������
//��1��ֱ�Ӳ�������
//˼�룺��Ϊ�������䣬һ��������һ��������
//�������N����  ��һ������ [0,0]  ���� [1,N-1]
//�Դ����ƽ�����������β��뵽���������
void InsertSort(vector<int>& temp)
{
	if (temp.size() == 0)
		return;

	int i, j, key;
	for (i = 1; i < temp.size(); ++i)
	{
		//����Ҫ���������
		key = temp[i];
		//���������жϣ����ν���key���ֵ����Ųһλ
		for (j = i - 1; j >= 0 && key < temp[j]; --j)
		{
			temp[j + 1] = temp[j];
		}
		//�����������
		temp[j + 1] = key;
	}
}
//�ɴ˿ɼ�ֱ�Ӳ����������ʱ�临�Ӷ�ΪO(N*N) 
//��õ�����ʱ�临�ӶȾ��������������O(N)
//�ռ临�Ӷ�ΪO(N) ���ȶ���

//��2��ϣ������
//���������֪����������ֻ�е�����������״���������ʱ�临�Ӷ�����͵�
//�ɴ�����������ϣ�����򣬶���һ��Ԥ�����ڽ���ֱ�Ӳ������򣬿����ṩЧ��
//˼�룺���ǿ�����һ��gap����ÿһ�β���ļ�࣬��gapΪ1��ʱ��ʹ����������
void ShellSort(vector<int>& temp)
{
	int gap = temp.size();
	while (gap > 1)
	{
		//����������10����
		//gap = 10  4  2  1
		gap =  gap/3 + 1;

		int i, j, key;
		for (i = gap; i < temp.size(); ++i)
		{
			key = temp[i];
			for (j = i - gap; j >= 0 && key < temp[j]; j-=gap)
			{
				temp[j + gap] = temp[j];
			}
			temp[j + gap] = key;
		}
	}
}
//���п��Կ���ϣ�������ǽ�����Ԥ����Ȼ���ڽ���ֱ�Ӳ�������
//������������gap �������ǲ��ȶ��ģ���ʱ�临�Ӷ��Ǳ�O��N*N��ҪС��
//�ռ临�Ӷ���O��1��

//2.ѡ������
//��1��.ѡ�������˼�룺ÿ����δ������������ҳ���С�ĺ�δ��������ĵ�һ�����н���
//8 2 1 3 8 0 7
//��һ������֮�� 0 2 1 3 8 8 7
//�ɼ����ǲ��ȶ��������㷨
void SelectSort(vector<int>& temp)
{
	if (temp.size() == 0)
		return;
	int i = 0;
	int j = temp.size();
	int max = 0;
	while (j)
	{
		max = j - 1;
		for (i = j - 2; i > 0; --i)
		{
			if (temp[max] < temp[i])
				max = i;
		}
		if(max != 0)
			swap(temp[max], temp[j - 1]);

		--j;
	}
}
//��֪��ʱ�临�Ӷ���O(N*N)�ռ临�Ӷ���O(N)

//(2)�������˼�룺�������Ƚ�һ�����Ȼ����ڵ�����һ�������н����������µ���
//�Դ����ƣ���������ˡ�
//   6 
// 1   3
//       1
//��������Կ�����6��1�����˽��� 1 �� 1 ��˳�����˱仯���Զ������ǲ��ȶ���
void AdjustDown(vector<int>& temp, int size, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size)
		{
			if (temp[child] < temp[child + 1])
				swap(temp[child], temp[child + 1]);
		}
		if (temp[child] > temp[parent])
		{
			swap(temp[child], temp[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(vector<int>& temp)
{
	int n = temp.size();
	for (int i = (n - 2) / 2; i >= 0; --i)
		AdjustDown(temp, n, i);

	int end = temp.size() - 1;
	while (end > 0)
	{
		swap(temp[0], temp[end]);
		AdjustDown(temp, end, 0);
		--end;
	}
}
//���Կ��������ŵ�ʱ�临�Ӷ���O��N*logN���ռ临�Ӷ���O��1��

//3.��������
//��1��ð�������˼�룺һ������N���������飬���������Ƚ�
//�ȱȽ�N-1�Σ���������ͽ�����������棬Ȼ��������ð������N-2
//ֱ��ʣһ������
//1 3 1 7 2 9
//1 1 3 2 7 9
//�ɼ������ȶ���
void BubbleSort(vector<int>& temp)
{
	if (temp.size() == 0)
		return;
	bool didSwap = true;
	for (int i = 0; i < temp.size() - 1; ++i)
	{
		for (int j = 0; j < temp.size() - i - 1; ++j)
		{
			if (temp[j] > temp[j + 1])
			{
				swap(temp[j], temp[j + 1]);
				didSwap = false;
			}
		}
		if (didSwap == true)
			break;
	}

}
//ð�������ʱ�临�Ӷ���O��N*N���������ž����ź�����������O��N��
//�����Ѿ��������Ż�����ռ临�Ӷ���O��1��

//��2�����������˼�룺�����ұ���һ������Ϊ��׼ֵ��������Ļ�������߿�ʼ�ߣ���
//�Ȼ�׼ֵ�������Ȼ����ұ߿�ʼ�ң��Ȼ�׼ֵС���������������������������±���ȵ�
//ʱ�򣬽���ͻ�׼ֵ��������ʱ���Ϊ�������䣬���������������ͬ���ķ������еݹ�
//�������������ֻʣ��һ������ʱ��ݹ������Ҳ��������ˡ�
//3 5 3 4 1 2
//��һ��֮��
//1 5 3 4 3 2
//�������3�ܵ����ұ�3���ұߣ�������ǲ��ȶ���
void _QuickSort(vector<int>& temp, int left, int right)
{
	if (left >= right)
		return;
	int key = temp[right];
	int keyindex = right;
	--right;
	while (left < right)
	{
		while (temp[left] < key)
			++left;

		if (left >= right)
			break;

		while (right > 0 && temp[right] > key)
			--right;

		if (left < right)
			swap(temp[left], temp[right]);
	}
	if(temp[left] > temp[keyindex])
		swap(temp[left], temp[keyindex]);

	_QuickSort(temp, 0, left - 1);
	_QuickSort(temp, left + 1, keyindex);
}
void QuickSort(vector<int>& temp)
{
	if (temp.size() == 1 || temp.size() == 0)
		return;

	_QuickSort(temp, 0, temp.size() - 1);
}
//���Կ��������������ʱ�临�Ӷ���O(N*logN)�ռ临�Ӷ�ΪO(logN)










int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		//InsertSort(arr);
		//ShellSort(arr);
		//SelectSort(arr);
		//HeapSort(arr);
		//BubbleSort(arr);
		QuickSort(arr);
		//InsertSort(arr);
		for (int i = 0; i < arr.size(); i++)
		{
			cout << arr[i] << " ";
		}
	}
	return 0;
}