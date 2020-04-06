#include "Flight.h"


Flight::Flight()
{
	this->name = NULL;
	this->num_f = -1;
	this->num_s = -1;
}

Flight::Flight(int num_f, char* name, int num_s)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->num_f = num_f;
	this->num_s = num_s;
}

Flight::Flight(const Flight& f)
{
	this->name = new char[strlen(f.name) + 1];
	strcpy_s(this->name, strlen(f.name) + 1, f.name);
	this->num_f = f.num_f;
	this->num_s = f.num_s;
}

Flight::~Flight()
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}

}

char* Flight::get_name()
{
	return this->name;
}

int Flight::get_num_f()
{
	return this->num_f;
}

int Flight::get_num_s()
{
	return this->num_s;
}

void Flight::set_name(char* new_name)
{
	if (this->name)
	{
		delete[] this->name;
		this->name = NULL;
	}
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name) + 1, new_name);
}

void Flight::set_num_f(int new_num_f)
{
	this->num_f = new_num_f;
}

void Flight::set_num_s(int new_num_s)
{
	this->num_s = new_num_s;
}

Flight& Flight::operator=(const Flight& f)
{
	this->set_name(f.name);
	this->set_num_f(f.num_f);
	this->set_num_s(f.num_s);
	return *this;
}

bool Flight::operator==(const Flight& f)
{
	return (strcmp(this->name, f.name) == 0 && this->num_f == f.num_f && this->num_s == f.num_s);
}

ostream& operator<<(ostream& os, const Flight& f)
{
	os << f.num_f << " " << f.name << " " << f.num_s;
	return os;
}