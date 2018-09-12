#pragma once

#include "Date.h"


class TLiter
{
private:
	char _name[50];
	char _fio[50];
	Date _date;
public:
	TLiter();
	TLiter(char* name, char* fio, Date date);
	TLiter(const TLiter &obj);
	void get_old(Date& date);
	void print_fio_and_name_only();
	void print();
	bool authod_equal(TLiter &obj);
	bool late(TLiter &obj);
	char* get_name();
	~TLiter();
};

