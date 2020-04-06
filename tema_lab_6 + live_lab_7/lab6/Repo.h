#pragma once
#include "Flight.h"
#include <list>

template <class T>
class Repos
{
protected:
	list<T> flights;
public:
	Repos();
	~Repos();
	void add_elem(T el);
	list<T> get_all();
	int get_size();
	void modify(const T& f1, const T& f2);
	void del(T del_fl);
	T get_elem(int given_num_s);
};

template <class T> Repos <T>::Repos()
{
	this->flights.clear();
}

template <class T> Repos<T>::~Repos()
{
	this->flights.clear();
}

template <class T> void Repos<T>::add_elem(T el)
{
	this->flights.push_back(el);
}

template <class T> list<T> Repos<T>::get_all()
{
	return this->flights;
}

template <class T> int Repos<T>::get_size()
{
	return this->flights.size();
}

template <class T> void Repos<T>::modify(const T& f1, const T& f2)
{
	//list <Flight>::iterator it = find(this->flights.begin(), this->flights.end(), mod_f);
	//this->flights[it].set_num_f(new_num_f);
	//this->flights[it].set_name(new_name);
	//this->flights[it].set_num_s(new_num_s);
	/*int i = 0;
	for (T crt : flights)
	{
		if (crt == flights)
			f1 = f2;
		i++;
	}*/
}

template <class T> T Repos<T>::get_elem(int given_num_s)
{
	
	while (!this->flights.empty())
	{
		if (given_num_s != this->flights.front().get_num_s())
			this->flights.pop_front();
		else
			return this->flights.front();
	}
}

template <class T> void Repos<T>::del(T del_f)
{
	list <Flight>::iterator it = find(this->flights.begin(), this->flights.end(), del_f);
	this->flights.erase(it);
}