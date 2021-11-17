#include<iostream>
#include<math.h>
#include<vector> 
using namespace std;
void printArray(vector<int> arr);
/*****************************/
void bubbleSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void insertSort(vector<int>& a);
void quickSort(vector<int>& arr, int left, int right);
void mergeSort(vector<int>& arr, int left, int right);
/************Ví dụ*****************/
void selectionSortExample(vector<int>& arr);//sắp xếp số nguyên tố trong mảng theo thứ tự tăng dần, giữ nguyên các vị trí còn lại
void bubbleSortExample(vector<int>& arr);//sắp xếp lẻ ở đầu mảng theo thứ tự tăng dần, chẵn ở cuối theo thứ tự giảm dần
void insertionSortExample(vector<int>& arr1, vector<int>& arr2);//chèn mảng mới vào một mảng đã sắp xếp theo thứ tự tăng dần

int main()
{
	vector<int> a={ 1,10,11,8,3,5,3,2,6,4 };
	//selectionSort(a);
	//insertSort(a);
	selectionSortExample(a);
	printArray(a);
	bubbleSortExample(a);
	printArray(a);
	//quickSort(a, 0, a.size()-1);
	mergeSort(a, 0, a.size() - 1);
	printArray(a);
	vector<int> b = { 5,3,10 };
	insertionSortExample(a, b);
	printArray(a);
}


void bubbleSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size()-1; i++)
		for (int j = arr.size()-1; j > i; j--)
			if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
}
void selectionSort(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < arr.size(); j++)
			if (arr[j] < arr[min]) min = j;
		if (arr[i] > arr[min]) swap(arr[i], arr[min]);
	}
}
void insertSort(vector<int>& a)
{
	int temp, last;
	for (int i = 1; i < a.size(); i++)
	{
		temp = a[i];
		last = i - 1;
		while (last >= 0 && a[last] > temp)
		{
			a[last + 1] = a[last];
			last--;
		}
		a[last + 1] = temp;
	}
}

int partition(vector<int>& arr, int left, int right)
{
	int i = left, j = right;
	int pivot = arr[right];
	while (i<j)
	{
		while (arr[i] < pivot && i < j) i++;
		while (arr[j - 1] >= pivot && i < j) j--;
		if (i < j)
		{
			swap(arr[i], arr[j - 1]);
			i++;
			j--;
		}
	}
	if (pivot < arr[i]) swap(arr[i], arr[right]);
	return i;
}
void quickSort(vector<int>& arr, int left, int right)
{
	if (right > left)
	{
		int i = partition(arr, left, right);
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
}
void merge(vector<int> &arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	vector<int> temp;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp.push_back(arr[i]);
			i++;
		}
		else 
		{
			temp.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid)
	{
		temp.push_back(arr[i]);
		i++;
	}
	while (j <= right)
	{
		temp.push_back(arr[j]);
		j++;
	}
	for (int i = left; i <= right; i++)
		arr[i] = temp[i - left];
}
void mergeSort(vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}
void bubbleSortExample(vector<int>& arr)
{
	for (int i = 0; i < arr.size()-1; i++)
		for (int j = arr.size()-1; j > i; j--)
		{
			if ((arr[j-1] % 2 == 0 && arr[j] % 2 != 0)
				|| (arr[j-1] % 2 != 0 && arr[j] % 2 != 0 && arr[j-1] > arr[j])
				|| (arr[j-1] % 2 == 0 && arr[j] % 2 == 0 && arr[j-1] < arr[j])) swap(arr[j], arr[j-1]);
		}
}
bool check(int n)//ham kiem tra so nguyen to
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}
void selectionSortExample(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
		if (check(arr[i]))
		{
			int min = i;
			for (int j = i + 1; j < arr.size(); j++)
			{
				if (check(arr[j]) && arr[j] < arr[min]) min = j;
			}
			if (min != i) swap(arr[min], arr[i]);
		}
}
void insertionSortExample(vector<int>& arr1, vector<int>& arr2)
{
	for (int i = 0; i < arr2.size(); i++)
	{
		int last = arr1.size() - 1;
		arr1.push_back(arr2[i]);
		while (last >= 0 && arr1[last] > arr2[i])
		{
			arr1[last + 1] = arr1[last];
			last--;
		}
		arr1[last + 1] = arr2[i];
	}

}

void printArray(vector<int> arr)
{
	cout << endl;
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}