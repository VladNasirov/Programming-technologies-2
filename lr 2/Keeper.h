#pragma once
#include "Sign.h"
#include <fstream>
#pragma warning(disable: 4996)
class Keeper
{
private:
	int ksize;
	Sign* value_sign;
public:
	Keeper();
	Keeper(int size);
	void add_sign(Sign* new_element, int pos);
	void remove_sign(int pos);
	void resize_sign(int newsize);
	void remove_all_sign();
	int get_size_sign();
	void show_all_sign();
	Sign* get_array_sign();
	Sign& operator[](int pos);
	void sorting();
	void get_person_info();
};

