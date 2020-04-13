#pragma once
#include "Service.h"
#include "Flight.h"
#include "RepoFile.h"
#include <iostream>
using namespace std;


class UI
{
private:
	Service <RepoFile<Flight>> s;
public:
	void menu();
	void add();
	void update();
	void del();
	void all();
	void add_to_cart();
	void all_cart();
	void update_booking();
	void uwu();
};

