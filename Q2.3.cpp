#include<stdio.h>
#include<iostream>
//static int count= 1; 	Static variable outside function
//int count= 1; 	Global variable
void Count() 
{
	static int count= 1; //	Static variable inside function
	std::cout<<count; 
	count++; 
}

int main()
{
	Count();
	Count();
	Count();
}
//Bien static ben trong ham Count() se duoc khoi tao 1 lan duy nhat khi goi ham va chi duoc su dung trong ham Count()
//Bien toan cuc va bien static ngoai ham thi tuong tu nhau
