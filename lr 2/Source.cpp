#include "sign.h"
#include "Keeper.h"
#include <Windows.h>
#include "Zadanie 2.h"
#undef max;
void Keeper_sign(Keeper* test)
{
	int select_sign;
	do
	{
		system("cls");
		cout << "1.�������� ��������\n2.������������� ��������\n3.������� ��������\n4.����������� ���� �����\n5.����������� ���������� � ��������\n6.�����\n";
		cin >> select_sign;
		if (select_sign == 1)
		{
			Sign* example = new Sign(1);
			cout << "������ � ���������� " << test->get_size_sign() << " ���������\n������� ������ �� �������� ����� ������� ����� �������\n";
			int index;
			do
			{
				cin >> index;
				if (index <= test->get_size_sign())
				{
					test->add_sign(example, index);
				}
				if (index > test->get_size_sign())
				{
					test->resize_sign(index);
					test->add_sign(example, index);
				}
				if (index < 0)
				{
					cout << "������ �� ����� ���� �������������!\n";
				}
			} while (index < 0);
			cout << "������� ������� ��������!\n";
			system("pause");
		}
		if (select_sign == 2)
		{
			if (test->get_size_sign() == 0)
			{
				cout << "��������� ����� ����!\n";

			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_sign() << " ���������" << endl;
				test->show_all_sign();
				cout << "����� ������� ����� �������������?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_sign() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_sign() - 1);
				cout << "��� ����� �������������?\n1.���������\n2.��������\n";
				int select_edit;
				do
				{
					cin >> select_edit;
					if (select_edit == 1)
					{
						test->get_array_sign()[select_elm].set_secondname();
						test->get_array_sign()[select_elm].set_name();
						test->get_array_sign()[select_elm].set_zodiaksign();
						test->get_array_sign()[select_elm].set_birhday();
					}
					if (select_edit == 2)
					{
						cout << "��� ����� ��������?\n1.�������\n2.���\n3.���� �������\n4.���� ��������\n5.�����\n";
						int select_edit_partially;
						do
						{
							cin >> select_edit_partially;
							if (select_edit_partially == 1)
							{
								test->get_array_sign()[select_elm].set_secondname();
							}
							if (select_edit_partially == 2)
							{
								test->get_array_sign()[select_elm].set_name();
							}
							if (select_edit_partially == 3)
							{
								test->get_array_sign()[select_elm].set_zodiaksign();
							}
							if (select_edit_partially == 4)
							{
								test->get_array_sign()[select_elm].set_birhday();
							}
							if (select_edit_partially == 5)
							{
								break;
							}
							if (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6 && select_edit_partially != 7)
							{
								cout << "������ �������� �����!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6 && select_edit_partially != 7);
					}

					if (select_edit != 1 && select_edit != 2)
					{
						cout << "������� �������� �������!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "������� ��������������!\n";
			}
			system("pause");
		}
		if (select_sign == 3)
		{
			if (test->get_size_sign() == 0)
			{
				cout << "��������� ����� ����!\n";

			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_sign() << " ���������" << endl;
				test->show_all_sign();
				cout << "����� ������� ����� �������?\n";


				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_sign() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_sign() - 1);
				test->remove_sign(select_remove_elm);
				cout << "������� ������!\n";
			}
			system("pause");

		}

		if (select_sign == 4)
		{
			if (test->get_size_sign() == 0)
			{
				cout << "��������� ����� ����!\n";

			}
			else
			{
				test->show_all_sign();
			}
			system("pause");
		}
		if (select_sign == 5)
		{
			if (test->get_size_sign() == 0)
			{
				cout << "��������� ����� ����!\n";

			}
			else
			{
				test->get_person_info();
			}
			system("pause");
		}
		if (select_sign != 1 && select_sign != 2 && select_sign != 3 && select_sign != 4 && select_sign != 5 && select_sign!=6)
		{
			cout << "������ �������� �����!\n";
		}
	} while (select_sign != 6);
}
void print_menu()
{
	cout << "1.���� ������ �� ������� ������� \n2.���� ������ � ������� �����/������\n3.����� �� ���������\n";
}
void Keeper_menu()
{
	int size;
	cout << "������� ������ ���������� ��� ������ ������:\n";
	while (!(cin >> size))
	{
		cout << "������ �����! ������� ���������� �������� ���: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Keeper* test = new Keeper(0);
	int select;
	do
	{
		system("cls");
		print_menu();
		cin >> select;
		if (select == 1)
		{
			Keeper_sign(test);
		}
		if (select == 2)
		{
			menu_p2();
		}
	} while (select != 3);
}

int main(void)
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);
	Keeper_menu();
}