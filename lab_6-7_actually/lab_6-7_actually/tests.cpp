#include "tests.h"


//Flight tests
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
	Repo <Flight> r;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	r.add(f1);

	assert(r.get_size() == 1);
}

void test_get_all()
{
	Repo <Flight> r;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	r.add(f1);
	assert(r.get_all().front() == f1);
}

void test_get_size()
{
	Repo <Flight> r;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	r.add(f1);

	assert(r.get_size() == 1);
}

void test_update()
{
	Repo <Flight> r;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	r.add(f1);

	r.update(f1, 22, name1, 22);

	assert(r.get_all().front().get_num_f() == 22);
}

void test_del()
{
	Repo <Flight> r;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	r.add(f1);
	assert(r.get_size() == 1);
	r.del(f1);
	assert(r.get_size() == 0);
}

//Service tests

void test_add_s()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add(f1);
	assert(s.get_size() == 1);
}

void test_get_all_s()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add(f1);
	assert(s.get_all().front() == f1);
}

void test_get_size_s()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add(f1);
	assert(s.get_size() == 1);
}

void test_get_cart_size()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add_to_cart(f1);
	assert(s.get_cart_size() == 1);
}

void test_update_s()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add(f1);
	s.update(f1, 22, name1, 22);
	assert(s.get_all().front().get_num_f() == 22);
	assert(s.get_all().front().get_num_s() == 22);
}

void test_del_s()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add(f1);
	assert(s.get_size() == 1);
	s.del(f1);
	assert(s.get_size() == 0);
}

void test_add_to_cart()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add_to_cart(f1);
	assert(s.get_cart_size() == 1);
}

void test_get_all_cart()
{
	Service <Repo<Flight>> s;
	char* name1 = new char[4];
	strcpy_s(name1, strlen("Ion") + 1, "Ion");
	Flight f1(1, name1, 1);
	s.add_to_cart(f1);

	assert(s.get_all_cart().front() == f1);
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
	test_update();
	test_del();

	//Service
	test_add_s();
	test_get_all_s();
	test_get_size_s();
	test_get_cart_size();
	test_update_s();
	test_del_s();
	test_add_to_cart();
	test_get_all_cart();
}