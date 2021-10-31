#include "People.h"
#include<iostream>
#include<string.h>
using namespace std;
int People::num = 0;
void People::printInfo()
{
	cout << "Name: " << getName() << endl
		<< "Birthday" << getBirthday().day << "/" << getBirthday().month << "/" << getBirthday().year << endl
		<< "ID code" << getIdCode() << endl;
}
People::People()
{
	name = new char[100];
	birthday = { 0,0,0 };
	idcode = 0;
	num++;
}
People::People(char* name, Date birthday, int idcode)
{
	setName(name);
	setBirthday(birthday);
	setIdCode(idcode);
	num++;
}
People::People(People* p)
{
	name = new char[100];
	strcpy_s(name, 100, p->name);
	birthday = p->birthday;
	idcode = p->idcode;
}
People::~People()
{
	delete[] name;
}
void People::setName(char* name)
{
	this->name = name;
}
char* People::getName()
{
	return name;
}
void People::setBirthday(Date birthday)
{
	this->birthday = birthday;
}
Date People::getBirthday()
{
	return birthday;
}
void People::setIdCode(int idcode)
{
	this->idcode = idcode;
}
int People::getIdCode()
{
	return idcode;
}