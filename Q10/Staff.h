#pragma once
#include "People.h"
class Staff :
    public People
{
protected:
    int departmentID;
    Date joinedDate;
    int level;
public:
    int static num;
    Staff();
    Staff(char*, Date, int, int, Date, int);
    virtual ~Staff();
    void virtual printInfo();
    void setDepartmentID(int);
    int getDepartmentID();
    void setJoinedDate(Date);
    Date getJoinedDate();
    void setLevel(int);
    int getLevel();
};

