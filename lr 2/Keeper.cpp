#include "Keeper.h"
const char* exceptions;
Keeper::Keeper()
{
	setlocale(LC_ALL, "Russian");
	ksize = 0;
	value_sign = nullptr;
	cout << "Класс Keeper создан!\n";
}

Keeper::Keeper(int size)
{
	setlocale(LC_ALL, "Russian");
	try
	{
		if (size >= 0)
		{
			this->ksize = size;
			value_sign = new Sign[size];
			cout << "Класс Keeper создан!\n";
		}
		else
		{
			exceptions = "Класс Keeper не может быть отрицательной длины!\n";
			throw exceptions;
			value_sign = nullptr;
		}
	}
	catch (char* exceptions)
	{
		cout << exceptions << endl;
		system("pause");
	}
}


void Keeper::add_sign(Sign* new_element, int pos)
{
	if (pos < 0 || pos > ksize)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}
	else
	{
		Sign* temp = new Sign[ksize + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = value_sign[i];
		}
		temp[pos] = *new_element;
		for (int j = pos; j < ksize; j++)
		{
			temp[j + 1] = value_sign[j];
		}
		delete[] value_sign;
		value_sign = temp;
		ksize++;
	}
}
void Keeper::get_person_info()
{
	string cmpfirstname;
	string cmpsecondname;
	cout << "Введите фамилию человека, информацию о котором хотите получить:" << endl;
	cin >> cmpsecondname;
	for (int i = 0; i < get_size_sign(); i++)
	{
		if (value_sign[i].get_secondname()==cmpsecondname)
		{
			cout << value_sign[i] << endl;
		}
	}
}


void Keeper::remove_sign(int pos)
{
	if (ksize == 0)
	{
		cout << "Контейнер и так пуст!\n";
	}
	else
	{

		if (pos < 0 || pos > ksize)
		{
			cout << "Позиция в классе Keeper отсутствует!\n";

		}
		else
		{

			if (ksize == 1)
			{
				remove_all_sign();
				return;
			}
			Sign* temp = new Sign[ksize - 1];
			for (int i = 0; i < pos; i++)
			{
				temp[i] = value_sign[i];
			}
			for (int j = pos + 1; j < ksize; j++)
			{
				temp[j - 1] = value_sign[j];
			}
			delete[] value_sign;
			value_sign = temp;
			ksize--;
		}
	}
}

void Keeper::resize_sign(int newsize)
{
	if (newsize == ksize)
	{
		return;
	}
	if (newsize < 0)
	{
		remove_all_sign();
		return;
	}
	Sign* temp = new Sign[newsize];
	if (ksize >= 0)
	{
		int count = 0;
		if (newsize > ksize)
		{
			count = ksize;
		}
		else
		{
			count = newsize;
		}
		for (int i = 0; i < count; i++)
		{
			temp[i] = value_sign[i];
		}
		delete[] value_sign;
		value_sign = temp;
		ksize = newsize;

	}
}


void Keeper::remove_all_sign()
{

	delete[] value_sign;
	value_sign = nullptr;
	ksize = 0;
}


int Keeper::get_size_sign()
{
	return ksize;
}
Sign& Keeper::operator[](int pos)
{
	if (pos < 0 || pos > ksize)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";
		exit(1);
	}
	else
	{
		return value_sign[pos];
	}
}

void Keeper::show_all_sign()
{
	sorting();
	for (int i = 0; i != ksize; i++)
	{
		cout << i << ". " << value_sign[i] << endl;
	}
}


Sign* Keeper::get_array_sign()
{
	return value_sign;
}

void Keeper::sorting()
{
	for (int i = 1; i < get_size_sign(); i++)
	{
		for (int j = 0; j < get_size_sign() - 1; j++)
		{
			if (value_sign[j].get_birthday_year() > value_sign[j + 1].get_birthday_year()) //сравнение года
			{
				Sign temp;
				temp = value_sign[j];
				value_sign[j] = value_sign[j + 1];
				value_sign[j + 1] = temp;
			}
			if (value_sign[j].get_birthday_year() == value_sign[j + 1].get_birthday_year())
			{
				if (value_sign[j].get_birthday_month() > value_sign[j + 1].get_birthday_month()) //сравнение месяца
				{
					Sign temp;
					temp = value_sign[j];
					value_sign[j] = value_sign[j + 1];
					value_sign[j + 1] = temp;
				}
				if (value_sign[j].get_birthday_month() == value_sign[j + 1].get_birthday_month())
				{
					if (value_sign[j].get_birthday_day() > value_sign[j + 1].get_birthday_day()) //сравнение дня
					{
							Sign temp;
							temp = value_sign[j];
							value_sign[j] = value_sign[j + 1];
							value_sign[j + 1] = temp;
					}
				}
			}
		}
	}
}

