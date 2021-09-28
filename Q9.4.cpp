#include<iostream>
#include<stdio.h>
#include <cstdio>
using namespace std;
extern void sort(int *arr, int count, int (*order) (int, int));
int CheckBigger(int a, int b) {return a>b;}
int CheckSmaller(int a, int b) {return a<b;}
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
