#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int x,y,z,*p,*q,*r;
	x = 1;
	y = 2;
	z = 3;
	p = &x;
	q = &y;
	r = &z;
	cout<<x<<" "<<y<<" "<<z<<" "<<p<<" "<<q<<" "<<r<<" "<<*p<<" "<<*q<<" "<<*r<<endl;
	cout<<"Swapping values"<<endl;
	z = x;
	x = y;
	y = z;
	cout<<x<<" "<<y<<" "<<z<<" "<<p<<" "<<q<<" "<<r<<" "<<*p<<" "<<*q<<" "<<*r<<endl;
}
