#include<iostream>
int main()
{
	int *a = new int;
	*a = 10;
	delete a;
	printf("%d", *a);
}
//sau khi delete a thi vung nho a tro den se duoc giai phong va cap phat cho 1 tac vu khac nen gia tri se ngau nhien
