#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <cstring>

#include "TLiter.h"


using namespace std;


/*
	����������� � �����������
*/
TLiter::TLiter()
{
	strcpy(this->_fio, "");
	strcpy(this->_name, "");
}

/*
	����������� ��� ����������
*/
TLiter::TLiter(char* name, char* fio, Date date)
{
	strcpy(this->_name, name);
	strcpy(this->_fio, fio);
	this->_date = date;
}

/*
	����������� �����������
*/
TLiter::TLiter(const TLiter &obj)
{
	this->_date = obj._date;
	strcpy(this->_name, obj._name);
	strcpy(this->_fio, obj._fio);
}

/*
	�����, ��������������� ���. ������������ �� �����
*/
void TLiter::print()
{
	cout << endl;
	cout << left << setw(15) << "��������:" << this->_name << endl;
	cout << left << setw(15) << "�����:" << this->_fio << endl;
	cout << left << setw(15) << "���� ������:";
	this->_date.print();
	cout << endl << endl;
}

/*
	������������� ������ ��� ������ � ��������
*/
void TLiter::print_fio_and_name_only()
{
	cout << endl;
	cout << left << setw(15) << "��������:" << this->_name << endl;
	cout << left << setw(15) << "�����:" << this->_fio << endl;
	cout << endl << endl;
}

/*
	���������� ������� �� ������� ����� ���������� ������� � ����� ������ ������������
*/
void TLiter::get_old(Date& date)
{
	if (this->_date.late(date))
		cout << "������������ � ����� ������� ��� �� �����!" << endl;
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

		cout << "� ������� ������ ������������ �� ";
		date.print();
		cout << " ������ " << year_diff << " ���(���) " << month_diff << " �����(��) " << day_diff << " ����(����)" << endl;
	}
}

/*
	True, ���� ���������� �����
*/
bool TLiter::authod_equal(TLiter &obj)
{
	if (strcmp(this->_fio, obj._fio) == 0)
		return true;
	else return false;
}

/*
	True, ���� ������������ �������� ����� �����������
*/
bool TLiter::late(TLiter &obj)
{
	if (this->_date.late(obj._date))
		return true;
	else return false;
}

/*
	���������� �������� ������������
*/
char* TLiter::get_name()
{
	return this->_name;
}

/*
	����������
*/
TLiter::~TLiter()
{
}
