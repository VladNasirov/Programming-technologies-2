#include "sign.h"
Sign::Sign()
{

	name = "=";
	secondname = "=";
	zodiacsign = "=";
	birthday_data[0] = 0;
	birthday_data[1] = 0;
	birthday_data[2] = 0;
	cout << "Объект со знаком зодиака создан!\n";

}
Sign::Sign(int a)
{

	set_name();
	set_secondname();
	set_birhday();
	set_zodiaksign();
	cout << "Объект со знаком зодиака создан!\n";
}
Sign::	~Sign()
{
	cout << "Объект под названием знак зодиака удален!\n";
}
void Sign::set_name()
{
	cout << "Введите имя: " << endl;
	cin >> name;
}

string Sign::get_name()
{
	return name;
}

void Sign::set_secondname()
{
	cout << "Введите фамилию: " << endl;
	cin >> secondname;
}

string Sign::get_secondname()
{
	return secondname;
}

void Sign::set_zodiaksign()
{
	cout << "Введите знак зодиака: " << endl;
	cin >> zodiacsign;
	if (Checkzodiacsign()==false)
	{
			cout << "Дата рождения не совпадает со знаком зодиака!" << endl;
			cout << "Введите верный знак зодиака: " << endl;
			cin >> zodiacsign;	
	}
}

string Sign::get_zodiaksign()
{
	return zodiacsign;
}


