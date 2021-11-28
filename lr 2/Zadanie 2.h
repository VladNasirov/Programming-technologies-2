#pragma once
void menu_p2();
void findmax();
void print_menu_p2();
void randomtext();
void cleartext();
void intext();
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class Word
{
private:
	int lenght=0;
	string word;
	int meettimes = 1;
public:
	void operator+=(char w)
	{
		word += w;
		lenght++;
	}
	string getword()
	{
		return word;
	}
	int getlenght()
	{
		return lenght;
	}
	int getmeettimes()
	{
		return meettimes;
	}
	void addmeettimes()
	{
		meettimes++;
	}
	void deleteword()
	{
		word.clear();
	}
};