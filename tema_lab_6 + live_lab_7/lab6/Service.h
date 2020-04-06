#pragma once
#include "Repo.h"
#include <iostream>
using namespace std;


template <class t>
class Service
{
private:
	t r;
	t cart;
public:
	Service();
	~Service();
	void add(Flight f);
	void modify(Flight f, Flight f2);
	void del(Flight f);
	Flight get_elem(int given_num_s);
	list<Flight> get_all();
	int get_size();
	void add_to_cart(int num_f, char* name, int num_s);
	int get_size_cart();
	list <Flight> get_all_cart();
	
};


template <class t> Service<t>::Service() {}
template <class t> Service<t>::~Service() {}
template <class t> void Service<t>::add(Flight f)
{
	this->r.add_elem(f);
}

template <class t> void Service <t>::modify(Flight f, Flight f2)
{
	this->r.modify(f, f2);
}

template <class t> void Service <t>::del(Flight f)
{
	this->r.del(f);
}

template <class t> list<Flight> Service<t>::get_all()
{
	return this->r.get_all();
}

template <class t> Flight Service<t>::get_elem(int given_num_s)
{
	return this->r.get_elem(given_num_s);
}

template <class t> int Service <t>::get_size()
{
	return this->r.get_size();
}

template <class t> list <Flight> Service<t>::get_all_cart()
{
	return this->cart.get_all();
}

template <class t> void Service <t>::add_to_cart(int num_f, char* name, int num_s)
{
	//Flight f(num_f, name, num_s);
	int seat_numbers[40] = { 0 };
	int all_seat_numbers[40] = { 0 };
	int dim = 0;
	int dim_a = 0;
	list <Flight> res = this->get_all_cart();
	list <Flight> res_all = this->get_all();
	
	while (!res.empty())
	{
		seat_numbers[dim++] = res.front().get_num_s();
		res.pop_front();
	}
	while (!res_all.empty())
	{
		all_seat_numbers[dim_a++] = res_all.front().get_num_s();
		res_all.pop_front();
	}

	if (1 <= num_s && num_s <= 40)
	{
		if (dim == 0)
		{
			Flight f(num_f, name, num_s);
			this->cart.add_elem(f);
		}
		else
			for (int i = 0; i < dim; i++)
			{
				if (num_s != seat_numbers[i])
				{
					Flight f(num_f, name, num_s);
					this->cart.add_elem(f);
				}
			}
	}
	for (int i = 0; i < dim; i++)
	{
		if (num_s == seat_numbers[i])
		{
			cout << "Rezervarea exista deja. Incercati locurile: ";
			if (all_seat_numbers[i] != seat_numbers[i])
				cout << all_seat_numbers[i] << " ";
			cout << endl;
		}
	}
}

template <class t> int Service<t>::get_size_cart()
{
	return this->cart.get_size();
}

