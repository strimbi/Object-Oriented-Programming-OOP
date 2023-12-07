#ifndef ROCHII_HEADER
#define ROCHII_HEADER

#include <string>
using namespace std;

class Rochie
{
private:
	int id;
	string denumire;
	string marime;
	string culoare;
	int nr;
	int pret;
	bool personabilizare;
public:
	Rochie();
	Rochie(int id, string denumire, string marime, string culoare, int nr, int pret, bool personabilizare);
	~Rochie();

	void setId(int id);
	void setDenumire(string denumire);
	void setMarime(string marime);
	void setCuloare(string culoare);
	void setNr(int nr);
	void setPret(int pret);
	void setPersonalizare(bool person);

	int getId();
	string getDenumire();
	string getMarime();
	string getCuloare();
	int getNr();
	int getPret();
	bool gsetPersonalizare();

	void operator=(const Rochie& c);
	bool operator==(const Rochie& c);

	string tostring();
};
#endif // !ROCHII_HEADER
