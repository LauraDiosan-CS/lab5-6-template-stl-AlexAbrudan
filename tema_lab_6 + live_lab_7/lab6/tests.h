#pragma once

#include <assert.h>
#include "Flight.h"
#include "Service.h"
#include "Repo.h"


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
void test_modify();
void test_del();
void test_get_elem();

//Service tests
void test_add_s();
void test_get_all_s();
void test_modify_s();
void test_del_s();
void test_get_size_s();
void test_get_elem_s();


void all_tests();