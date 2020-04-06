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
	strcpy_s(name, strlen("Ion") + 1, "Ion");
	Flight f(1, name, 1);
	assert(strcmp(f.get_name(), name) == 0);
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
	strcpy_s(new_name, 1 + strlen("Ana"), "Ana");
	f.set_name(new_name);
	assert(strcmp(f.get_name(), new_name) == 0);
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

	Repos <Flight> r;
	r.add_elem(f1);
	assert(r.get_size() == 1);
}

void test_get_all()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repos <Flight> r;
	r.add_elem(f1);
	assert(r.get_all().front() == f1);
}

void test_get_size()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repos <Flight> r;
	r.add_elem(f1);
	assert(r.get_size() == 1);
}

//void test_modify()
//{
//	char* name1 = new char[4];
//	strcpy_s(name1, strlen("Ion") + 1, "Ion");
//	Flight f1(1, name1, 1);
//
//	Repos <Flight> r;
//	r.add_elem(f1);
//	r.modify(1, 22, name1);
//	assert(r.get_all().front().get_num_f() == 22);
//}

void test_del()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repos <Flight> r;
	r.add_elem(f1);
	r.del(f1);
	assert(r.get_size() == 0);
}

void test_get_elem()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Repos <Flight> r;
	r.add_elem(f1);
	assert(r.get_elem(1) == f1);
}

void test_add_s()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Service <Repos<Flight>> s;

	s.add(f1);

	assert(s.get_size() == 1);
}

void test_get_all_s()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Service <Repos<Flight>> s;

	s.add(f1);

	assert(s.get_all().front() == f1);
}

//void test_modify_s()
//{
//	char* name1 = new char[4];
//	strcpy_s(name1, strlen("Ion") + 1, "Ion");
//	Flight f1(1, name1, 1);
//
//	Service <Repos<Flight>> s;
//
//	s.add(f1);
//	s.modify(1, 22, name1);
//
//	assert(s.get_all().front().get_num_f() == 22);
//}

void test_del_s()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Service <Repos<Flight>> s;

	s.add(f1);

	s.del(f1);

	assert(s.get_all().empty() == true);
}

void test_get_size_s()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Service <Repos<Flight>> s;

	assert(s.get_size() == 0);

	s.add(f1);

	assert(s.get_size() == 1);
}

void test_get_elem_s()
{
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);

	Service <Repos<Flight>> s;

	s.add(f1);

	assert(s.get_elem(1) == f1);
}

void all_tests()
{
	//Flight
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
	//Repo
	test_add();
	test_get_all();
	test_get_size();
	//test_modify();
	//test_del();
	test_get_elem();

	//Service
	test_add_s();
	test_get_all_s();
	//test_modify_s();
	//test_del_s();
	test_get_size_s();
	test_get_elem_s();
}