#include "Student.h"
#include<iostream>
using namespace std;
int Student::num = 0;
Student::Student()
{
	grade = 10;
	numOfProject = 10;
	scoreOfProject = new float[100];
	num++;
}
Student::Student(char* name, Date birthday, int idcode, int grade, int numOfProject, float* scoreOfProject) :People(name, birthday, idcode)
{
	setGrade(grade);
	setNumOfProject(numOfProject);
	setScoreOfProject(scoreOfProject);
	num++;
}
Student::Student(Student* st)
{
	strcpy_s(name, 100, st->name);
	birthday = st->birthday;
	idcode = st->idcode;
	grade = st->grade;
	numOfProject = st->numOfProject;
	scoreOfProject = new float[numOfProject];
	memcpy(scoreOfProject, st->scoreOfProject, sizeof(float) * numOfProject);
}
Student::~Student()
{
	delete[] scoreOfProject;
}
void Student::printInfo()
{
	People::printInfo();
	cout << "Class: " << getGrade() << endl
		<< "Num of project: " << getNumOfProject() << endl;
	for (int i = 0; i < getNumOfProject(); i++)
	{
		cout << "Score of project " << i + 1 << ": " << getScoreOfProject()[i] << endl;
	}
}
void Student::setGrade(int grade)
{
	this->grade = grade;
}
int Student::getGrade()
{
	return grade;
}
void Student::setNumOfProject(int numOfProject)
{
	this->numOfProject = numOfProject;
}
int Student::getNumOfProject()
{
	return numOfProject;
}
void Student::setScoreOfProject(float* scoreOfProject)
{
	this->scoreOfProject = scoreOfProject;
}
float* Student::getScoreOfProject()
{
	return scoreOfProject;
}
float Student::calAvgScore()
{
	float avg = 0;
	for (int i = 0; i < numOfProject; i++)
	{
		avg = avg + getScoreOfProject()[i];
	}
	avg = avg / numOfProject;
	return avg;
}
float Student::getAvgScore()
{
	return calAvgScore();
}
