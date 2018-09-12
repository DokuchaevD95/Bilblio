#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>

#include "Date.h"


using namespace std;


/*
	����������� ��� ����������
*/
Date::Date()
{
	this->_year = 1970;
	this->_month = this->_day = 1;
}

/*
	����������� � �����������
*/
Date::Date(int year, int month, int day)
{
	this->_year = year;
	this->_month = month;
	this->_day = day;
}

/*
	����������� �����������
*/
Date::Date(const Date& obj)
{
	this->_year = obj._year;
	this->_month = obj._month;
	this->_day = obj._day;
}

/*
	������� ����� ��������� ������ Date
*/
Date Date::create()
{
	int year, month, day;
	bool error;
	cout << "���� ����/��/��" << endl << endl;
	do
	{
		error = false;
		// ���������� ����
		cout << "���: ";
		cin >> year;
		cin.ignore();
		if (year > 2020 || year < 1920)
		{
			error = true;
		}
		// ���������� ������
		cout << "�����: ";
		cin >> month;
		cin.ignore();
		if (month < 1 || month > 12)
		{
			error = true;
		}
		// ���������� ���
		cout << "����: ";
		cin >> day;
		cin.ignore();
		if (day < 1)
		{
			error = true;
		}
		if (month < 7)
		{
			// �������� �������
			if (month == 2)
			{
				// �������� �� ���������� ���
				if (year % 4 == 0)
				{
					if (day > 29)
						error = true;
				}
				else
				{
					if (day > 28)
						error = true;
				}
			}
			// �������� ������ �������, �� ������ ������������
			else
			{
				if (month % 2 == 1)
				{
					if (day > 31)
						error = true;
				}
				else
					if (day > 30)
						error = true;
			}
		}
		// �������� ������� ����� �������
		else
		{
			if (month % 2 == 0)
			{
				if (day > 31)
					error = true;
			}
			else
				if (day > 30)
					error = true;
		}

		if (error)
			cout << "�������� ������ � ���������� ������ �� ����� ����!" << endl << endl;
	} while (error);

	return Date(year, month, day);
}

/*
	�����, ��������� ���� �� �����
*/
void Date::print()
{
	cout << this->_year << "/" << this->_month << "/" << this->_day;
}

/*
	�����, ������� �������� ������� ����
*/
Date Date::today()
{
	time_t seconds = time(NULL);
	tm* time_info = localtime(&seconds);
	return Date(1900 + time_info->tm_year, time_info->tm_mon + 1, time_info->tm_mday);
}

/*
	������ ����
*/
int Date::get_year()
{
	return this->_year;
}

/*
	������ ������
*/
int Date::get_month()
{
	return this->_month;
}

/*
	������ ���
*/
int Date::get_day()
{
	return this->_day;
}

/*
	���������� ���������� ���� � ������������ ������ � ����
*/
int Date::count_days_of_month_and_day(int year, int month)
{
	if (month > 12 || month < 1)
		return 0;
	else
	{
		if (month < 7)
		{
			if (month == 2)
			{
				if (year % 4 == 0)
				{
					return 29;
				}
				else
				{
					return 28;
				}
			}
			else
			{
				if (month % 2 == 1)
				{
					return 31;
				}
				else
					return 30;
			}
		}
		else
		{
			if (month % 2 == 0)
			{
				return 31;
			}
			else
				return 30;
		}

	}
}

/*
	��������, ������ ���� ����� �� ������� ���� ������������ ����������
*/
bool Date::late(Date &obj)
{
	if (this->_year > obj._year)
	{
		return true;
	}
	else
	{
		if (this->_year == obj._year && this->_month > obj._month)
		{
			return true;
		}
		else
		{
			if (this->_year == obj._year && this->_month == obj._month && this->_day > obj._day)
			{
				return true;
			}
			else return false;
		}
	}
}

/*
	����������
*/
Date::~Date()
{
}
