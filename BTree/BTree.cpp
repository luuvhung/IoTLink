#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node();
	Node(int);
	~Node();
};
class BTree {
private:
	Node* root;
	void addElement(Node*&, int);//thêm node vào cây
	void delElement(Node*&, int);//xóa node có giá trị data
	Node* leftMost(Node*);//tìm node bé nhất
	void printLNR(Node*);//in theo LNR
	Node* searchElement(Node*,int);//tìm kiếm node có giá trị data
	void cleanTree(Node*&);//xóa cây
public:
	BTree();
	~BTree();
	void addElement(int);
	void printLNR();
	void delElement(int);
	Node* searchElement(int);
};
void menu(BTree&);
int main() {
	{
		BTree btree;
		menu(btree);
		system("pause");
	}
	_CrtDumpMemoryLeaks();
}

Node::Node() {
	data = 0;
	left = nullptr;
	right = nullptr;
}
Node::Node(int data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
}
Node::~Node() {}
BTree::BTree() {
	root = nullptr;
}
void BTree::cleanTree(Node*& node) {
	if (node != nullptr) {
		cleanTree(node->left);
		cleanTree(node->right);
		delete(node);
	}
}
BTree::~BTree() {
	cleanTree(root);
}
void BTree::addElement(Node* &node,int data) {
	if (node == nullptr) {
		Node* temp = new Node(data);
		node = temp;
	}
	else if (data > node->data) addElement(node->right, data);
	else if (data < node->data) addElement(node->left, data);
}
void BTree::addElement(int data) {
	addElement(root, data);
}

void BTree::printLNR(Node* node) {
	if (node != nullptr) {
		printLNR(node->left);
		cout << node->data << " ";
		printLNR(node->right);
	}
}
void BTree::printLNR() {
	printLNR(root);
}

Node* BTree::leftMost(Node* node) {
	while (node->left != nullptr) node = node->left;
	return node;
}
void BTree::delElement(Node* &node, int data) {
	if (node != nullptr) {
		if (data < node->data) delElement(node->left, data);
		else if (data > node->data) delElement(node->right, data);
		else {
			Node* temp = node;
			if (node->left == nullptr) node = node->right;
			else if (node->right == nullptr) node = node->left;
			else {
				Node* p = leftMost(node->right);
				node->data = p->data;
				delElement(node->right, p->data);
			}
			delete temp;
		}
	}
}
void BTree::delElement(int data) {
	delElement(root, data);
}
Node* BTree::searchElement(Node* node, int data) {
	if (node != nullptr) {
		if (data > node->data) return searchElement(node->right, data);
		else if (data < node->data) return searchElement(node->left, data);
		else return node;
	}
	return nullptr;
}
Node* BTree::searchElement(int data) {
	Node* node = searchElement(root, data);
	if (node == nullptr) cout << "Khong tim thay";
	else {
		cout << "Da tim thay";
	}
	return node;
}
void menu(BTree &btree){
	bool check = true;
	while (check) {
		int select;
		system("cls");
		cout << "1. Them" << endl
			<< "2. Xoa" << endl
			<< "3. In" << endl
			<< "4. Tim kiem " << endl
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
				btree.addElement(data);
			}
			break;
		}
		case 2: {
			int data;
			cout << "Nhap gia tri can xoa: "; cin >> data;
			btree.delElement(data);
			break;
		}
		case 3: {
			btree.printLNR();
			cout << endl;
			system("pause");
			break;
		}
		case 4: {
			cout << "Nhap gia tri can tim: ";
			int data; cin >> data;
			btree.searchElement(data);
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