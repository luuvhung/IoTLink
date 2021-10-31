#pragma once
#include"People.h"
class Node
{
public:
	People* data;
	Node* next;
	Node();
	~Node();
	static void addElement(Node*&, People*);
	static void removeElement(Node*&, Node*);
};

