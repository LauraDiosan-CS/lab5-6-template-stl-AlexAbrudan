#pragma once
#include "Flight.h"
#include <list>

using namespace std;

template <class t>
class Repo
{
protected:
	list <t> flights;
public:
	Repo();
	~Repo();
	void add(t f);
	int update(const t& f, int new_num_f, char* new_name, int new_num_s);
	int del(const t& f);
	int get_size();
	list <t> get_all();
	t get_elem(const t& f);
};


template <class t> Repo<t>::Repo() {}
template <class t> Repo<t>::~Repo() {}
template <class t> void Repo<t>::add(t f)
{
	this->flights.push_back(f);
}

template <class t> list<t> Repo<t>::get_all()
{
	return this->flights;
}

template <class t> t Repo<t>::get_elem(const t& f)
{
	list <Flight>::iterator it = find(this->flights.begin(), this->flights.end(), f);
	if (it != this->flights.end())
		return distance(this->flights.begin(), it);
	return -1;
}

template <class t> int Repo<t>::update(const t& f, int new_num_f, char* new_name, int new_num_s)
{
	list <Flight>::iterator it = find(this->flights.begin(), this->flights.end(), f);
	if (it != this->flights.end())
	{
		(*it).set_num_f(new_num_f);
		(*it).set_name(new_name);
		(*it).set_num_s(new_num_s);
		return 0;
	}
	return -1;
}

template <class t>int Repo<t>::del(const t& f)
{
	list <Flight>::iterator it =find(this->flights.begin(), this->flights.end(), f);
	if (it != this->flights.end())
	{
		this->flights.erase(it);
		return 0;
	}
	return -1;
}

template <class t> int Repo<t>::get_size()
{
	return this->flights.size();
}