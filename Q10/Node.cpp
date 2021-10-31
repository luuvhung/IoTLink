#include "Node.h"
Node::Node()
{
	data = nullptr;
	next = nullptr;
}
Node::~Node()
{
	delete data;
}
void Node::addElement(Node*& head, People* data)
{
	Node* temp1 = new Node;
	Node* temp2;
	temp1->data = data;
	if (head == nullptr)
	{
		head = temp1;
	}
	else
	{
		temp2 = head;
		while (temp2->next != nullptr)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp1;
	}
}
void Node::removeElement(Node*& head, Node* node)
{
	Node* temp;
	if (node == head) head = head->next;
	else
	{
		temp = head;
		while (temp->next == node)
		{
			temp = temp->next;
		}
		temp->next = node->next;
	}
	delete node;
}