#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node();
	Node(int);
	~Node();
};
class List {
private:
	Node* head;
	Node* tail;
public:
	List();
	~List();
	void addElement(int);
	void insertElement(int, int);
	void delElement(int);
	void printList();
	int searchElement(int);
};
int main() {
	{
		List list;
		bool check = true;
		while (check) {
			int select;
			system("cls");
			cout << "1. Them" << endl
				<< "2. Chen" << endl
				<< "3. Xoa" << endl
				<< "4. In" << endl
				<< "5. Tim kiem " << endl
				<< "0. Thoat" << endl
				<< "Nhap lua chon: ";
			cin >> select;
			switch (select)
			{
			case 1: {
				int nums;
				cout << "Nhap so phan tu can them: "; cin >> nums;
				for (int i = 0; i < nums; i++) {
					int data;
					cout << "Nhap phan tu " << i << ": "; cin >> data;
					list.addElement(data);
				}
				break;
			}
			case 2: {
				int index, data;
				cout << "Nhap vi tri: "; cin >> index;
				cout << "Nhap gia tri: "; cin >> data;
				list.insertElement(data, index);
				break;
			}
			case 3: {
				int index;
				cout << "Nhap vi tri can xoa: "; cin >> index;
				list.delElement(index);
				break;
			}
			case 4: {
				list.printList();
				cout << endl;
				system("pause");
				break;
			}
			case 5: {
				cout << "Nhap gia tri can tim: ";
				int data; cin >> data;
				if (list.searchElement(data) == -1) cout << "Khong tim thay";
				else cout << "vi tri: " << list.searchElement(data);
				cout << endl;
				system("pause");
				break;
			}
			case 0: {
				check = false;
				break;
			}
			}
		}
	}
	_CrtDumpMemoryLeaks();
}

Node::Node() {
	data = 0;
	next = nullptr;
}
Node::Node(int data) {
	this->data = data;
	next = nullptr;
}
Node::~Node() {

}
List::List() {
	head = nullptr;
	tail = nullptr;
}
void List::addElement(int data) {
	Node* temp = new Node(data);
	if (head == nullptr) head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
}
void List::insertElement(int data, int index) {
	if (index == 0) {
		Node* temp = new Node(data);
		if (head == nullptr) head = tail = temp;
		else {
			temp->next = head;
			head = temp;
		}
	}
	else {
		int previous = 0;
		for (Node* p = head; p != nullptr; p = p->next) {
			if (previous == index - 1) {
				Node* temp = new Node(data);
				temp->next = p->next;
				p->next = temp;
				if (temp->next == nullptr) tail = temp;//nếu phần tử được thêm vào cuối thì cập nhật lại tail;
				break;
			}
			previous++;
		}
	}
}
void List::delElement(int index) {
	if (head != nullptr) {
		if (index == 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			int previous = 0;
			for (Node* p = head; p->next != nullptr; p = p->next) {
				if (previous == index - 1) {
					Node* temp = p->next;
					p->next = temp->next;
					if (temp->next == nullptr) tail = p;//nếu xóa phần tử cuối thì cập nhật lại tail
					delete temp;
					break;
				}
				previous++;
			}
		}
	}
}
int List::searchElement(int data) {
	int index = 0;
	for (Node* p = head; p != nullptr; p = p->next) {
		if (p->data == data) return index;
		index++;
	}
	return -1;
}
void List::printList() {
	int index = 0;
	for (Node* p = head; p != nullptr; p = p->next) {
		cout << "Phan tu "<< index <<": " << p->data << endl;
		index++;
	}
}
List::~List() {
	Node* p = head;
	while (p != nullptr) {
		Node* temp = p;
		p = p->next;
		delete temp;
	}
}