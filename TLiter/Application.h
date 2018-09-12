#pragma once
#include "TLiter.h"


class Application
{
private:
	const int _capacity = 16;
	const char filename[20] = "base.txt";
	int _limit;
	int _count;
	TLiter* _array;
	void resize();
	void print();
	void print_all(bool full = true);
	void author_equal();
	void date_compare();
	void old();
	int choose();
	bool import_from_file();
public:
	Application();
	void start();
	~Application();
};

