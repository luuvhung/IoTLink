#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Node {
public:
	int data;
	shared_ptr<Node> next;
	Node();
	Node(int data);
	~Node();
};
class List {
private:
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
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
List::~List() {

}
void List::addElement(int data) {
	shared_ptr<Node> temp = make_shared<Node>(data);
	if (head == nullptr) head = tail = temp;
	else {
		tail->next = temp;
		tail = temp;
	}
}
void List::insertElement(int data,int index) {
	shared_ptr<Node> temp = make_shared<Node>(data);
	if (index == 0) {
		temp->next = head;
		head = temp;
	}
	else {
		shared_ptr<Node> p = head;
		int i = 1;
		while (i < index && p != nullptr) {
			i++;
			p = p->next;
		}
		if (p != nullptr) {
			temp->next = p->next;
			p->next = temp;
		}
	}
	if (temp->next == nullptr) tail = temp;//nếu phần tử được chèn vào vị trí cuối
}
void List::delElement(int index) {
	if (head != nullptr) {
		if (index == 0) head = head->next;
		else {
			shared_ptr<Node> p = head;
			int i = 1;
			while (i < index && p->next != nullptr) {
				i++;
				p = p->next;
			}
			if (p->next != nullptr) {
				p->next = p->next->next;
				if (p->next == nullptr) tail = p;//nếu xóa phần tử cuối cùng
			}
		}
	}
}
int List::searchElement(int data) {
	int index = 0;
	for (shared_ptr<Node> p = head; p != nullptr; p = p->next) {
		if (p->data == data) return index;
		index++;
	}
	return -1;
}
void List::printList() {
	for (shared_ptr<Node> p = head; p != nullptr; p = p->next) {
		cout << p->data << " ";
	}
}