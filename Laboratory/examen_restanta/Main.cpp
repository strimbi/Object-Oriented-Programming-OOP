#include "Teste.h"
#include "Ui.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Ui ui;
	cout << "Tests running...." << endl;
	test_all();
	cout << "Tests finished!!" << endl;			///mesaj afirmativ cand testele au trecut fara probleme
	ui.start();
}