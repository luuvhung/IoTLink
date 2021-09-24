#include <iostream>
using namespace std;

int main()
{
	int a[4] = {1, 2, 3, 4};
	int *p = a;
	printf("%d %d %d\n", a, *a, &a);
	printf("%d %d %d\n", p, *p, &p);

	printf("%d %d %d %d\n", (a + 1), *(a + 1), *a + 1, &a + 1);
	printf("%d %d %d %d\n", (p + 1), *(p + 1), *p + 1, &p + 1);
}

