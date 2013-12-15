#include "Person.h"
#include <iomanip>

bool operator< (const Person& lhs, const Person& rhs)
{
	return lhs.time < rhs.time;
}

bool operator> (const Person& lhs, const Person& rhs)
{
	return lhs.time > rhs.time;
}

bool operator== (const Person& lhs, const Person& rhs)
{
	return lhs.start_number == rhs.start_number;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	int w = 15;
	os << left << setw(12) << obj.time << setw(10) << obj.first_name << setw(17) << obj.last_name << setw(20) << obj.club << endl;

	return os;
}