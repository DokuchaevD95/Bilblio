#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstring>

#include "TLiter.h"


using namespace std;


/*
	Конструктор с параметрами
*/
TLiter::TLiter()
{
	strcpy(this->_fio, "");
	strcpy(this->_name, "");
}

/*
	Конструктор без параметров
*/
TLiter::TLiter(char* name, char* fio, Date date)
{
	strcpy(this->_name, name);
	strcpy(this->_fio, fio);
	this->_date = date;
}

/*
	Конструктор копирования
*/
TLiter::TLiter(const TLiter &obj)
{
	this->_date = obj._date;
	strcpy(this->_name, obj._name);
	strcpy(this->_fio, obj._fio);
}

/*
	Метод, распечатывающий лит. произведение на экран
*/
void TLiter::print()
{
	cout << endl;
	cout << left << setw(15) << "Название:" << this->_name << endl;
	cout << left << setw(15) << "Автор:" << this->_fio << endl;
	cout << left << setw(15) << "Дата выхода:";
	this->_date.print();
	cout << endl << endl;
}

/*
	Распечатывает только ФИО автора и название
*/
void TLiter::print_fio_and_name_only()
{
	cout << endl;
	cout << left << setw(15) << "Название:" << this->_name << endl;
	cout << left << setw(15) << "Автор:" << this->_fio << endl;
	cout << endl << endl;
}

/*
	Возвращает разницу во времени между переданной дадотой и датой выхода произведения
*/
void TLiter::get_old(Date& date)
{
	if (this->_date.late(date))
		cout << "Произведение к этому моменту еще не вышло!" << endl;
	else
	{
		int year_diff = 0, month_diff = 0, day_diff = 0;

		year_diff = date.get_year() - this->_date.get_year();

		if (this->_date.get_month() > date.get_month())
		{
			year_diff--;
			month_diff = 12 - this->_date.get_month() + date.get_month();
		}
		else month_diff = date.get_month() - this->_date.get_month();
		if (this->_date.get_day() > date.get_day())
		{
			int days_count = 0;
			if (date.get_month() > 1)
				days_count = Date::count_days_of_month_and_day(date.get_year(), date.get_month() - 1);
			else days_count = Date::count_days_of_month_and_day(date.get_year() - 1, 12);
			day_diff = days_count + date.get_day() - this->_date.get_day();
		}
		else day_diff = date.get_day() - this->_date.get_day();

		cout << "С момента выхода произведения по ";
		date.print();
		cout << " прошло " << year_diff << " лет(год) " << month_diff << " месяц(ев) " << day_diff << " дней(день)" << endl;
	}
}

/*
	True, если одинаковый автор
*/
bool TLiter::authod_equal(TLiter &obj)
{
	if (strcmp(this->_fio, obj._fio) == 0)
		return true;
	else return false;
}

/*
	True, если произведение выпущено позже переданного
*/
bool TLiter::late(TLiter &obj)
{
	if (this->_date.late(obj._date))
		return true;
	else return false;
}

/*
	Возвращает название произведения
*/
char* TLiter::get_name()
{
	return this->_name;
}

/*
	Деструктор
*/
TLiter::~TLiter()
{
}
