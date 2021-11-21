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
void BTree::cleanTree(Node*& leaf) {
	if (leaf != nullptr) {
		cleanTree(leaf->left);
		cleanTree(leaf->right);
		delete(leaf);
	}
}
BTree::~BTree() {
	cleanTree(root);
}
void BTree::addElement(Node* &leaf,int data) {
	if (leaf == nullptr) {
		Node* temp = new Node(data);
		leaf = temp;
	}
	else if (data > leaf->data) addElement(leaf->right, data);
	else if (data < leaf->data) addElement(leaf->left, data);
}
void BTree::addElement(int data) {
	addElement(root, data);
}

void BTree::printLNR(Node* leaf) {
	if (leaf != nullptr) {
		printLNR(leaf->left);
		cout << leaf->data << " ";
		printLNR(leaf->right);
	}
}
void BTree::printLNR() {
	printLNR(root);
}

Node* BTree::leftMost(Node* leaf) {
	while (leaf->left != nullptr) leaf = leaf->left;
	return leaf;
}
void BTree::delElement(Node* &leaf, int data) {
	if (leaf != nullptr) {
		if (data < leaf->data) delElement(leaf->left, data);
		else if (data > leaf->data) delElement(leaf->right, data);
		else {
			Node* temp = leaf;
			if (leaf->left == nullptr) leaf = leaf->right;
			else if (leaf->right == nullptr) leaf = leaf->left;
			else {
				Node* p = leftMost(leaf->right);
				leaf->data = p->data;
				delElement(leaf->right, p->data);
			}
			delete temp;
		}
	}
}
void BTree::delElement(int data) {
	delElement(root, data);
}
Node* BTree::searchElement(Node* leaf, int data) {
	if (leaf != nullptr) {
		if (data > leaf->data) return searchElement(leaf->right, data);
		else if (data < leaf->data) return searchElement(leaf->left, data);
		else return leaf;
	}
	return nullptr;
}
Node* BTree::searchElement(int data) {
	Node* leaf = searchElement(root, data);
	if (leaf == nullptr) cout << "Khong tim thay";
	else {
		cout << "Da tim thay";
	}
	return leaf;
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