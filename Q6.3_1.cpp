//using memcpy

#include<iostream>
#include<string.h>
void swap(char &x, char &y)
{
    char temp = x;
    x = y;
    y = temp;
}
void copyString(char *input, int offset, int length, bool invert, char *output, int output_offset)
{
	char c[length+1];
	memcpy(c,&input[offset],length);
	c[length]='\0';
	if (invert)
	{
		for (int i=0;i<length/2;i++)
		{
			swap(c[i] , c[length-i-1]);
		}
	}
	int l = strlen(output);
	memcpy(&output[output_offset],c,length);
	output[l] = '\0';
}
int main()
{
	char st[] = "Hello world";//char *st = "Hello world" con tro st se tro den chuoi hang ki tu nen khong the sua gia tri cua chuoi
	char st2[] = "My name is C++";
	copyString(st, 6, 5 , true, st2, 11);
	std::cout<<st2;
}
