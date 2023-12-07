#pragma warning(disable: 4996)
#include "repofile.h"
#include <cstring>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

RepoFile::RepoFile(string& filename)
{
    this->filename = filename;
    load_from_file();
}

void RepoFile::load_from_file()
{
    ifstream fin;
    fin.open("automat.txt");
    string s;

    while (getline(fin, s)) 
    {
        int cod = 0, pret = 0;
        std::string nume = { 0 };
        string str = s;
        istringstream ss(str);
        string del;
        int ok = 0;

        while (getline(ss, del, ' '))
        {
            if (ok == 0)
            {
                cod = stoi(del);
            }
            else if(ok == 1)
            {
                nume = del;
            }
            else if(ok == 2)
            {
                pret = stoi(del);
            }
            ok++;
        }
        
        addElem(Produs(cod, nume, pret));
    }
    fin.close();
}

void RepoFile::save_to_file()
{
    ofstream fout("automat.txt");
    for (int i = 0; i < getSize(); i++) 
    {
        Produs produs = getElem(i);
        fout << produs.getCod() << " " << produs.getNume() << " " << produs.getPret() << endl;
    }
}

RepoFile::RepoFile()
{
}

RepoFile::~RepoFile()
{

}

void RepoFile::addElem(const Produs& p)
{
	Repo::addElem(p);
	save_to_file();
}

void RepoFile::delElem(int poz)
{
	Repo::delElem(poz);
	save_to_file();
}

int RepoFile::getSize()
{
	return Repo::getSize();
}

bool RepoFile::findPoz(int poz)
{
    return Repo::findPoz(poz);
}

std::vector<Produs> RepoFile::getAll()
{
	return Repo::getAll();
}
