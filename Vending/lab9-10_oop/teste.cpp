#include <iostream>
#include <assert.h>
#include "teste.h"
#include "entitate.h"
#include "service.h"
#include "repo.h"
#include "collection.h"
#include "repofile.h"

using namespace std;

void test_entitate()
{
	Produs p1(7321, (char*)"ciocolata", 10);
	assert(p1.getCod() == 7321);
	assert(p1.getNume() == "ciocolata");
	assert(p1.getPret() == 10);
	
	p1.setCod(772);
	assert(p1.getCod() == 772);
	
	p1.setNume((char*)"suc");
	assert(p1.getNume() == "suc");

	p1.setPret(12);
	assert(p1.getPret() == 12);

	Produs p2(7321, (char*)"ciocolata", 10);
	assert(p1 == p2 == false);
}

void test_repo()
{
	Repo repo;
	assert(repo.getSize() == 0);

	repo.addElem(Produs(7321, (char*)"ciocolata", 5));
	repo.addElem(Produs(431, (char*)"suc", 10));
	repo.addElem(Produs(8531, (char*)"corn", 8));
	assert(repo.getSize() == 3);
	
	repo.delElem(0);
	assert(repo.getSize() == 2);
	
	assert(repo.getAll()[0].getCod() == 431);
	
	repo.update(0, Produs(100, (char*)"cioco", 12));
	assert(repo.getAll()[0].getCod() == 100);
}

void test_service()
{
	Service service;
	assert(service.getSize() == 3);
	
	service.addElem(8531, (char*)"corn", 8);
	assert(service.getSize() == 4);

	service.delElem(3);
	assert(service.getSize() == 3);

	assert(service.getAll()[0].getCod() == 4237);
}

void test_service_collectie()
{
	Service service;
	assert(service.colSize() == 3);
	assert(service.colNroc(2) == 4);

	service.colAddElem(10);
	assert(service.colSize() == 4);
	assert(service.colNroc(10) == 1);

	service.coldDelElem(2);
	assert(service.colNroc(2) == 3);
}
void test_repo_file()
{
	std::string filename = R"(C:\Users\User\source\repos\lab9-10_oop\filetest.txt)";
	RepoFile repo = RepoFile(filename);
	assert(repo.getSize() == 3);

	repo.addElem(Produs(123, (char*)"kinder", 7));
	assert(repo.getSize() == 4);

	repo.delElem(3);
	assert(repo.getSize() == 3);
}

void teste()
{
	test_entitate();
	test_repo();
	test_service_collectie();
}