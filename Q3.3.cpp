#include<stdio.h>
#include<iostream>
int Floor(float x)
{
	return int(x);
}
int ceil(float x)
{
	float y;
	y = x - int(x);
	return y>0?x+1:x;
}
int round(float x)
{
	float y;
	y = x - int(x);
	return y>=0.5?x+1:x;
}
int main()
{
	std::cout<<Floor(5.9);
	std::cout<<ceil(5.1);
	std::cout<<round(5.4);
}
