#include "entitate.h"
#include "repo.h"
#include <string.h>
#include <vector>
#ifndef REPOFILE_HEADER
#define REPOFILE_HEADER

class RepoFile: public Repo
{
private:
	std::string filename;
	void load_from_file();
	void save_to_file();

public:
	RepoFile(std::string& filename);
	RepoFile();
	~RepoFile();

	void addElem(const Produs& p);
	void delElem(int poz);
	int getSize();
	bool findPoz(int poz);
	std::vector<Produs> getAll();
};
#endif