#include "tests.h"


void test_constructor1()
{
	Flight f;
	assert(f.get_name() == NULL);
	assert(f.get_num_f() == -1);
	assert(f.get_num_s() == -1);
}

void test_constructor2()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion")+1, "Ion");
	Flight f(1, name, 1);
	assert(strcmp(f.get_name(), name)==0);
	assert(f.get_num_f() == 1);
	assert(f.get_num_s() == 1);
}

void test_get_name()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	assert(strcmp(f.get_name(), name) == 0);
}

void test_get_num_f()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	assert(f.get_num_f() == 1);
}

void test_get_num_s()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	assert(f.get_num_s() == 1);
}

void test_set_name()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	char* new_name = new char[4];
	strcpy_s(new_name, 1+strlen("Ana"), "Ana");
	f.set_name(new_name);
	assert(strcmp(f.get_name(), new_name)==0);
}

void test_set_num_f()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	f.set_num_f(2);
	assert(f.get_num_f() == 2);
}

void test_set_num_s()
{
	char* name = new char[4];
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	f.set_num_s(2);
	assert(f.get_num_s() == 2);
}

void test_op_attrib()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	char* name2 = new char[4];
	strcpy_s(name2, 1 + strlen("Ana"), "Ana");
	Flight f2(1, name2, 1);

	f1 = f2;
	assert(strcmp(f1.get_name(), f2.get_name()) == 0);


}

void test_op_equals()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	char* name2 = new char[4];
	strcpy_s(name2, 1 + strlen("Ana"), "Ana");
	Flight f2(1, name2, 1);

	assert((f1 == f2) == false);
}

//Repo tests

void test_add()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repo r;

	r.add(f1);

	assert(r.get_size() == 1);
}

void test_get_size()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repo r;

	r.add(f1);

	assert(r.get_size() == 1);
}

void test_get_all()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repo r;

	r.add(f1);

	list <Flight> res;
	res = r.get_all();
	assert(res.front() == f1);
}

void all_tests()
{
	test_constructor1();
	test_constructor2();
	test_get_name();
	test_get_num_f();
	test_get_num_s();
	test_set_name();
	test_set_num_f();
	test_set_num_s();
	test_op_attrib();
	test_op_equals();
	test_add();
	test_get_size();
	test_get_all();
}