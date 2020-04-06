#pragma once
#include "Repo.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class t>
class RepoFile :
	public Repos<t>
{
private:
	const char* fis;

public:
	RepoFile();
	RepoFile(const char* fileName);
	void load(const char* fileName);
};


template <class t> RepoFile<t>::RepoFile() {}

template <class t> RepoFile<t>::RepoFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int num_f = 0, num_s = 0;
	while (!f.eof()) {
		f >> num_f >> nume >> num_s;
		if (nume != "") {
			Flight f(num_f, nume, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] nume;
	f.close();
}

template <class t> void RepoFile<t>::load(const char* fileName)
{
	this->flights.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	int num_f, num_s;
	while (!f.eof())
	{
		f >> num_f >> nume >> num_s;
		if (strcmp(nume, "") != 0)
		{
			Flight f(num_f, nume, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] nume;
	f.close();
}
