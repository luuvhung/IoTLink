#include<stdio.h>
#include<iostream>

void calculate(int val)
{
	static int count=10;
	static int value;
	printf("%d %d\n",value, count++);
	value = val;
}

int main(int n, char** args)
{
	int i = 1;
	int j = 2;
	calculate(i);
	calculate(j);
}
/* 
trong lan goi ham dau tien 2 bien static duoc khoi tao count = 10,value = 0 =>in ra "0 10" sau do count tang len 11, value = val = i = 1
trong lan goi ham thu hai count = 11, value = 1 =>in ra "1 11" sau do count tang len 12, value = j = 2 
*/
