#include <stdio.h>
#include <iostream>
int main(int n, char** args)
{
	int i = 140;
	char c = i;
	int j;
	if (i<=127) j = c;
	else j = 256 + c;
	printf("%d", j);
	system("pause");
}
/*
*ket qua: -116 vi gioi han char = [-128,127], nen c=140 se duoc gan gia tri nguoc tro lai
*neu thay "char c" = "unsigned char c" ket qua se in ra 140 vi gioi han cua unsigned char = [0,255]
*neu thay i = 260 ket qua in ra 4 vi gioi han cua unsigned char = [0,255]
*/
