#include <iostream>
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
        count++;
    }
    virtual void printInfo()
    {
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
    Staff()
    {
        count++;
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
class Node
{
    public:
        People* data;
        Node* next;
        static Node *addElement(Node* head,People *data)
        {
            Node *temp = new Node;
            temp->next = NULL;
            temp->data = data;
            if (head==NULL)
                head = temp;
            else
            {
                temp->next = head;
                head = temp;
            }
            return temp;
        }
};
void input(Node *&head)
{
    bool ctn = true;
    while(ctn)
    {
        int choice = 0;
        cout << "Select" << endl
            << "1. Student" << endl
            << "2. Staff" << endl
            << "3. Teacher" << endl
            << "4. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            char *name = new char[10];
            Student *st = new Student;
            cout << "Name: ";
            cin >> name;
            st->setName(name);
            int day, month, year;
            cout << "Birthday: ";
            cin >> day >> month >> year;
            st->setBirthday(day,month,year);
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            st->setIdCode(idCode);
            int grade;
            cout << "Grade: ";
            cin >> grade;
            st->setGrade(grade);
            int num;
            cout << "Num of project: ";
            cin >> num;
            st->setNumOfProject(num);
            float *score = new float[num];
            for (int i = 0; i < num; i++)
            {
                cout << "Enter score project " << i + 1 << " : ";
                cin >> score[i];
            }
            st->setScoreProject(score);
            head = Node::addElement(head,st);
            break;
        }
        case 2:
        {
            char *name = new char[10];
            Staff *stf = new Staff;
            cout << "Name: ";
            cin >> name;
            stf->setName(name);
            int day, month, year;
            cout << "Birthday: ";
            cin >> day >> month >> year;
            stf->setBirthday(day,month,year);
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            stf->setIdCode(idCode);
            int departmentId;
            cout<<"Department ID: ";
            cin>>departmentId;
            stf->setDepartmentId(departmentId);
            cout<<"Joined Day: ";
            cin>>day>>month>>year;
            stf->setJoinedDate(day,month,year);
            int level;
            cout<<"Level: ";
            cin>>level;
            stf->setLevel(level);
            head = Node::addElement(head,stf);
            break;
        }
        case 3:
        {
            char *name = new char[10];
            Teacher *tc = new Teacher;
            cout << "Name: ";
            cin >> name;
            tc->setName(name);
            int day, month, year;
            cout << "Birthday: ";
            cin >> day >> month >> year;
            tc->setBirthday(day,month,year);
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            tc->setIdCode(idCode);
            int departmentId;
            cout<<"Department ID: ";
            cin>>departmentId;
            tc->setDepartmentId(departmentId);
            cout<<"Joined Day: ";
            cin>>day>>month>>year;
            tc->setJoinedDate(day,month,year);
            int level;
            cout<<"Level: ";
            cin>>level;
            tc->setLevel(level);
            int Class;
            cout<<"Class: ";
            cin>>Class;
            tc->setClass(Class);
            int subject, secondSubject;
            cout<<"Subject, second subject: ";
            cin>>subject>>secondSubject;
            tc->setSubject((subjects)subject);
            tc->setSecondSubject((subjects)secondSubject);
            head = Node::addElement(head,tc);
            break;
        }  
        case 4:
            ctn = false;
            break;
        }
    }
}
void printList(Node *head)
{
    for (Node *i = head; i != NULL; i = i->next)
    {
        i->data->printInfo();
    }
}
int People::count = 0;  //do static là biến dùng chung nên không thuộc 1 đối tượng nào
int Staff::count = 0;   //nên không thể khởi tạo trong hàm contructor của class được
int Student::count = 0; //phải khởi tạo bên ngoài
int Teacher::count = 0;
int main()
{
    Node *head = NULL;
    input(head);
    printList(head);
    cout << People::count;
    cout << Staff::count;
    cout << Student::count;
    cout << Teacher::count;
    system("pause");
}