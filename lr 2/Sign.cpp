#include "sign.h"
Sign::Sign()
{

	name = "=";
	secondname = "=";
	zodiacsign = "=";
	birthday_data[0] = 0;
	birthday_data[1] = 0;
	birthday_data[2] = 0;
	cout << "������ �� ������ ������� ������!\n";

}
Sign::Sign(int a)
{

	set_name();
	set_secondname();
	set_birhday();
	set_zodiaksign();
	cout << "������ �� ������ ������� ������!\n";
}
Sign::	~Sign()
{
	cout << "������ ��� ��������� ���� ������� ������!\n";
}
void Sign::set_name()
{
	cout << "������� ���: " << endl;
	cin >> name;
}

string Sign::get_name()
{
	return name;
}

void Sign::set_secondname()
{
	cout << "������� �������: " << endl;
	cin >> secondname;
}

string Sign::get_secondname()
{
	return secondname;
}

void Sign::set_zodiaksign()
{
	cout << "������� ���� �������: " << endl;
	cin >> zodiacsign;
	if (Checkzodiacsign()==false)
	{
			cout << "���� �������� �� ��������� �� ������ �������!" << endl;
			cout << "������� ������ ���� �������: " << endl;
			cin >> zodiacsign;	
	}
}

string Sign::get_zodiaksign()
{
	return zodiacsign;
}


void Sign::set_birhday()
{
	cout << "������� ����: " << endl;
	while (!(cin >> birthday_data[0])) 
	{
		cout << "������ �����! ������� ���������� �������� ���: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "������� � ������: " << endl;
	while (!(cin >> birthday_data[1])) {
		cout << "������ �����! ������� ���������� �������� ������: "<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "������� ���: " << endl;
	while (!(cin >> birthday_data[2])) {
		cout << "������ �����! ������� ���������� �������� ����: "<<endl;
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
bool Sign::Checkzodiacsign()//���. ���������� (�������� ����� ������� �� �����).
{
	if (zodiacsign=="����"|| zodiacsign == "����"|| zodiacsign == "����"|| zodiacsign == "Aries"|| zodiacsign == "ARIES"|| zodiacsign == "aries")
	{
		if (birthday_data[1] == 3 || birthday_data[1] == 4)
		{
			if (birthday_data[1] == 3 && birthday_data[0] >= 21 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 4 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "�����" || zodiacsign == "�����" || zodiacsign == "�����" || zodiacsign == "Taurus" || zodiacsign == "TAURUS" || zodiacsign == "taurus")
	{
		if (birthday_data[1] == 4 || birthday_data[1] == 5)
		{
			if (birthday_data[1] == 4 && birthday_data[0] >= 21 && birthday_data[0] <= 30)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 5 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "��������" || zodiacsign == "��������" || zodiacsign == "��������" || zodiacsign == "Gemini" || zodiacsign == "GEMINI" || zodiacsign == "gemini")
	{
		if (birthday_data[1] == 5 || birthday_data[1] == 6)
		{
			if (birthday_data[1] == 5 && birthday_data[0] >= 22 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 6 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "���" || zodiacsign == "���" || zodiacsign == "���" || zodiacsign == "Cancer" || zodiacsign == "CANCER" || zodiacsign == "cancer")
	{
		if (birthday_data[1] == 6 || birthday_data[1] == 7)
		{
			if (birthday_data[1] == 6 && birthday_data[0] >= 22 && birthday_data[0] <= 30)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 7 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}


	if (zodiacsign == "���" || zodiacsign == "���" || zodiacsign == "���" || zodiacsign == "Leo" || zodiacsign == "LEO" || zodiacsign == "leo")
	{
		if (birthday_data[1] == 7 || birthday_data[1] == 8)
		{
			if (birthday_data[1] == 7 && birthday_data[0] >= 23 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 8 && birthday_data[0] >= 1 && birthday_data[0] <= 21)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
	
	if (zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "Virgo" || zodiacsign == "VIRGO" || zodiacsign == "virgo")
	{
		if (birthday_data[1] == 8 || birthday_data[1] == 9)
		{
			if (birthday_data[1] == 8 && birthday_data[0] >= 22 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 9 && birthday_data[0] >= 1 && birthday_data[0] <= 23)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "Libra" || zodiacsign == "LIBRA" || zodiacsign == "libra")
	{
		if (birthday_data[1] == 9 || birthday_data[1] == 10)
		{
			if (birthday_data[1] == 9 && birthday_data[0] >= 24 && birthday_data[0] <= 30)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 10 && birthday_data[0] >= 1 && birthday_data[0] <= 23)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "��������" || zodiacsign == "��������" || zodiacsign == "��������" || zodiacsign == "Scorpio" || zodiacsign == "SCORPIO" || zodiacsign == "scorpio")
	{
		if (birthday_data[1] == 10 || birthday_data[1] == 11)
		{
			if (birthday_data[1] == 10 && birthday_data[0] >= 24 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 11 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "Sagittarius" || zodiacsign == "SAGITTARIUS" || zodiacsign == "sagittarius")
	{
		if (birthday_data[1] == 11 || birthday_data[1] == 12)
		{
			if (birthday_data[1] == 11 && birthday_data[0] >= 23 && birthday_data[0] <= 30)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 12 && birthday_data[0] >= 1 && birthday_data[0] <= 22)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
	if (zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "Capricorn" || zodiacsign == "CAPRICORN" || zodiacsign == "�apricorn")
	{
		if (birthday_data[1] == 12 || birthday_data[1] == 1)
		{
			if (birthday_data[1] == 12 && birthday_data[0] >= 23 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 1 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "�������" || zodiacsign == "Aquarius" || zodiacsign == "AQUARIUS" || zodiacsign == "aquarius")
	{
		if (birthday_data[1] == 1 || birthday_data[1] == 2)
		{
			if (birthday_data[1] == 1 && birthday_data[0] >= 21 && birthday_data[0] <= 31)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 2 && birthday_data[0] >= 1 && birthday_data[0] <= 19)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}

	if (zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "����" || zodiacsign == "Pisces" || zodiacsign == "PISCES" || zodiacsign == "pisces")
	{
		if (birthday_data[1] == 2 || birthday_data[1] == 3)
		{
			if (birthday_data[1] == 2 && birthday_data[0] >= 20 && birthday_data[0] <= 29)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
			if (birthday_data[1] == 3 && birthday_data[0] >= 1 && birthday_data[0] <= 20)
			{
				cout << "���� ������� ������ �����! " << endl;
				return true;
			}
		}
		else return false;
	}
}
string Sign::Me()
{
	return "�� ��������: "+ this->get_secondname() + " " + this->get_name() + "  ���� �������: " + this->get_zodiaksign() + " ���� ��������: " + to_string(this->birthday_data[0]) + "/"+to_string(this->birthday_data[1])+"/"+ to_string(this->birthday_data[2]) + "\n";
}
