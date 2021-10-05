#include <iostream>
#include <typeinfo>
#include<string.h>
#include<fstream>
using namespace std;
struct Date
{
    int day, month, year;
};
enum subjects
{
    MATHS,
    PHYS,
    ENGLISH
};
class People
{
protected:
    char *name;
    Date birthday;
    int idCode;

public:
    static int count;
    People()
    {
        name = new char[10];
        count++;
    }
    People(People *p)
    {
        strcpy(name,p->name);
        birthday = p->birthday;
        idCode = p->idCode;
    }
    virtual ~People()
    {
        delete[] name;
        cout<<"delete People"<<endl;
        count--;
    }
    virtual void printInfo()
    {
        cout<<"-------------------"<<endl;
        cout << "Name: " << name << endl;
        cout << "Birthday: " << birthday.day << "/" << birthday.month << "/" << birthday.year << endl;
        cout << "ID code: " << idCode << endl;
    }
    char *getName()
    {
        return name;
    }
    void setName(char *name)
    {
        strcpy(this->name,name);
    }
    Date getBirthday()
    {
        return birthday;
    }
    void setBirthday(int day, int month, int year)
    {
        birthday.day = day;
        birthday.month = month;
        birthday.year = year;
    }
    int getIdCode()
    {
        return idCode;
    }
    void setIdCode(int idCode)
    {
        this->idCode = idCode;
    }
};
class Staff : public People
{
protected:
    int departmentId;
    Date joinedDate;
    int level;

public:
    static int count;
    Staff()
    {
        count++;
    }
    Staff(Staff *stf)
    {
        strcpy(name,stf->name);
        birthday = stf->birthday;
        idCode = stf->idCode;
        departmentId = stf->departmentId;
        joinedDate = stf->joinedDate;
        level = stf->level;
    }
    virtual ~Staff()
    {
        cout<<"delete staff"<<endl;
        count--;
    }
    virtual void printInfo()
    {
        People::printInfo();
        cout << "Department ID: " << departmentId << endl;
        cout << "Joined Date: " << joinedDate.day << "/" << joinedDate.month << "/" << joinedDate.year << endl;
        cout << "Level: " << level << endl;
    }
    int getDepartmentId()
    {
        return departmentId;
    }
    void setDepartmentId(int departmentId)
    {
        this->departmentId = departmentId;
    }
    Date getJoinedDate()
    {
        return joinedDate;
    }
    void setJoinedDate(int day, int month, int year)
    {
        joinedDate.day = day;
        joinedDate.month = month;
        joinedDate.year = year;
    }
    int getLevel()
    {
        return level;
    }
    void setLevel(int level)
    {
        this->level = level;
    }
};
class Student : public People
{
private:
    int grade;
    int numOfProject;
    float *scoreProject;
    float calAvgScore()
    {
        float score = 0;
        for (int i = 0; i < numOfProject; i++)
        {
            score = score + scoreProject[i];
        }
        return score / (float)numOfProject;
    }

public:
    static int count;
    Student()
    {
        count++;
    }
    Student(Student *st)
    {
        strcpy(name,st->name);
        birthday = st->birthday;
        idCode = st->idCode;
        grade = st->grade;
        numOfProject = st->numOfProject;
        scoreProject = new float[numOfProject];
        memcpy(scoreProject,st->scoreProject,sizeof(float)*numOfProject);
    }
    ~Student()
    {
        delete[] scoreProject;
        cout<<"delete student"<<endl;
        count--;
    }
    void printInfo()
    {
        People::printInfo();
        cout << "Grade: " << grade << endl;
        cout << "Num of project: " << numOfProject << endl;
        for (int i = 0; i < numOfProject; i++)
        {
            cout << "Score of project " << i + 1 << ": " << scoreProject[i] << endl;
        }
    }
    int getGrade()
    {
        return grade;
    }
    void setGrade(int grade)
    {
        this->grade = grade;
    }
    int getNumOfProject()
    {
        return numOfProject;
    }
    void setNumOfProject(int numOfProject)
    {
        this->numOfProject = numOfProject;
    }
    float *getScoreProject()
    {
        return scoreProject;
    }
    void setScoreProject(float *scoreProject)
    {
        this->scoreProject = scoreProject;
    }
    float getCalAvgScore()
    {
        return calAvgScore();
    }
};
class Teacher : public Staff
{
private:
    int Class;
    subjects subject, secondSubject;

public:
    static int count;
    Teacher()
    {
        count++;
    }
    Teacher(Teacher *tc)
    {
        strcpy(name,tc->name);
        birthday = tc->birthday;
        idCode = tc->idCode;
        departmentId = tc->departmentId;
        joinedDate = tc->joinedDate;
        level = tc->level;
        Class = tc->Class;
        subject = tc->subject;
        secondSubject = tc->secondSubject;
    }
    ~Teacher()
    {
        cout<<"delete teacher"<<endl;
        count--;
    }
    void printInfo()
    {
        Staff::printInfo();
        cout << "Class: " << Class << endl;
        cout << "Subject: " << subject << endl;
        cout << "Second Subject: " << secondSubject << endl;
    }
    int getClass()
    {
        return Class;
    }
    void setClass(int Class)
    {
        this->Class = Class;
    }
    subjects getSubject()
    {
        return subject;
    }
    void setSubject(subjects subject)
    {
        this->subject = subject;
    }
    subjects getSecondSubject()
    {
        return secondSubject;
    }
    void setSecondSubject(subjects secondSubject)
    {
        this->secondSubject = secondSubject;
    }
};
int People::count = 0;  //do static là biến dùng chung nên không thuộc 1 đối tượng nào
int Staff::count = 0;   //nên không thể khởi tạo trong hàm contructor của class được
int Student::count = 0; //phải khởi tạo bên ngoài
int Teacher::count = 0;
int main()
{
    Teacher *tc1 = new Teacher;
    Staff *stf1 = dynamic_cast<Staff*>(tc1);
    People *p1 = dynamic_cast<People*>(tc1);
    //
    Student *st1 = new Student;
    People *p2 = dynamic_cast<People*>(st1);
    cout<<dynamic_cast<Teacher*>(st1);
    //Teacher *tc2 = static_cast<Teacher*>(st1);
    delete tc1;
    delete st1;
}