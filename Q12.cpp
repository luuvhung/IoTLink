#include <iostream>
#include <typeinfo>
#include<string.h>
#include<list>
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
    People(char* name,Date birthday,int idCode)
    {
        this->name=name;
        this->birthday=birthday;
        this->idCode=idCode;
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
        this->name = name;
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
    Staff(char *name,Date birthday,int idCode,int departmentId,Date joinedDate,int level):People(name,birthday,idCode)
    {
        this->departmentId=departmentId;
        this->joinedDate=joinedDate;
        this->level=level;
        count++;
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
    Student(char* name,Date birthday,int idCode,int grade,int numOfProject, float *scoreProject):People(name,birthday,idCode)
    {
        this->grade=grade;
        this->numOfProject=numOfProject;
        this->scoreProject=scoreProject;
        count++;
    }
    ~Student()
    {
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
    Teacher(char *name,Date birthday,int idCode,int departmentID,Date joinedDate,int level,int Class,subjects subject,subjects secondSubject):Staff(name,birthday,idCode,departmentID,joinedDate,level)
    {
        this->Class = Class;
        this->subject = subject;
        this->secondSubject = secondSubject;
        count++;
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
    list<People*> ppList;
    People *pp1 = new People("hungpp",{1,2,1999},2);
    People *stf1 = new Staff("hungstf",{1,2,2000},2,1,{1,2,2020},1);
    People *tc1 = new Teacher("hungtc",{1,3,2001},3,2,{1,1,2021},2,12,MATHS,ENGLISH);
    float score[2] = {10,9};
    People *st1 =  new Student("hungst",{3,4,1999},4,11,2,score);
    ppList.push_back(pp1);
    ppList.push_back(stf1);
    ppList.push_back(tc1);
    ppList.push_back(st1);
    list<People*>::iterator i = ppList.begin();
    advance(i,0);
    (*i)->setName("hung1");
    i = ppList.begin();
    advance(i,1);
    (*i)->setName("hung2");
    i = ppList.begin();
    advance(i,2);
    (*i)->setName("hung3");
    i = ppList.begin();
    advance(i,3);
    (*i)->setName("hung4");
    for (i = ppList.begin();i!=ppList.end();i++)
    {
        (*i)->printInfo();
    }
    for (i = ppList.begin();i!=ppList.end();i++)
    {
        delete *i;
    }
    ppList.clear();
    system("pause");
}