#include "Service.h"
#ifndef UI_HEADER
#define UI_HEADER

class Ui
{
private:
	Service service;
public:
	Ui();
	~Ui();

	void afisare_bacterii();
	void inmultire();

	void add_bacterii_initiale();
	void afisare_dupa_tip();

	void medie_varsta();

	void print_menu();
	bool check_for_digits(string input);
	void start();
};
#endif // !UI_HEADER
