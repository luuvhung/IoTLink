#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;
class Node {
public:
	int data;
	shared_ptr<Node> left;
	shared_ptr<Node> right;
	Node();
	Node(int);
	~Node();
};
class BTree {
private:
	shared_ptr<Node> root;
	void addElement(shared_ptr<Node>&, int);
	void delElement(shared_ptr<Node>&, int);
	shared_ptr<Node> leftMost(shared_ptr<Node>);
	void printLNR(shared_ptr<Node>);
	shared_ptr<Node> searchElement(shared_ptr<Node>, int);
public:
	BTree();
	~BTree();
	void addElement(int);
	void printLNR();
	void delElement(int);
	shared_ptr<Node> searchElement(int);
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

BTree::~BTree() {
}
void BTree::addElement(shared_ptr<Node>& leaf, int data) {
	if (leaf == nullptr) {
		shared_ptr<Node> temp = make_shared<Node>(data);
		leaf = temp;
	}
	else if (data > leaf->data) addElement(leaf->right, data);
	else if (data < leaf->data) addElement(leaf->left, data);
}
void BTree::addElement(int data) {
	addElement(root, data);
}

void BTree::printLNR(shared_ptr<Node> leaf) {//left node right
	if (leaf != nullptr) {
		printLNR(leaf->left);
		cout << leaf->data << " ";
		printLNR(leaf->right);
	}
}
void BTree::printLNR() {
	printLNR(root);
}

shared_ptr<Node> BTree::leftMost(shared_ptr<Node> leaf) {
	while (leaf->left != nullptr) leaf = leaf->left;
	return leaf;
}
void BTree::delElement(shared_ptr<Node>& leaf, int data) {
	if (leaf != nullptr) {
		if (data < leaf->data) delElement(leaf->left, data);
		else if (data > leaf->data) delElement(leaf->right, data);
		else {
			if (leaf->left == nullptr) leaf = leaf->right;
			else if (leaf->right == nullptr) leaf = leaf->left;
			else {
				shared_ptr<Node> p = leftMost(leaf->right);
				leaf->data = p->data;
				delElement(leaf->right, p->data);
			}
		}
	}
}
void BTree::delElement(int data) {
	delElement(root, data);
}
shared_ptr<Node> BTree::searchElement(shared_ptr<Node> leaf, int data) {
	if (leaf != nullptr) {
		if (data > leaf->data) return searchElement(leaf->right, data);
		else if (data < leaf->data) return searchElement(leaf->left, data);
		else return leaf;
	}
	return nullptr;
}
shared_ptr<Node> BTree::searchElement(int data) {
	shared_ptr<Node> leaf = searchElement(root, data);
	if (leaf == nullptr) cout << "Khong tim thay";
	else {
		cout << "Da tim thay";
	}
	return leaf;
}
void menu(BTree& btree) {
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