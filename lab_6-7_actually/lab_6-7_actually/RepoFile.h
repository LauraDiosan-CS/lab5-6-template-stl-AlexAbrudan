#pragma once
#include "Repo.h"
#include <fstream>

using namespace std;


class RepoFile:
	public Repo<Flight>
{
private:
	const char* fis;
public:
	RepoFile();
	~RepoFile();
	RepoFile(const char* fileName);
	void load_from_file(const char* fileName);
};

