#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Person.h"
#include "List.h"
#include <iomanip>

using namespace std;

int main()
{
	// Läs in startlistan
	ifstream fin("startlista.txt");
	string line;

	vector<Person> tmpVec;

	getline(fin, line);
	while(getline(fin, line))
	{
		stringstream ss(line);
		Person person;
		ss >> person.start_number >> person.first_name >> person.last_name;
		
		string t;
		while(ss >> t)
			person.club += (person.club == "" ? "" : " ") + t;
		
		tmpVec.push_back(person);
	}

	fin.close();
	fin.open("resultat.txt");

	// Läs in tiden
	getline(fin, line);
	while(getline(fin, line))
	{
		stringstream ss(line);
		string crap;
		int start_number;
		float time;

		ss >> start_number >> crap >> crap >> crap >> crap >> crap >> time;

		// Lägg till tiden vid rätt person.
		for(int i = 0; i < tmpVec.size(); i++)
		{
			if(tmpVec[i].start_number == start_number)
				tmpVec[i].time = time;
		}
	}

	Node* personList = nullptr;

	for(int i = 0; i < tmpVec.size(); i++)
		insert(personList, tmpVec[i]);

	ofstream utdata("utdata.txt");

	int w = 10;
	cout << left << setw(7) << "Plats" << setw(12) << "Sluttid" << setw(10) << "Förnamn" << setw(17) << "Efternamn" << setw(w) << "Klubb" << endl;

	// Testa skriv ut
	print(cout, personList, 1);
	
	cin.get();
	fin.close();
}