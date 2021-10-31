#include "Teacher.h"
#include<iostream>
using namespace std;
int Teacher::num = 0;
Teacher::Teacher()
{
	Class = 0;
	subject = MATHS;
	secondSubject = MATHS;
	num++;
}
Teacher::Teacher(char* name, Date birthday, int idcode, int departmentID, Date joinedDate, int level, int Class, Subjects subject, Subjects secondSubject) :Staff(name, birthday, idcode, departmentID, joinedDate, level)
{
	setClass(Class);
	setSubject(subject);
	setSecondSubject(secondSubject);
	num++;
}
Teacher::Teacher(Teacher* tc)
{
	strcpy_s(name,100, tc->name);
	birthday = tc->birthday;
	idcode = tc->idcode;
	level = tc->level;
	departmentID = tc->departmentID;
	joinedDate = tc->joinedDate;
	Class = tc->Class;
	subject = tc->subject;
	secondSubject = tc->secondSubject;
}
Teacher::~Teacher()
{

}
void Teacher::printInfo()
{
	Staff::printInfo();
	cout << "Class: " << getClass() << endl
		<< "Subject: " << getSubject() << endl
		<< "Second subject: " << getSecondSubject() << endl;
}
void Teacher::setClass(int Class)
{
	this->Class = Class;
}
int Teacher::getClass()
{
	return Class;
}
void Teacher::setSubject(Subjects subject)
{
	this->subject = subject;
}
Subjects Teacher::getSubject()
{
	return subject;
}
void Teacher::setSecondSubject(Subjects secondSubject)
{
	this->secondSubject = secondSubject;
}
Subjects Teacher::getSecondSubject()
{
	return secondSubject;
}