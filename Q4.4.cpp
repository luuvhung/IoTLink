#include <stdio.h>
#include <iostream>
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void BubbleSort(int arr[], int count)
{
	for(int i=0;i<count-1;i++)
	{
		for(int j=count-1;j>i;j--)
		{
			if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
		}
	}
}
void BubbleSort(int arr[], int offset, int count)
{
	BubbleSort(&arr[offset],count);
}
int main()
{
	int a[5] = {100, 4, 2, 6, 3};
	BubbleSort(a,1,4);
	for (int i = 0; i < 5; i++)
	{
		std::cout<<a[i]<<" ";
	}
}
