// Q10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "stdio.h"
#include "conio.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"
#include"Node.h"
using namespace std;
void input(Node*& head)
{
    bool ctn = true;
    while (ctn)
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
            char* name = new char[100];
            cout << "Name: ";
            cin >> name;
            Date birthday;
            cout << "Birthday(day,month,year): ";
            cin >> birthday.day >> birthday.month >> birthday.year;
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            int grade;
            cout << "Grade: ";
            cin >> grade;
            int num;
            cout << "Num of project: ";
            cin >> num;
            float* score = new float[num];
            for (int i = 0; i < num; i++)
            {
                cout << "Enter score project " << i + 1 << " : ";
                cin >> score[i];
            }
            People* st = new Student(name, birthday, idCode, grade, num, score);
            Node::addElement(head, st);
            break;
        }
        case 2:
        {
            char* name = new char[100];
            cout << "Name: ";
            cin >> name;
            Date birthday;
            cout << "Birthday(day,month,year): ";
            cin >> birthday.day >> birthday.month >> birthday.year;
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            int departmentId;
            cout << "Department ID: ";
            cin >> departmentId;
            Date joinedDate;
            cout << "Joined Day(day,month,year): ";
            cin >> joinedDate.day >> joinedDate.month >> joinedDate.year;
            int level;
            cout << "Level: ";
            cin >> level;
            People* stf = new Staff(name, birthday, idCode, departmentId, joinedDate, level);
            Node::addElement(head, stf);
            break;
        }
        case 3:
        {
            char* name = new char[100];
            cout << "Name: ";
            cin >> name;
            Date birthday;
            cout << "Birthday(day,month,year): ";
            cin >> birthday.day >> birthday.month >> birthday.year;
            int idCode;
            cout << "ID code: ";
            cin >> idCode;
            int departmentId;
            cout << "Department ID: ";
            cin >> departmentId;
            Date joinedDate;
            cout << "Joined Day(day,month,year): ";
            cin >> joinedDate.day >> joinedDate.month >> joinedDate.year;
            int level;
            cout << "Level: ";
            cin >> level;
            int Class;
            cout << "Class: ";
            cin >> Class;
            int subject, secondSubject;
            cout << "Subject, second subject: ";
            cin >> subject >> secondSubject;
            People* tc = new Teacher(name, birthday, idCode, departmentId, joinedDate, level, Class, Subjects(subject), Subjects(secondSubject));
            Node::addElement(head, tc);
            break;
        }
        case 4:
            ctn = false;
            break;
        }
    }
}
void printList(Node* head)
{
    for (Node* i = head; i != NULL; i = i->next)
    {
        i->data->printInfo();
    }
}
void swapNode(Node* node1,Node* node2)
{
    People* temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
void sortList(Node* head)
{
    for(Node* i=head;i!=nullptr;i=i->next)
        for (Node* j = i->next; j != nullptr; j=j->next)
        {
            if (dynamic_cast<Student*>(i->data) && dynamic_cast<Staff*>(j->data)) swapNode(i, j);
            if (dynamic_cast<Teacher*>(i->data) && dynamic_cast<Staff*>(j->data) && !dynamic_cast<Teacher*>(j->data)) swapNode(i, j);
        }
}
void printStudent(Node* head)
{
    for (Node* i = head; i != nullptr; i = i->next)
    {
        if (dynamic_cast<Student*>(i->data))
        {
            if (dynamic_cast<Student*>(i->data)->getAvgScore() > 5) i->data->printInfo();
        }
    }
}
int main()
{
{
        Node* head=nullptr;
        input(head);
        sortList(head);
        printList(head);
        printStudent(head);
        Node* i = head;
        while (i != nullptr)
        {
            i = head->next;
            Node::removeElement(head, head);
        }
}
_CrtDumpMemoryLeaks();
}