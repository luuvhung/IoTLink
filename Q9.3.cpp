#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int CheckBigger(int a, int b) {return a>b;}
int CheckSmaller(int a, int b) {return a<b;}
void sort(int *arr, int count, int (*order) (int, int))
{
    for(int i=0;i<count-1;i++)
	{
		for(int j=count-1;j>i;j--)
		{
			if(order(arr[j], arr[j-1])) swap(arr[j], arr[j-1]);
		}
	}
}
void output(int arr[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int a[10] = {1,4,2,4,5,10,1,4,2,3};
	sort(a,5,CheckBigger);
	output(a,10);
	cout<<endl;
	sort(a,5,CheckSmaller);
	output(a,10);
	system("pause");
}

