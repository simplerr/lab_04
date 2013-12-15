#include <iostream>
#include "List.h"
#include "Person.h"
#include <iomanip>

using namespace std;

bool insert(Node*& pNode, const Person& data)
{
	if(pNode != nullptr)
	{
		// Insert infront
		if(data < pNode->data)
		{
			Node* newNode = new Node(pNode, data);
			pNode = newNode;
			return true;
		}
		else if(data > pNode->data)
		{
			insert(pNode->pNext, data);
		}
		else
			return false;
	}
	else if(pNode == nullptr)
	{
		pNode = new Node(nullptr, data);
		return true;
	}
}

bool remove(Node*& pNode, const Person& data)
{
	if(pNode == nullptr)
		return false;

	if(pNode->data == data)
	{
		// pNext != nullptr?
		if(pNode->pNext != nullptr)
		{
			Node* tmpNode = pNode->pNext;
			delete pNode;
			pNode = tmpNode;
		}
		else
		{
			delete pNode;
			pNode = nullptr;
		}
	}
	else
	{
		remove(pNode->pNext, data);
	}

	return true;
}

bool empty(Node* pNode)
{
	return pNode == nullptr ? true : false;
}

bool member(Node* pNode, const Person& data)
{
	if(pNode == nullptr)
		return false;

	if(pNode->data == data)
		return true;
	else
		member(pNode->pNext, data);
}

void print(std::ostream& os, Node* pNode, int place)
{
	if(pNode == nullptr)
		return;

	os << setw(7) << place << pNode->data;

	if(pNode->pNext == nullptr)
	{
		os << endl;
	}
	else
		print(os, pNode->pNext, ++place);
}

void clear(Node*& pNode)
{
	if(pNode == nullptr)
		return;

	clear(pNode->pNext);
	delete pNode;
	pNode = nullptr;
}

int size(Node* pNode)
{
	if(pNode == nullptr)
		return 0;

	return size(pNode->pNext) + 1;
}

// Nya

void set_time(Node*& pNode, const int& start_number, const float& time)
{
	if(pNode == nullptr)
		return;

	if(pNode->data.start_number == start_number)
	{
		pNode->data.time = time;
		return;
	}
	else
		set_time(pNode->pNext, start_number, time);
}

void sort_by_time(Node*& pNode)
{

}