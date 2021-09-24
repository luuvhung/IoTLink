#include <stdio.h>
#include <iostream>
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void Invert(int input[], int num_element)
{
	for (int i=0;i<num_element/2;i++)
	{
		swap(input[i],input[num_element-1-i]);
	}
}
void Invert(int input[], int num_element, int output[])
{
	for (int i=0;i<num_element;i++)
	{
		output[i] = input[num_element-1-i];
	}
}
int main()
{
	int a[6] = {1,2,3,4,5,6};
	Invert(a,6);
	for (int i=0;i<6;i++)
	{
		std::cout<<a[i]<<" ";
	}
	int b[6];
	Invert(a,6,b);
	for (int i=0;i<6;i++)
	{
		std::cout<<b[i]<<" ";
	}
}
