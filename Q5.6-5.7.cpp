#include<iostream>
int main()
{
	int a[4] = {1, 2, 3, 4};
	int *p = a;

	int *p2 = new int;
	
	//delete p;
	//delete a;
	delete p2;
}
//su dung delete de giai phong bo nho cap phat dong
//delete[] su dung khi cap phat dong cho mang

