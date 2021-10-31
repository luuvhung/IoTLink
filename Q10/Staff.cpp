#include "Staff.h"
#include<iostream>
using namespace std;
int Staff::num = 0;
void Staff::printInfo()
{
	People::printInfo();
	cout << "Department ID: " << getDepartmentID() << endl
		<< "Joined Date: " << getJoinedDate().day << "/" << getJoinedDate().month << "/" << getJoinedDate().year << endl
		<< "Level: " << getLevel() << endl;
}
Staff::Staff()
{
	departmentID = 0;
	joinedDate = { 0,0,0 };
	level = 0;
	num++;
}
Staff::Staff(char* name, Date birthday, int idcode, int departmentID, Date joinedDate, int level) :People(name, birthday, idcode)
{
	setLevel(level);
	setDepartmentID(departmentID);
	setJoinedDate(joinedDate);
	num++;
}
Staff::Staff(Staff* stf)
{
	strcpy_s(name, 100, stf->name);
	birthday = stf->birthday;
	idcode = stf->idcode;
	level = stf->level;
	departmentID = stf->departmentID;
	joinedDate = stf->joinedDate;

}
Staff::~Staff()
{

}
void Staff::setDepartmentID(int departmentID)
{
	this->departmentID = departmentID;
}
int Staff::getDepartmentID()
{
	return departmentID;
}
void Staff::setJoinedDate(Date joinedDate)
{
	this->joinedDate = joinedDate;
}
Date Staff::getJoinedDate()
{
	return joinedDate;
}
void Staff::setLevel(int level)
{
	this->level = level;
}
int Staff::getLevel()
{
	return level;
}
