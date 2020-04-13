#pragma once
#include "Repo.h"
#include "Flight.h"
#include <iostream>
using namespace std;

template <class t>
class Service
{
private:
	t r;
	t cart;
	const int NUMBER_OF_SEATS = 5;
public:
	Service();
	~Service();
	void add(Flight f);
	void del(const Flight& f);
	void update(const Flight& f, int new_num_f, char* new_name, int new_num_s);
	list<Flight> get_all();
	void add_to_cart(Flight f);
	list <Flight> get_all_cart();
	//Flight get_elem(const Flight& f);
	bool in_vector(int val, int x[], int dim);
	int get_size();
	int get_cart_size();
	int update_booking(Flight f, int new_num_s);
	bool existing_flight(Flight f, list<Flight> res);
	void save_to_file();
};

template <class t> Service<t>::Service() {}
template <class t> Service<t>::~Service() {}
template <class t> void Service<t>::add(Flight f)
{
	this->r.add(f);
}

template <class t> void Service<t>::del(const Flight& f)
{
	this->r.del(f);
}

template <class t> void Service<t>::update(const Flight& f, int new_num_f, char* new_name, int new_num_s)
{
	this->r.update(f, new_num_f, new_name, new_num_s);
}

template <class t> list<Flight> Service<t>::get_all()
{
	return this->r.get_all();
}

template <class t> bool Service<t>::in_vector(int val, int x[], int dim)
{
	for (int i = 0; i < dim; i++)
		if (val == x[i])
			return true;
	return false;
}

template <class t> void Service<t>::add_to_cart(Flight f)
{
	int dim = 0;
	int cart_num_s[500] = { 0 };
	list <Flight> from_cart = this->cart.get_all();

	int dim2 = 0;
	int all_num_s[500] = { 0 };
	list <Flight> all = this->r.get_all();

	while (!from_cart.empty())
	{
		cart_num_s[dim++] = from_cart.front().get_num_s();
		from_cart.pop_front();
	}
	while (!all.empty())
	{
		all_num_s[dim2++] = all.front().get_num_s();
		all.pop_front();
	}

	if (!this->in_vector(f.get_num_s(), cart_num_s, dim))
		this->cart.add(f);
	else
	{
		cout << "Numarul de loc este luat. Incercati locurile: ";
		for (int i = 0; i < NUMBER_OF_SEATS; i++)
			if (!this->in_vector(all_num_s[i], cart_num_s, dim))
				cout << i << " ";
		cout << endl;
	}

}

template <class t> list <Flight> Service<t>::get_all_cart()
{
	return this->cart.get_all();
}

template <class t> int Service<t>::get_size()
{
	return this->r.get_size();
}

template <class t> int Service<t>::get_cart_size()
{
	return this->cart.get_size();
}

template <class t> bool Service<t>::existing_flight(Flight f, list<Flight> res)
{
	bool ok = false;
	while (!res.empty())
	{
		if (f == res.front())
			ok = true;
		res.pop_front();
	}
	if (ok)
		return true;
	else
		return false;
}

template <class t> int Service<t>::update_booking(Flight f, int new_num_s)
{
	int dim = 0;
	int cart_num_s[500] = { 0 };
	list <Flight> from_cart = this->cart.get_all();
	list <Flight> res = this->cart.get_all();

	while (!from_cart.empty())
	{
		cart_num_s[dim++] = from_cart.front().get_num_s();
		from_cart.pop_front();
	}

	if (!this->existing_flight(f, res))
	{
		//cout << "Rezervarea nu exista! " << endl;
		return -1;
	}
	else
	{
		if (1 <= new_num_s && new_num_s <= NUMBER_OF_SEATS && !this->in_vector(new_num_s, cart_num_s, dim))
		{
			this->cart.update(f, f.get_num_f(), f.get_name(), new_num_s);
			//cout << "Booking updated successfully! " << endl;
			return 0;
		}
		else
			if (this->in_vector(new_num_s, cart_num_s, dim))
			{
				//cout << "Locul introdus este ocupat! " << endl;
				return -2;
			}
			else
			{
				//cout << "Locul introdus nu exista! " << endl;
				return -3;
			}
	}
}

template <class t> void Service<t>::save_to_file()
{
	this->r.save_to_file();
}