#include <iostream>
#include <vector>
#include "Repo.h"
#include "Service.h"
#include "Teste.h"
#include "Rochii.h"
#include <assert.h>
#include <string>

using namespace std;

/// <summary>
/// teste pentru reposiutory
/// </summary>
void test_repo()
{
	Repo repo = Repo("teste.txt");

	assert(repo.getSize() == 10);

	assert(repo.getAll()[0] == repo.getRochie(0));

	Rochie c = Rochie(2, "Vouge", "M", "roz", 33, 340, false);
	assert(repo.getRochie(1) == c);
	
	Rochie r = Rochie(2, "Vouge", "M", "roz", 56, 340, true);
	repo.updateRochie(1, r);
	
	repo.updateRochie(1, c);
}

void test_rochie()
{
	Rochie r = Rochie(1, "Zara", "S", "albastru", 12, 345, true);
	Rochie c = Rochie(2, "Vouge", "M", "roz", 33, 340, false);

	assert((r == c) == false);
	
	r = c;

	assert(r == c);

	assert(r.getCuloare() == "roz");
	assert(r.getDenumire() == "Vouge");
	assert(r.getId() == 2);
	assert(r.getMarime() == "M");
	assert(r.getNr() == 33);
	assert(r.getPret() == 340);
	assert(r.gsetPersonalizare() == false);
	
	r.setCuloare("mov");
	r.setDenumire("ABra");
	r.setMarime("M");
	r.setNr(67);
	r.setPersonalizare(true);

	assert(r.getCuloare() == "mov");
	assert(r.getDenumire() == "ABra");
	assert(r.getMarime() == "M");

}

/// <summary>
/// teste pt service 
/// </summary>
void test_service()
{
	Repo repo = Repo("teste.txt");
	Service service = Service(repo);

	assert(service.getSize() == 10);

	assert(service.getAll()[0] == service.getRochie(0));

	Rochie c = Rochie(2, "Vouge", "M", "roz", 33, 340, false);
	assert(service.getRochie(1) == c);

	Rochie r = Rochie(2, "Vouge", "M", "roz", 56, 340, true);
	service.updateRochie(1, 2, "Vouge", "M", "roz", 56, 340, true);

	service.updateRochie(1, 2, "Vouge", "M", "roz", 33, 340, false);

	
	std::vector<Rochie> rochite;
	try
	{
		rochite = service.criterii("M", "True");
		assert(rochite.size() == 2);
	}
	catch(MyException& ex)		//.prindem exceptia
	{ }

	try
	{
		rochite = service.top3();
		assert(rochite.size() == 3);
	}
	catch (MyException& ex)
	{
	}

	try
	{
		int nr = service.getRochie(0).getNr();
		service.cumparare(1);
		assert(service.getRochie(0).getNr() == nr - 1);
	}
	catch(MyException& ex)
	{ }

}

void test_all()
{
	test_repo();
	test_rochie();
	test_service();
}