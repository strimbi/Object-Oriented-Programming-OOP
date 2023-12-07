#include <iostream>
#include "Entitate.h"
#include "Teste.h"
#include "Repo.h"
#include "Service.h"
#include "Exception.h"
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

void test_entitate()
{
	Bacterie b = Bacterie("Homdonc", 1, 2);

	assert(b.getTip() == 2);
	assert(b.getDenumire() == "Homdonc");
	assert(b.getVarsta() == 1);

	Bacterie c = Bacterie("Mnicolo", 0, 1);

	assert(b == c == false);

	b = c;
	assert(b.getTip() == 1);
	assert(b.getDenumire() == "Mnicolo");
	assert(b.getVarsta() == 0);
}

/// <summary>
/// Teste pentru repo
/// </summary>
void test_repo()
{
	Repo repo;

	assert(repo.getSize() == 0);

	repo.addBacterie(Bacterie("Mnicolo", 0, 1));
	Bacterie c = Bacterie("Mnicolo", 0, 1);
	
	assert(c == repo.getBacterie(0));

	assert(repo.getAll().size() == 1);

}

/// <summary>
/// teste pt service
/// </summary>
void test_service()
{
	Service service;

	assert(service.getSize() == 0);

	service.addBacterie("Mnicolo", 0, 1);
	Bacterie c = Bacterie("Mnicolo", 0, 1);

	assert(c == service.getBacterie(0));

	assert(service.getAll().size() == 1);

	assert(service.returnare_bacterii_tip(1).size() == 1);	/// avem 1 de tipul 1

	assert(service.inmultire(2).size() == 4);  ///test pentru inmultirea
	assert(service.medie(service.inmultire(2)) == 1); ///test pentru medie
	
}

void test_all()
{
	test_entitate();
	test_repo();
	test_service();
}