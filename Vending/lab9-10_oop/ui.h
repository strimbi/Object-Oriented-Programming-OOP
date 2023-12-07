#ifndef UI_H
#define UI_H
#include <iostream>
#include "service.h"
#include "collection.h"
#include <cstring>
#include <string.h>

using namespace std;

class Ui
{
private:
	Service service;

public:
	Ui();
	Ui(Service service);
	~Ui();

	void listeaza();
	void addElem();
	void delElem();
	void showCole();
	void buy();

	bool compare_strings(string str1, string str2);
	bool check_for_digits(string input);
	void print_main_menu();
	void start();
};

#endif // !UI_H

