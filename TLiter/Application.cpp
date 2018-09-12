#include <fstream>
#include <iostream>
#include <iomanip>

#include "Application.h"
#include "Date.h"


using namespace std;


/*
	Конструктор без параметров
*/
Application::Application()
{
	this->_count = 0;
	this->_limit = this->_capacity;
	this->_array = new TLiter[this->_capacity];
}

/*
	Метод, запускающий всю работу и проводящий инициализацию
*/
void Application::start()
{
	if (!this->import_from_file())
		return;
	int menu = 0;
	do
	{
		cout << endl;
		cout << left << setw(30) << "Печать произведений:" << 1 << endl;
		cout << left << setw(30) << "Возраст произведения" << 2 << endl;
		cout << left << setw(30) << "Сравнение по автору" << 3 << endl;
		cout << left << setw(30) << "Сравнение по дате выхода" << 4 << endl;
		cout << left << setw(30) << "Выход" << "else" << endl;
		cin >> menu;

		switch (menu)
		{
		case 1:
			this->print();
			break;
		case 2:
			this->old();
			break;
		case 3:
			this->author_equal();
			break;
		case 4:
			this->date_compare();
			break;
		}
	} while (menu < 5 && menu > 0);
}

/*
	Контроллер по возрасту произведения, обрабатывается свитчем
*/
void Application::old()
{
	this->print_all();
	int id = this->choose();
	Date today = Date::today();
	this->_array[id].get_old(today);
}

/*
	Контроллер печати, обрабатывается свитчем
*/
void Application::print()
{
	int menu = 0;
	cout << endl;
	cout << left << setw(25) << "Полная:" << 1 << endl;
	cout << left << setw(25) << "ФИО автора и название:" << 2 << endl;
	cout << "Выберите: ";
	do
	{
		cin >> menu;
		cin.ignore();
		if (menu < 1 || menu > 2)
		{
			cout << "Ошибка, попробуйте снова: ";
			cin >> menu;
			cin.ignore();
		}

	} while (menu < 1 || menu > 2);
	if (menu == 1)
		this->print_all();
	else this->print_all(false);
}

/*
	Конструктор с параметрами
*/
void Application::resize()
{
	TLiter* buf = this->_array;
	this->_array = new TLiter[this->_limit + this->_capacity];
	for (int i = 0; i < this->_count; i++)
	{
		this->_array[i] = buf[i];
	}
	this->_limit += this->_capacity;
	delete[] buf;
}

/*
	Печатает весь список произведений
	Выводит всю информацию если флаг true
*/
void Application::print_all(bool full)
{
	cout << endl;
	for (int i = 0; i < this->_count; i++)
	{
		cout << "----------------------> " << i << " <----------------------" << endl;
		if (full)
			this->_array[i].print();
		else this->_array[i].print_fio_and_name_only();
	}
}

/*
	Позволяет выбрать одно из произведений, вернет его номер
*/
int Application::choose()
{
	int result = 0;
	cout << "Введите номер произведения: ";
	do
	{
		cin >> result;
		cin.ignore();
		if (result < 0 || result >= this->_count)
		{
			cout << "Ошибка, попробуйте снова: ";
			cin >> result;
			cin.ignore();
		}
	} while (result < 0 || result >= this->_count);
	return result;
}

/*
	Импортирует данные из файла
*/
bool Application::import_from_file()
{
	ifstream file = ifstream(this->filename, ios::in);
	if (!file)
	{
		cout << "Не удалось открыть файл" << endl;
		return false;
	}
	else
	{
		char name[50];
		char fio[50];
		int year, month, day;
		while (!file.eof())
		{
			file.getline(fio, 50, '#');
			file.getline(name, 50, '#');
			file >> year >> month >> day;
			file.ignore();
			if (this->_count < this->_limit)
			{
				this->_array[this->_count++] = TLiter(name, fio, Date(year, month, day));
			}
			else
			{
				this->resize();
				this->_array[this->_count++] = TLiter(name, fio, Date(year, month, day));
			}
		}
		if (this->_count > 0)
			return true;
		else return false;
	}
}

/*
	Сравнивает два произведени по автору
*/
void Application::author_equal()
{
	int first, second;
	cout << endl << "Выберите два произведения из списка!!!" << endl;
	this->print_all();
	first = this->choose();
	second = this->choose();
	if (this->_array[first].authod_equal(this->_array[second]))
		cout << "Произведения написаны одним автором" << endl;
	else
		cout << "Произведения написаны разными авторами" << endl;
}

/*
	Сравнивает два произведения по дате выпуска
*/
void Application::date_compare()
{
	int first, second;
	cout << endl << "Выберите два произведения из списка!!!" << endl;
	this->print_all();
	first = this->choose();
	second = this->choose();
	cout << "\"" << this->_array[first].get_name() << "\" выпущена ";
	if (this->_array[first].late(this->_array[second]))
		cout << "позже чем \"" << this->_array[second].get_name() << "\"" << endl;
	else
		cout << "одновременно либо раньше чем \"" << this->_array[second].get_name() << "\"" << endl;
}

/*
	Деструктор
*/
Application::~Application()
{
}
