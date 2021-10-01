#include <iostream>
#include <typeinfo>
#include<string.h>
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
class Node
{
    public:
        People* data;
        Node* next;
        static void addElement(Node* &head,People *data)
        {
            Node *temp1 = new Node;
            Node *temp2;
            temp1->next = NULL;
            temp1->data = data;
            if (head==NULL)
                head = temp1;
            else
            {
                temp2 = head;
                while(temp2->next!=NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = temp1;
            }
        }
        static void removeElement(Node* &head, Node* i)
        {
            if (i==head) head = i->next;
            else
            {
                Node *temp;
                for (Node* j= head;j!=i;j = j->next)
                {
                    if (j->next=i) temp = j;
                }
                temp->next = i->next;
            }
            delete i;
        }
        ~Node()
        {
            cout<<"delete node"<<endl;
            delete data;
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
            char name[10];
            Student *st = new Student;
            cout << "Name: ";
            cin >> name;
            st->setName(name);
            int day, month, year;
            cout << "Birthday(day,month,year): ";
            cin >> day>> month >> year;
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
            Node::addElement(head,st);
            break;
        }
        case 2:
        {
            char name[10];
            Staff *stf = new Staff;
            cout << "Name: ";
            cin >> name;
            stf->setName(name);
            int day, month, year;
            cout << "Birthday(day,month,year): ";
            cin >> day>> month >> year;
            stf->setBirthday(day,month,year);
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            stf->setIdCode(idCode);
            int departmentId;
            cout<<"Department ID: ";
            cin>>departmentId;
            stf->setDepartmentId(departmentId);
            cout<<"Joined Day(day,month,year): ";
            cin>>day>>month>>year;
            stf->setJoinedDate(day,month,year);
            int level;
            cout<<"Level: ";
            cin>>level;
            stf->setLevel(level);
            Node::addElement(head,stf);
            break;
        }
        case 3:
        {
            char name[10];
            Teacher *tc = new Teacher;
            cout << "Name: ";
            cin >> name;
            tc->setName(name);
            int day, month, year;
            cout << "Birthday(day,month,year): ";
            cin >> day>> month >> year;
            tc->setBirthday(day,month,year);
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            tc->setIdCode(idCode);
            int departmentId;
            cout<<"Department ID: ";
            cin>>departmentId;
            tc->setDepartmentId(departmentId);
            cout<<"Joined Day(day,month,year): ";
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
            Node::addElement(head,tc);
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
void swap(Node *x, Node *y)
{
    Node *temp;
    temp->data = x->data;
    x->data = y->data;
    y->data = temp->data;
}
void sort(Node *head)
{
    for (Node *i=head;i!=NULL;i=i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (dynamic_cast<Student*>(i->data)&&dynamic_cast<Staff*>(j->data)) swap(i,j);
            if (dynamic_cast<Teacher*>(i->data)&&dynamic_cast<Staff*>(j->data)&&!dynamic_cast<Teacher*>(j->data)) swap(i,j);
        }
    }
}
void printStudent(Node *head)
{
    for (Node *i=head;i!=NULL;i=i->next)
    {
        if(dynamic_cast<Student*>(i->data))
        {
            Student *st;
            st = (Student*)i->data;
            if(st->getCalAvgScore()>5) st->printInfo(); 
        }
    }
}
Node *cloneList(Node *node,Node *list)
{
    for (Node *i = list;i!=NULL;i = i->next)
    {
        if (dynamic_cast<Student*>(i->data))
        {
            Student *st = new Student((Student *)i->data);
            Node::addElement(node,st);
        }
        else if(dynamic_cast<Teacher*>(i->data))
        {
            Teacher *tc = new Teacher((Teacher *)i->data);
            Node::addElement(node,tc);
        }
        else
        {
            Staff *st =  new Staff((Staff *)i->data);
            Node::addElement(node,st);
        }
    }
    return node;

}
int People::count = 0;  //do static là biến dùng chung nên không thuộc 1 đối tượng nào
int Staff::count = 0;   //nên không thể khởi tạo trong hàm contructor của class được
int Student::count = 0; //phải khởi tạo bên ngoài
int Teacher::count = 0;
int main()
{
    Node *head = NULL;
    Node *clone = NULL;
    input(head);//add cac phan tu vao list
    sort(head);//sap xep dau staff, giua teacher, cuoi student
    printList(head);//in ra list
    cout<<endl<<"Danh sach hoc sinh co diem trung binh lon hon 5: "<<endl;
    printStudent(head);//in ra danh sach sinh vien co diem tb > 5
    cout <<endl<<"Num of People: "<<People::count<<endl;
    cout <<"Num of Staff: "<<Staff::count<<endl;
    cout <<"Num of Student: "<<Student::count<<endl;
    cout <<"Num of Teacher: "<<Teacher::count<<endl;
    Node::removeElement(head,head->next);//xoa 1 node
    clone = cloneList(clone,head);//sao chep 1 list
    printList(clone);//in ra list
    system("pause");
}