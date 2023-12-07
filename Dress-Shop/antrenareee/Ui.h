#include "Service.h"
#ifndef UI_H
#define UI_H

class Ui
{
private:
	Service service;
public:
	Ui();
	Ui(Service service)
	{
		this->service = service;
	}
	~Ui();

	void afisare();
	void top_3();
	void afisare_criterii();
	void cumparare();

	void print_menu();
	bool check_for_digits(string input);
	void start();
};

#endif // 
