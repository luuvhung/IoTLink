#include<stdio.h>
#include<iostream>
int main()
{
	int arr[10];
	int count=0;
	for (int i=0;i<10;i++)
	{
		std::cin>>arr[i];
		if (arr[i]>=10) count++;
	}
	std::cout<<"so luong so >=10: "<<count;
}
 
