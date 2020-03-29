
#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& arr, int _left, int _right)
{
	if (left >= right) 
		return;
	int p1 = _left;
	int p2 = _right;
	int pivot = arr[p1];
	while (p1 < p2)
	{
		while (p1 < p2 && arr[p2] >= pivot) 
			p2--;

		if(p1 < p2)
			arr[p1] = arr[p2];

		while (p1 < p2 && arr[p1] <= pivot) 
			p1++;

		if (p1 < p2)
			arr[p2] = arr[p1];
	}
	arr[p1] = pivot;
	quickSort(arr, _left, p1 - 1);
	quickSort(arr, p1 + 1, _right);
}

int main()
{
	int n; cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	quickSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < n; i++)
	{
		if (i) 
			cout << " " << arr[i];
		else 
			cout << arr[i];
	}
	return 0;
}

/*#include<iostream>
#include<vector>

using namespace std;

void quickSort(vector<int>& arr, int _left, int _right)
{
	if (_left >= _right)
		return;

	int left = _left;
	int right = _right;
	int index = arr[left];

	while (left < right)
	{
		while (left < right && arr[right] >= index)
			right--;
		if (left < right)
			arr[left] = arr[right];

		while (left < right && arr[left] <= index)
			left++;
		if (left < right)
			arr[right] = arr[left];
	}
	arr[left] = index;

	quickSort(arr, _left, left - 1);
	quickSort(arr, right + 1, _right);
}

int main()
{
	int n; cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	quickSort(arr, 0, arr.size() - 1);
	for (int i = 0; i < n; i++)
	{
		if (i)
			cout << " " << arr[i];
		else
			cout << arr[i];
	}
	return 0;
}*/