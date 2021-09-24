#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int x = 2;
	int y = 8;
	int *p,*q;
	p = &x;
	q = &y;
	cout<<&x<<" "<<x<<"\n";
	cout<<p<<" "<<*p<<"\n";
	cout<<&y<<" "<<y<<"\n";
	cout<<q<<" "<<*q<<"\n";
	cout<<&p<<" "<<&q<<"\n";
}
