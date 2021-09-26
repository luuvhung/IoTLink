#include <iostream>
using namespace std;
struct Student
{
    char *name;
    int id;
    float score;
    static int numOfStudent;
    Student()
    {
        name = new char[10];
        numOfStudent++;
    }
    ~Student()
    {
        //delete[] name;
        //numOfStudent--;
    }
};
bool checkid(Student s[], int index)
{
    if (index == 0)
        return false;
    for (int i = 0; i < index; i++)
    {
        if (s[index].id == s[i].id)
            return true;
    }
    return false;
}
int Student::numOfStudent = 0;
void input(Student s[])
{
    for (int i = 0; i < Student::numOfStudent; i++)
    {
        cout << "Name: ";
        cin >> s[i].name;
        do
        {
            cout << "ID: ";
            cin >> s[i].id;
        } while (checkid(s, i));
        do
        {
            cout<<"Score: ";
            cin>>s[i].score;
        } while (s[i].score>10||s[i].score<0);
    }
}
void swap(Student &x, Student &y)
{
    Student temp = x;
    x = y;
    y = temp;
}
void Sort(Student arr[])
{
	for(int i=0;i<Student::numOfStudent;i++)
	{
		for(int j=Student::numOfStudent-1;j>i;j--)
		{
			if(arr[j].score < arr[j-1].score) swap(arr[j], arr[j-1]);
		}
	}
}
int main()
{
    Student student[10];
    input(student);
    Sort(student);
    for (int i=0;i<10;i++)
    {
        cout<<student[i].name<<" "<<student[i].id<<" "<<student[i].score<<endl;
    }
    system("pause");
}