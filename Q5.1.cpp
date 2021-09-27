#include <stdio.h>
#include <iostream>
using namespace std;

typedef int *IntPtrType;

int main()
{
	IntPtrType ptr_a, ptr_b, *ptr_c;//ptr_a,ptr_b: con tro cap 1;ptr_c:con tro cap 2

	ptr_a = new int; 
	*ptr_a = 3;// gia tri tai dia chi ptr_a tro toi = 3 
	ptr_b = ptr_a;// gia tri cua ptr_b = gia tri cua ptr_a =>ptr_a va ptr_b cung tro toi 1 dia chi
	cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri tai dia chi ptr_a va ptr_b tro toi

	ptr_b = new int;//cap phat dong cho ptr_b
	*ptr_b = 9;//gia tri tai dia chi ptr_b tro toi = 9
	cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri tai dia chi ptr_a va ptr_b tro toi

	*ptr_b = *ptr_a;//gia tri tai dia chi ptr_b tro toi = gia tri tai dia chi ptr_a tro toi = 3
	cout << *ptr_a << " " << *ptr_b << "\n";//xuat ra gia tri tai dia chi ptr_a va ptr_b tro toi

	delete ptr_a;//giai phong bo nho cap phat dong
	ptr_a = ptr_b;
	cout << *ptr_a << " " << *&*&*&*&*ptr_b << "\n";//&*ptr_b=ptr_b =>*&*&*&*&*ptr_b = *ptr_b

	ptr_c = &ptr_a;//ptr_c tro den dia chi cua ptr_a
	cout << *ptr_c << " " << **ptr_c << "\n";//*ptr_c = gia tri cua ptr_a = dia chi ptr_a tro toi; **p_tr = gia tri tai dia chi ma ptr_a tro toi

	delete ptr_a;
	ptr_a = NULL;

	return 0;
}
