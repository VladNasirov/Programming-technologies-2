#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sign
{
private:
	string name;
	string secondname;
	string zodiacsign;
	int birthday_data[3];
public:
	Sign();
	Sign(int a);
	void set_name();
	string get_name();
	void set_secondname();
	string get_secondname();
	void set_zodiaksign();
	string get_zodiaksign();
	void set_birhday();
	int get_birthday_day();
	int get_birthday_month();
	int get_birthday_year();
	friend ostream& operator << (ostream& out, Sign& object);
	~Sign();
	string Me();
	bool Checkzodiacsign();
};