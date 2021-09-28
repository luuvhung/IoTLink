#include <iostream>
#include <string.h>
using namespace std;

typedef struct _Student
{
    char *name;
    int id;
    float score;
    struct _Student *next;
} student;
student *createStudent(char name[], int id, float score)
{
    student *temp = new student;
    temp->name = new char[10];
    strcpy(temp->name, name);
    temp->id = id;
    temp->score = score;
    temp->next = NULL;
    return temp;
}
student *addStudent(student *head, char name[], int id, float score)
{
    student *temp = createStudent(name, id, score);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}
bool checkid(student *head, int id)
{
    if (head == NULL)
        return false;
    for (student *i = head; i != NULL; i = i->next)
    {
        if (id == i->id)
            return true;
    }
    return false;
}
student *input()
{
    student *head = NULL;
    char name[10];
    int id, temp = 1;
    float score;
    while (temp != 0)
    {
        cout << "Name: ";
        cin >> name;
        do
        {
            cout << "ID: ";
            cin >> id;
        } while (checkid(head, id));
        do
        {
            cout << "score: ";
            cin >> score;
        } while (score < 0 || score > 10);
        head = addStudent(head, name, id, score);
        temp = id;
    }
    return head;
}
void swap(student *&x, student *&y)
{
    student *temp = new student;
    temp->name = new char[10];
    strcpy(temp->name,x->name);
    temp->id = x->id;
    temp->score = x->score;
    x->name = y->name;
    x->id = y->id;
    x->score = y->score;
    y->name = temp->name;
    y->id = temp->id;
    y->score = temp->score;
}
student *sort(student *head)
{
    for (student *i = head; i != NULL; i = i->next)
    {
        for (student *j = i->next; j != NULL; j = j->next)
        {
            if (i->score > j->score)
            {
                swap(i, j);
            }
        }
    }
    return head;
}
void output(student *head)
{
    for (student *i = head; i != NULL; i = i->next)
    {
        cout << i->name << "," << i->id << "," << i->score << endl;
    }
}
student *del(student *head)
{
    student *pre;
    for (student *i=head;i!=NULL;i = i->next)
    {
        if (i->score<5)
        {
            if (i==head) head=i->next;
            else pre->next = i->next;
        }
        pre = i;
    }
    return head;
}
int main()
{
    student *head;
    student *head2;
    student *head3;
    head = input();
    cout<<"Danh sach truoc khi sap xep: "<<endl;
    output(head);
    cout<<"Danh sach sau khi sap xep: "<<endl;
    head2 = sort(head);
    output(head2);
    cout<<"Danh sach sau khi xoa diem <5: "<<endl;
    head3 = del(head2);
    output(head3);
    system("pause");
}