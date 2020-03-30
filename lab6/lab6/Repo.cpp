#include "Repo.h"
#include <iostream>

using namespace std;


Repo::Repo()
{
	this->flights.clear();
}

Repo::~Repo()
{
	this->flights.clear();
}

void Repo::add(Flight f)
{
	this->flights.push_back(f);
}

list<Flight> Repo::get_all()
{
	/*while (!this->flights.empty())
	{
		cout << this->flights.front() << " ";
		this->flights.pop_front();
	}
	cout << endl;*/
	return this->flights;

}

int Repo::get_size()
{
	return this->flights.size();
}

Flight Repo::find_elem(int given_num_s)
{
	Flight found_it;
	do
	{
		found_it = this->flights.front();
		this->flights.pop_front();
	} while (!this->flights.empty() || found_it.get_num_s() == given_num_s);
	return found_it;
}