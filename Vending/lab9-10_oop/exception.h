#ifndef MYEXCEPTION_HEADER
#define MYEXCEPTION_HEADER

#include <iostream>
using namespace std;

class MyException : public std::exception 
{
private:
    std::string message = "My Excpetion2";

public:
    MyException(const std::string& msg = "")
    {
        this->message = msg;
    }
    string what() 
    {                                                                   
        return (this->message).c_str();
    }
};

#endif // !MYEXCEPTION_HEADER