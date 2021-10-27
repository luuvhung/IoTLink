#pragma once
#include "Staff.h"
enum Subjects { MATHS, PHYS, ENGLISH };
class Teacher :
    public Staff
{
private:
    int Class;
    Subjects subject;
    Subjects secondSubject;
public:
    static int num;
    Teacher();
    Teacher(char*,Date,int,int,Date,int,int,Subjects,Subjects);
    ~Teacher();
    void printInfo();
    void setClass(int);
    int getClass();
    void setSubject(Subjects);
    Subjects getSubject();
    void setSecondSubject(Subjects);
    Subjects getSecondSubject();
};

