#include "Zadanie 2.h"
const char* exception_open_file= "Ошибка открытия файла!";
void intext()
{
	string stroka;
	cout << "Введите текст: " << endl;
	cin.ignore(32767, '\n');
	getline(cin,stroka);
	ofstream out;
	out.open("text.txt");
	try
	{
		if (out.is_open())
		{
			out << stroka << endl;
		}
		else if (!out.is_open())
		{
			throw exception_open_file;
		}
		out.close();
	}
	catch (const char* exception_open_file)
	{
		cout << exception_open_file << "text.txt" << endl;
		out.close();
	}
}

void cleartext()
{
	fstream clear_file("text.txt", ios::out);
	clear_file.close();
}

void randomtext()
{
	int N,N1, charnum;
	cout << "Введите кол-во случайных символов: " << endl;
	cin >> charnum;
	ofstream out;
	out.open("text.txt");
	try 
	{
		for (int i = 0; i < charnum; i++)
		{
			if (out.is_open())
			{
				out << char(rand() % 26 + ' ');
			}
			else if (!out.is_open())
			{
				throw exception_open_file;
			}
		}
		out.close();
	}
	catch (const char* exception_open_file)
	{
		cout << exception_open_file << "text.txt" << endl;
		out.close();
	}
}

void print_menu_p2()
{
	cout << "1.Ввод своего текста.\n2.Очистить файл.\n3.Заполнить файл случайными символами.\n4.Найти самое длинное слово.\n5.Выход." << endl;
}

void findmax()
{
	int max = 0;
	int tempmax = 0;
	int maxslovopos;
	ifstream in;
	string massin;
	string symb;
	in.open("text.txt");
	try
	{
		if (in.is_open())
		{
			while (getline(in, symb))
			{
				massin += "\n";
				massin += symb;
			}
		}
		else if (!in.is_open())
		{
			throw "Ошибка открытия файла!\n";
		}
		in.close();
	}
	catch (const char* exception_open_file)
	{
		cout << exception_open_file << "text.txt" << endl;
		in.close();
	}
	for (int i = 0; i < size(massin); i++)
	{
		if (massin[i] ==' '|| massin[i]=='.'||massin[i]==','||massin[i]=='?'||massin[i]=='!'||massin[i]=='\n'||massin[i]=='\0'||massin[i]==':'||massin[i]==';'||massin[i]=='\''||massin[i]=='$'|| massin[i] =='+'|| massin[i] =='-'|| massin[i] =='*'|| massin[i] == '/'|| massin[i] == '%'|| massin[i] == '"'|| massin[i] == '#'|| massin[i] == '('|| massin[i] == ')'|| massin[i] == '&')
		{
			tempmax = 0;
		}
		else//найдено слово
		{
			tempmax++;
		}
		if (tempmax>max)
		{
			maxslovopos = i-max; //позиция первого символа максимального слова
			max = tempmax;
		}
	}
	cout << "Строка: " << endl;
	cout << massin << endl;
	cout <<"Начало макс. слова: "<< maxslovopos << endl;
	cout <<"Длинна максю слова: "<< max << endl;
	string word;
	for (int j=0; j<size(massin); j++)
	{
		if ((j >= maxslovopos) && (j < maxslovopos + max))
		{
			word+=massin[j];
		}
	}
	string keyword=word;
	int cnt=0;
	for (int i = 0; i < size(massin); i++)
	{
		if (!(massin[i] == ' ' || massin[i] == '.' || massin[i] == ',' || massin[i] == '?' || massin[i] == '!' || massin[i] == '\n' || massin[i] == '\0' || massin[i] == ':' || massin[i] == ';'))
		{
			word += massin[i];
		}
		else
		{
			if (word == keyword)
			{
				cnt++;
			}
			word.clear();
		}
	}

	cout <<"Самое длинное слово: "<< keyword << endl;
	cout <<"Встречается в тексте: "<< cnt <<" раз."<< endl;
	system("pause");
}
void menu_p2()
{
	int choice;
	do
	{
		system("cls");
		print_menu_p2();
		cin >> choice;
		if (choice == 1)
		{
			intext();
		}
		if (choice == 2)
		{
			cleartext();
		}
		if (choice == 3)
		{
			randomtext();
		}
		if (choice == 4)
		{
			findmax();
		}
	} while (choice != 5);
}