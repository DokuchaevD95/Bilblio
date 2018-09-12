#pragma once
class Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date();
	Date(int year, int month, int day);
	Date(const Date &obj);
	int get_year();
	int get_month();
	int get_day();
	bool late(Date &obj);
	static int count_days_of_month_and_day(int year, int month);
	void print();
	static Date today();
	static Date create();
	~Date();
};

