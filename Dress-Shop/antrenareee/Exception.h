#ifndef MYEXCEPTION_HEADER
#define MYEXCEPTION_HEADER

#include <iostream>
using namespace std;

/// <summary>
/// clasa de Exceptie care mostenste clasa exception
/// </summary>
class MyException : public std::exception
{
private:
    std::string message = "My Excpetion2";      //parametrul care primeste textul pe care vrem sa l afisam in cazul exceptiei

public:
    MyException(const std::string& msg = "")
    {
        this->message = msg;        //constructor cu parametru 
    }
    string what()
    {
        return (this->message).c_str();     //se returneaza mesajul de exceptie ca string
    }
};

#endif // !MYEXCEPTION_HEADER