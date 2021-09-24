#include<iostream>
#include<string.h>
void clone(char *input, char *output)
{
	for (int i=0;i<strlen(input);i++)
	{
		output[i] = input[i];
	}
}
int main()
{
	char *st = "Hello";
	char *st2 = new char [100];
	clone(st,st2);
	std::cout<<st2;
	delete[] st2;
}
