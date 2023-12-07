#include "Repo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Repo::Repo()
{
}

Repo::Repo(string name)
{
	this->filename = name;  ///atribuim fisierul
	readfromfile();
}

Repo::~Repo()
{
}

/// <summary>
/// functie pentru citirea din fisier
/// </summary>
void Repo::readfromfile()
{
    ifstream fin;
    fin.open(this->filename);
    string s;

    while (getline(fin, s))
    {
        int id = 0;
        string nume = "";
        string marime = "";
        string culoare = "";
        int nr = 0;
        int pret = 0;
        bool ok = false;

        string str = s;
        istringstream ss(str);
        string del;
        int numaratoare = 0;

        while (getline(ss, del, ' '))
        {
            if (numaratoare == 0)
            {
                id = stoi(del);
            }
            else if (numaratoare == 1)
            {
                nume = del;
            }
            else if (numaratoare == 2)
            {
                marime = del;
            }
            else if (numaratoare == 3)
            {
                culoare = del;
            }
            else if (numaratoare == 4)
            {
                nr = stoi(del);
            }
            else if (numaratoare == 5)
            {
                pret = stoi(del);
            }
            else if (numaratoare == 6)
            {
                if (del == "True") ok = true;
                else ok = false;
            }
            numaratoare++;
        }
       rochii.push_back(Rochie(id, nume, marime, culoare, nr, pret, ok));
    }
    fin.close();
}

/// <summary>
/// functie pentru scrierea in fisier
/// </summary>
void Repo::writetofile()
{
    ofstream fout(filename);
    for (int i = 0; i < this->getSize(); i++)
    {
        string pers;
        Rochie c = this->getRochie(i);
        if (c.gsetPersonalizare() == false) pers = "False";
        else pers = "True";
        fout << c.getId() << " " << c.getDenumire() << " " << c.getMarime() << " " << c.getCuloare() <<
            " " << c.getNr() << " " << c.getPret() << " " << pers << endl;
    }
    fout.close();
}

int Repo::getSize()
{
	return rochii.size();
}

void Repo::updateRochie(int poz, const Rochie& c)
{
	this->rochii[poz] = c;
}

Rochie Repo::getRochie(int poz)
{
	return rochii[poz];
}

std::vector<Rochie> Repo::getAll()
{
	return rochii;
}
