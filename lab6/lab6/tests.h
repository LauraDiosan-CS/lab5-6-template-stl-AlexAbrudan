#pragma once
#include "Repo.h"
#include "Flight.h"
#include <assert.h>

//Flight tests
void test_constructor1();
void test_constructor2();
void test_get_name();
void test_get_num_f();
void test_get_num_s();
void test_set_name();
void test_set_num_f();
void test_set_num_s();
void test_op_attrib();
void test_op_equals();


//Repo tests
void test_add();
void test_get_all();
void test_get_size();
void test_find();


void all_tests();