#include <stdio.h>
#include <iostream>
#include <cstdio>
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
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