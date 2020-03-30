#pragma once

#include <ostream>

using namespace std;

class Flight
{
private:
	int num_f, num_s;
	char* name;
public:
	Flight();
	Flight(int num_f, char* name, int num_s);
	Flight(const Flight& f);
	~Flight();

	char* get_name();
	int get_num_f();
	int get_num_s();

	void set_name(char* new_name);
	void set_num_f(int new_num_f);
	void set_num_s(int new_num_s);

	Flight& operator=(const Flight& f);
	bool operator==(const Flight& f);

	friend ostream& operator<<(ostream& os, const Flight& f);
};

