#include<iostream>
int main()
{
	char *st = "Hello world";
	std::cout<<st<<std::endl;
	char st2[] = {'H','e','l','l','o',' ','w','o','r','l','d','\0'};
	std::cout<<st2<<std::endl;
	char *st3 = new char[12];
	st3[0] = 'H';
	st3[1] = 'e';
	st3[2] = 'l';
	st3[3] = 'l';
	st3[4] = 'o';
	st3[5] = ' ';
	st3[6] = 'w';
	st3[7] = 'o';
	st3[8] = 'r';
	st3[9] = 'l';
	st3[10] = 'd';
	st3[11] = '\0';
	std::cout<<st3;
	delete[] st3;
}
