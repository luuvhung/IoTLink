#include <stdio.h>
#include <iostream>

int main(int n, char** args)
{
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i*10;
	}
	printf("0x%x 0x%x 0x%x\n", a, *a, &a);
	printf("0x%x 0x%x 0x%x 0x%x\n", (a + 1), *(a + 1), *a + 1, &a + 1);
}
/* 
a = &a = &a[0]
*a gia tri cua a[0] = 0
(a+1) = &a[1]
*(a+1) = a[1]
*a + 1 = a[0] + 1
&a + 1 dia chi cua vung nho sau mang a, cach a 10*4 bytes = 40 bytes
*/
