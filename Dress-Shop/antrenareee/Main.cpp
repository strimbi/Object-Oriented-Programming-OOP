#include "Teste.h"
#include "Ui.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Repo repo = Repo("Rochii.txt");		//creem repository ul cu fisierul din care dorim sa extragem datele
	Service service = Service(repo);			//construim service cu acel repository
	Ui ui = Ui(service);					//construim ui cu service ul de mai sus
	cout << "Tests running...." << endl;
	test_all();
	cout << "Tests finished!!" << endl;			//mesaj afirmativ cand testele au trecut fara probleme
	ui.start();
}