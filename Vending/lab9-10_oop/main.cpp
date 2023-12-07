#include <iostream>
#include "teste.h"
#include "ui.h"
#include "exception.h"

using namespace std;

int main()
{
	string file_name = R"(C:\Users\User\source\repos\lab9-10_oop\automat.txt)";
	RepoFile repo = RepoFile(file_name);
	Service service = Service(repo);
    Ui ui = Ui(service);
	cout << "Tests loading..." << endl;
	teste();
	cout << "Tests finished!" << endl << endl;
	ui.start();
}