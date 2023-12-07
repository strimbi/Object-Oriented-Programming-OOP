#include <string.h>
#include <iostream>
#ifndef ENTITATE_H
#define ENTITATE_H

using namespace std;

class Bacterie
{
private:
	string denumire;
	int varsta;
	int tip;
public:
	Bacterie();
	~Bacterie();
	Bacterie(string denumire, int varsta, int tip);

	void setDenumire(string denumire);
	void setVarsta(int varsta);
	void setTip(int tip);

	string getDenumire();
	int getVarsta();
	int getTip();

	bool operator==(const Bacterie& c);
	void operator=(const Bacterie& c);

	std::string tostring();
};
#endif // !ENTITATE_H