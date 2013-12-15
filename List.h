#pragma once

#include "Person.h"

struct Node
{
	Node()
	{
		pNext = nullptr;
	}

	Node(Node* pNext, Person data)
	{
		this->pNext = pNext;
		this->data = data;
	}

	Person data;
	Node* pNext;
};

bool insert(Node*& pNode, const Person& data);
bool remove(Node*& pNode, const Person& data);
bool empty(Node* pNode);
bool member(Node* pNode, const Person& data);
void print(std::ostream& os, Node* pNode, int place);
void clear(Node*& pNode);
int size(Node* pNode);

void set_time(Node*& pNode, const int& start_number, const float& time);
void sort_by_time(Node*& pNode);
