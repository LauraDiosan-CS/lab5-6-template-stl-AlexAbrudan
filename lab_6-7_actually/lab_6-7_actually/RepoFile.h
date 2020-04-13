#pragma once
#include "Repo.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

template <class t> class RepoFile: public Repo<t>
{
private:
	ifstream fin;
	ofstream fout;
public:
	RepoFile();
	~RepoFile();
	void load_from_file();
	void save_to_file();
};

template <class t> RepoFile<t>::~RepoFile() {}
template <class t> RepoFile<t>::RepoFile()
{
	fin.open("zboruri.in");
	char* name = new char[10];
	int num_f, num_s;
	while (!fin.eof())
	{
		fin >> num_f >> name >> num_s;
		if (name != "")
		{
			Flight f(num_f, name, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] name;
	fin.close();
}

template <class t> void RepoFile<t>::load_from_file()
{
	fin.open("zboruri.in");
	this->flights.clear();
	char* name = new char[10];
	int num_f, num_s;
	while (!fin.eof())
	{
		fin >> num_f >> name >> num_s;
		if (strcmp(name, "") != 0)
		{
			Flight f(num_f, name, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] name;
	fin.close();
}

template <class t> void RepoFile<t>::save_to_file()
{
	fout.open("zboruri.out");
	list <Flight> res = this->get_all();
	while (!res.empty())
	{
		fout << res.front()<<endl;
		res.pop_front();
	}
	fout.close();
}

