#include "exception.h"
#ifndef MYVALIDATOR_HEADER
#define MYVALIDATOR_HEADER

class Validator
{
public:
	void validatepret(int pret)
	{
		if (pret < 0) throw MyException("Pretul este invalid");
	}
	void validatecod(int cod)
	{
		if (cod < 0 || cod >1000) throw MyException("Codul este invalid");
	}
	void validatenume(std::string nume)
	{
		if(nume.size() > 30) throw MyException("Numele este prea lung");
	}

};

#endif // !MYVALIDATOR_HEADER