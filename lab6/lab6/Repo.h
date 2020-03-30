#pragma once

#include <list>

#include "Flight.h"

//template <class Flight>

class Repo
{
private:
	list <Flight> flights;
public:
	Repo();
	~Repo();
	void add(Flight f);
	list<Flight> get_all();
	int get_size();
	Flight find_elem(int given_num_s);
};