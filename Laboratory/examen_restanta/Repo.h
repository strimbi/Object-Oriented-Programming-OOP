#include "Entitate.h"
#include <vector>
#include <string>
#ifndef REPO_HEADER
#define REPO_HEADER

using namespace std;

class Repo
{
private:
	std::vector<Bacterie> bacterii;

public:
	Repo();
	~Repo();

	int getSize();
	Bacterie getBacterie(int poz);
	std::vector<Bacterie> getAll();
	void updateBacterie(int poz, const Bacterie& c);

	void addBacterie(const Bacterie& c);
};
#endif // !REPO_HEADER
