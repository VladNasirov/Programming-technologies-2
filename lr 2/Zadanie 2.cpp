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
	cout << "Текст введен!" << endl;
	system("pause");
}

void cleartext()
{
	fstream clear_file("text.txt", ios::out);
	clear_file.close();
	cout << "Текст отчищен!" << endl;
	system("pause");
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
				out << char(rand() % 100 + ' ');
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
	cout << "Текст введен!" << endl;
	system("pause");
}

void print_menu_p2()
{
	cout << "1.Ввод своего текста(если текст состоит из нескольких строк, то занесите его в файл text.txt).\n2.Очистить файл.\n3.Заполнить файл случайными символами.\n4.Найти самое длинное слово.\n5.Выход." << endl;
}

void findmax()
{
	int max = 0;
	int count_of_max=0;
	int tempmax = 0;
	int count_of_equal_size_word = 0;
	int flagslovo = 0;
	int wordcount = 0;
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
		if (massin[i] == ' ' || massin[i] == '.' || massin[i] == ',' || massin[i] == '?' || massin[i] == '!' || massin[i] == '\n' || massin[i] == '\0' || massin[i] == ':' || massin[i] == ';' || massin[i] == '\'' || massin[i] == '$' || massin[i] == '+' || massin[i] == '-' || massin[i] == '*' || massin[i] == '/' || massin[i] == '%' || massin[i] == '"' || massin[i] == '#' || massin[i] == '(' || massin[i] == ')' || massin[i] == '&'|| massin[i]=='['|| massin[i]==']'|| massin[i]=='{'|| massin[i]=='}'|| massin[i]=='^'|| massin[i]=='%'|| massin[i]=='№'|| massin[i]=='='|| massin[i]=='_'|| massin[i]=='@'|| massin[i]=='<'|| massin[i] == '>')
		{
			if (flagslovo == 1)
			{
				flagslovo = 0;
			}
		}
		else
		{
			if (flagslovo == 0)
			{
				flagslovo = 1;
				wordcount++;
			}
		}
	}
	cout <<"Текст: \n"<< massin << endl;
	cout <<"Кол-во слов в тексте: "<< wordcount << endl;
	int j = -1;
	Word* slovo = new Word[wordcount];
	for (int i = 0; i < size(massin); i++)
	{
		if (massin[i] == ' ' || massin[i] == '.' || massin[i] == ',' || massin[i] == '?' || massin[i] == '!' || massin[i] == '\n' || massin[i] == '\0' || massin[i] == ':' || massin[i] == ';' || massin[i] == '\'' || massin[i] == '$' || massin[i] == '+' || massin[i] == '-' || massin[i] == '*' || massin[i] == '/' || massin[i] == '%' || massin[i] == '"' || massin[i] == '#' || massin[i] == '(' || massin[i] == ')' || massin[i] == '&' || massin[i] == '[' || massin[i] == ']' || massin[i] == '{' || massin[i] == '}' || massin[i] == '^' || massin[i] == '%' || massin[i] == '№' || massin[i] == '=' || massin[i] == '_' || massin[i] == '@' || massin[i] == '<' || massin[i] == '>')
		{
			if (flagslovo == 1)
			{
				flagslovo = 0;
			}
		}
		else
		{
			if (flagslovo == 0)
			{
				flagslovo = 1;
				j++;
			}
			slovo[j] += massin[i];
		}
	}
	Word maxslovo;
	for (int i = 0; i < wordcount; i++)
	{
		if (slovo[i].getlenght() > max)
		{
			max = slovo[i].getlenght();
			maxslovo= slovo[i];
		}
		else if (slovo[i].getlenght() == max)
		{
			count_of_max++;
			if (slovo[i].getword() == maxslovo.getword())
			{
				slovo[i].addmeettimes();
			}
			else
			{
				count_of_equal_size_word++;
			}
		}
	}
	j = 0;
	if (count_of_equal_size_word > 0)
	{
		Word* maxwords = new Word[count_of_max+1];
		for (int i = 0; i < wordcount; i++)
		{
			if (slovo[i].getlenght() == max)
			{
				maxwords[j++] = slovo[i];
			}
		}
		for (int i = 1; i < count_of_max; i++)
		{
			for (int k = 0; k < count_of_max+1; k++)
			{
				if ((maxwords[i].getword() == maxwords[k].getword())&&(i!=k))
				{
					maxwords[i].addmeettimes();
					maxwords[k].deleteword();
				}
			}
		}
		for (int i = 0; i < count_of_max + 1; i++)
		{
			if (maxwords[i].getword() != "")
			{
				cout << maxwords[i].getword() <<"\t длина слова: "<<maxwords[i].getlenght() << " встречалось в тексте: "<<maxwords[i].getmeettimes()<< endl;
			}
		}
	}
	else 
	{
		cout <<"Самое длинное слово в тексте: "<< maxslovo.getword()<<" длинною: "<<maxslovo.getlenght()<<" встречалось в тексте : "<<maxslovo.getmeettimes()<< endl;
	}
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