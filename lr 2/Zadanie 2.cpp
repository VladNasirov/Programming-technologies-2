#include "Zadanie 2.h"
const char* exception_open_file= "������ �������� �����!";
void intext()
{
	string stroka;
	cout << "������� �����: " << endl;
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
	cout << "����� ������!" << endl;
	system("pause");
}

void cleartext()
{
	fstream clear_file("text.txt", ios::out);
	clear_file.close();
	cout << "����� �������!" << endl;
	system("pause");
}

void randomtext()
{
	int N,N1, charnum;
	cout << "������� ���-�� ��������� ��������: " << endl;
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
	cout << "����� ������!" << endl;
	system("pause");
}

void print_menu_p2()
{
	cout << "1.���� ������ ������(���� ����� ������� �� ���������� �����, �� �������� ��� � ���� text.txt).\n2.�������� ����.\n3.��������� ���� ���������� ���������.\n4.����� ����� ������� �����.\n5.�����." << endl;
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
			throw "������ �������� �����!\n";
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
		if (massin[i] == ' ' || massin[i] == '.' || massin[i] == ',' || massin[i] == '?' || massin[i] == '!' || massin[i] == '\n' || massin[i] == '\0' || massin[i] == ':' || massin[i] == ';' || massin[i] == '\'' || massin[i] == '$' || massin[i] == '+' || massin[i] == '-' || massin[i] == '*' || massin[i] == '/' || massin[i] == '%' || massin[i] == '"' || massin[i] == '#' || massin[i] == '(' || massin[i] == ')' || massin[i] == '&'|| massin[i]=='['|| massin[i]==']'|| massin[i]=='{'|| massin[i]=='}'|| massin[i]=='^'|| massin[i]=='%'|| massin[i]=='�'|| massin[i]=='='|| massin[i]=='_'|| massin[i]=='@'|| massin[i]=='<'|| massin[i] == '>')
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
	cout <<"�����: \n"<< massin << endl;
	cout <<"���-�� ���� � ������: "<< wordcount << endl;
	int j = -1;
	Word* slovo = new Word[wordcount];
	for (int i = 0; i < size(massin); i++)
	{
		if (massin[i] == ' ' || massin[i] == '.' || massin[i] == ',' || massin[i] == '?' || massin[i] == '!' || massin[i] == '\n' || massin[i] == '\0' || massin[i] == ':' || massin[i] == ';' || massin[i] == '\'' || massin[i] == '$' || massin[i] == '+' || massin[i] == '-' || massin[i] == '*' || massin[i] == '/' || massin[i] == '%' || massin[i] == '"' || massin[i] == '#' || massin[i] == '(' || massin[i] == ')' || massin[i] == '&' || massin[i] == '[' || massin[i] == ']' || massin[i] == '{' || massin[i] == '}' || massin[i] == '^' || massin[i] == '%' || massin[i] == '�' || massin[i] == '=' || massin[i] == '_' || massin[i] == '@' || massin[i] == '<' || massin[i] == '>')
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
				cout << maxwords[i].getword() <<"\t ����� �����: "<<maxwords[i].getlenght() << " ����������� � ������: "<<maxwords[i].getmeettimes()<< endl;
			}
		}
	}
	else 
	{
		cout <<"����� ������� ����� � ������: "<< maxslovo.getword()<<" �������: "<<maxslovo.getlenght()<<" ����������� � ������ : "<<maxslovo.getmeettimes()<< endl;
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