#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1.插入排序
//（1）直接插入排序
//思想：分为两个区间，一个是有序一个是无序
//假设插入N个数  第一次有序 [0,0]  无序 [1,N-1]
//以此类推将无序的数依次插入到有序的数中
void InsertSort(vector<int>& temp)
{
	if (temp.size() == 0)
		return;

	int i, j, key;
	for (i = 1; i < temp.size(); ++i)
	{
		//保存要插入的数字
		key = temp[i];
		//进行条件判断，依次将比key大的值往后挪一位
		for (j = i - 1; j >= 0 && key < temp[j]; --j)
		{
			temp[j + 1] = temp[j];
		}
		//进行有序插入
		temp[j + 1] = key;
	}
}
//由此可见直接插入最坏的排序时间复杂度为O(N*N) 
//最好的排序时间复杂度就是有序情况下是O(N)
//空间复杂度为O(N) 是稳定的

//（2）希尔排序
//从上面可以知道插入排序只有当数组是有序状况下排序的时间复杂度是最低的
//由此我们引入了希尔排序，多了一部预排序，在进行直接插入排序，可以提供效率
//思想：我们可以设一个gap控制每一次插入的间距，当gap为1的时候就代表排序好了
void ShellSort(vector<int>& temp)
{
	int gap = temp.size();
	while (gap > 1)
	{
		//假设数组是10个数
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
//从中可以看出希尔排序是进行了预排序，然后在进行直接插入排序
//由于它有增量gap 所以它是不稳定的，其时间复杂度是比O（N*N）要小的
//空间复杂度是O（1）

//2.选择排序
//（1）.选择排序的思想：每次在未排序的数组中找出最小的和未排序数组的第一个进行交换
//8 2 1 3 8 0 7
//第一次排序之后 0 2 1 3 8 8 7
//可见其是不稳定的排序算法
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
//可知其时间复杂度是O(N*N)空间复杂度是O(N)

//(2)堆排序的思想：排升序先建一个大堆然后根节点和最后一个结点进行交换，在向下调整
//以此类推，就排序好了。
//   6 
// 1   3
//       1
//从上面可以看出来6和1进行了交换 1 和 1 的顺序发生了变化所以堆排序是不稳定的
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
//可以看出来堆排的时间复杂度是O（N*logN）空间复杂度是O（1）

//3.交换排序
//（1）冒泡排序的思想：一个无序N个数的数组，两个两个比较
//先比较N-1次，将大的数就交换到了最后面，然后在依次冒泡牌组N-2
//直到剩一个数字
//1 3 1 7 2 9
//1 1 3 2 7 9
//可见其是稳定的
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
//冒泡排序的时间复杂度是O（N*N）而在最优就是排好序的情况下是O（N）
//上面已经做好了优化，其空间复杂度是O（1）

//（2）快速排序的思想：在最右边找一个数作为基准值，排升序的话，从左边开始走，找
//比基准值大的数，然后从右边开始找，比基准值小的数，两个交换，当左右两个下标相等的
//时候，将其和基准值交换，这时候分为两个区间，左区间和右区间以同样的方法进行递归
//处理，当最后区间只剩下一个数的时候递归结束，也就排序好了。
//3 5 3 4 1 2
//第一次之后
//1 5 3 4 3 2
//发现左边3跑到了右边3的右边，因此它是不稳定的
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
//可以看出来快速排序的时间复杂度是O(N*logN)空间复杂度为O(logN)










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