#pragma once

#include "Service.h"
#include "Flight.h"
#include <iostream>
using namespace std;

class UI
{
private:
	Service <Repos<Flight>> s;
public:
	void show_menu();
	void add();
	void modify();
	void del();
	void show_all();
	void get_elem();
	void book_elem();
	void show_all_booked();
	void UwU();
};

