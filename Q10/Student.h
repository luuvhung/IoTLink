#pragma once
#include "People.h"
class Student :
    public People
{
private:
    int grade;
    int numOfProject;
    float* scoreOfProject;
    float calAvgScore();
public:
    Student();
    Student(char*, Date, int, int, int, float*);
    Student(Student*);
    ~Student();
    static int num;
    void printInfo();
    void setGrade(int);
    int getGrade();
    void setNumOfProject(int);
    int getNumOfProject();
    void setScoreOfProject(float*);
    float* getScoreOfProject();
    float getAvgScore();
};