void Sign::set_birhday()
{
	cout << "Введите день: " << endl;
	while (!(cin >> birthday_data[0])) 
	{
		cout << "Ошибка ввода! Введите корректное значение дня: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Введите № месяца: " << endl;
	while (!(cin >> birthday_data[1])) {
		cout << "Ошибка ввода! Введите корректное значение месяца: "<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Введите год: " << endl;
	while (!(cin >> birthday_data[2])) {
		cout << "Ошибка ввода! Введите корректное значение года: "<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}
int Sign::get_birthday_day()
{ 
	return birthday_data[0];
}
int Sign::get_birthday_month()
{
	return birthday_data[1];
}
int Sign::get_birthday_year()
{
	return birthday_data[2];
}
ostream& operator << (ostream& out, Sign& object)
{
	out << object.Me();
	return out;
}
bool Sign::Checkzodiacsign()//доп. функционал (проверка знака зодиака по датам).
{
	if (zodiacsign=="Овен"|| zodiacsign == "ОВЕН"|| zodiacsign == "овен"|| zodiacsign == "Aries"|| zodiacsign == "ARIES"|| zodiacsign == "aries")
	{
		if (birthday_data[1] == 3 || birthday_data[1] == 4)
		{
			if (birthday_data[1] == 3 && birthday_data[0] >= 21 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 4 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "Телец" || zodiacsign == "ТЕЛЕЦ" || zodiacsign == "телец" || zodiacsign == "Taurus" || zodiacsign == "TAURUS" || zodiacsign == "taurus")
	{
		if (birthday_data[1] == 4 || birthday_data[1] == 5)
		{
			if (birthday_data[1] == 4 && birthday_data[0] >= 21 && birthday_data[0] <= 30)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 5 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "Близнецы" || zodiacsign == "БЛИЗНЕЦЫ" || zodiacsign == "близнецы" || zodiacsign == "Gemini" || zodiacsign == "GEMINI" || zodiacsign == "gemini")
	{
		if (birthday_data[1] == 5 || birthday_data[1] == 6)
		{
			if (birthday_data[1] == 5 && birthday_data[0] >= 22 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 6 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "Рак" || zodiacsign == "РАК" || zodiacsign == "рак" || zodiacsign == "Cancer" || zodiacsign == "CANCER" || zodiacsign == "cancer")
	{
		if (birthday_data[1] == 6 || birthday_data[1] == 7)
		{
			if (birthday_data[1] == 6 && birthday_data[0] >= 22 && birthday_data[0] <= 30)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 7 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}


	if (zodiacsign == "Лев" || zodiacsign == "ЛЕВ" || zodiacsign == "лев" || zodiacsign == "Leo" || zodiacsign == "LEO" || zodiacsign == "leo")
	{
		if (birthday_data[1] == 7 || birthday_data[1] == 8)
		{
			if (birthday_data[1] == 7 && birthday_data[0] >= 23 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 8 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
	
	if (zodiacsign == "Дева" || zodiacsign == "ДЕВА" || zodiacsign == "дева" || zodiacsign == "Virgo" || zodiacsign == "VIRGO" || zodiacsign == "virgo")
	{
		if (birthday_data[1] == 8 || birthday_data[1] == 9)
		{
			if (birthday_data[1] == 8 && birthday_data[0] >= 22 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 9 && birthday_data[0] >= 1 && birthday_data[0] <= 23)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "Весы" || zodiacsign == "ВЕСЫ" || zodiacsign == "весы" || zodiacsign == "Libra" || zodiacsign == "LIBRA" || zodiacsign == "libra")
	{
		if (birthday_data[1] == 9 || birthday_data[1] == 10)
		{
			if (birthday_data[1] == 9 && birthday_data[0] >= 24 && birthday_data[0] <= 30)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 10 && birthday_data[0] >= 1 && birthday_data[0] <= 23)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "Скорпион" || zodiacsign == "СКОРПИОН" || zodiacsign == "скорпион" || zodiacsign == "Scorpio" || zodiacsign == "SCORPIO" || zodiacsign == "scorpio")
	{
		if (birthday_data[1] == 10 || birthday_data[1] == 11)
		{
			if (birthday_data[1] == 10 && birthday_data[0] >= 24 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 11 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "Стрелец" || zodiacsign == "СТРЕЛЕЦ" || zodiacsign == "стрелец" || zodiacsign == "Sagittarius" || zodiacsign == "SAGITTARIUS" || zodiacsign == "sagittarius")
	{
		if (birthday_data[1] == 11 || birthday_data[1] == 12)
		{
			if (birthday_data[1] == 11 && birthday_data[0] >= 23 && birthday_data[0] <= 30)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 12 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "Козерог" || zodiacsign == "КОЗЕРОГ" || zodiacsign == "козерог" || zodiacsign == "Capricorn" || zodiacsign == "CAPRICORN" || zodiacsign == "сapricorn")
	{
		if (birthday_data[1] == 12 || birthday_data[1] == 1)
		{
			if (birthday_data[1] == 12 && birthday_data[0] >= 23 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 1 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "Водолей" || zodiacsign == "ВОДОЛЕЙ" || zodiacsign == "водолей" || zodiacsign == "Aquarius" || zodiacsign == "AQUARIUS" || zodiacsign == "aquarius")
	{
		if (birthday_data[1] == 1 || birthday_data[1] == 2)
		{
			if (birthday_data[1] == 1 && birthday_data[0] >= 21 && birthday_data[0] <= 31)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 2 && birthday_data[0] >= 1 && birthday_data[0] <= 19)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "Рыбы" || zodiacsign == "РЫБЫ" || zodiacsign == "рыбы" || zodiacsign == "Pisces" || zodiacsign == "PISCES" || zodiacsign == "pisces")
	{
		if (birthday_data[1] == 2 || birthday_data[1] == 3)
		{
			if (birthday_data[1] == 2 && birthday_data[0] >= 20 && birthday_data[0] <= 29)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
			if (birthday_data[1] == 3 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "Знак зодиака выбран верно! " << endl;
				return true;
			}
		}
		else return false;
	}
}
string Sign::Me()
{
	return "ФИ человека: "+ this->get_secondname() + " " + this->get_name() + "  Знак зодиака: " + this->get_zodiaksign() + " Дата рождения: " + to_string(this->birthday_data[0]) + "/"+to_string(this->birthday_data[1])+"/"+ to_string(this->birthday_data[2]) + "\n";
}
