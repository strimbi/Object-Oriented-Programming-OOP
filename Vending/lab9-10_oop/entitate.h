#ifndef ENTITATE_H
#define ENTITATE_H
#include <string.h>
#include <sstream>

class Produs 
{
private:
	int cod;
	std::string nume;
	int pret;

public:
	Produs();
	Produs(int cod, std::string nume, int pret);
	~Produs();

	void setCod(int cod);
	void setNume(std::string nume);
	void setPret(int pret);
	int getCod();
	std::string getNume();
	int getPret();
	bool operator==(Produs& p);
	void operator=(const Produs& p);
	std::string tostring();
};

#endif