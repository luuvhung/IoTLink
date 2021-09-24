#include <iostream>
using namespace std;

#define COUNT 10
#define MAX(a, b) ((a) < (b) ? (a):(b))
int main()
{
	int *p = new int[COUNT];
	int a[COUNT];

	for (int i = 0; i < sizeof(a); i++)
	{
		a[i] = i;
	}

	for (int i = 0; i < sizeof(p); i++)
	{
		p[i] = i;
	}
	

	for (int i = 0; i < MAX(sizeof(a), sizeof(p)); i++)
	{
		printf("%d %d\n", a[i], p[i]);
	}
}

