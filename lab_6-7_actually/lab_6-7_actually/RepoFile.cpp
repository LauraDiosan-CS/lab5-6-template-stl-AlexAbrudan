#include "RepoFile.h"


RepoFile::RepoFile() {}
RepoFile::~RepoFile() {}
RepoFile::RepoFile(const char* fileName)
{
	this->fis = fileName;
	ifstream f(fileName);
	string linie;
	char* name = new char[10];
	int num_f, num_s;
	while (!f.eof())
	{
		f >> num_f >> name >> num_s;
		if (name != "")
		{
			Flight f(num_f, name, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] name;
	f.close();
}

void RepoFile::load_from_file(const char* fileName)
{
	this->flights.clear();
	this->fis = fileName;
	ifstream f(fileName);
	char* name = new char[10];
	int num_f, num_s;
	while (!f.eof())
	{
		f >> num_f >> name >> num_s;
		if (strcmp(name, "") != 0)
		{
			Flight f(num_f, name, num_s);
			this->flights.push_back(f);
		}
	}
	delete[] name;
	f.close();
}