#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	int start_number;
	float time;
	string first_name;
	string last_name;
	string club;
};

bool operator< (const Person& lhs, const Person& rhs);
bool operator> (const Person& lhs, const Person& rhs);
bool operator== (const Person& lhs, const Person& rhs);
std::ostream& operator<<(std::ostream& os, const Person& obj);