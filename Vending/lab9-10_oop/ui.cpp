#include <iostream>
#include <string>
#include "ui.h"
#include "exception.h"

using namespace std;

Ui::Ui(Service service)
{
    this->service = service;
}

Ui::Ui()
{
    
}

bool Ui::check_for_digits(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;
    }
    return true;
}

bool Ui::compare_strings(string str1, string str2)
{
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

void Ui::print_main_menu() {

    cout << "\n";
    cout << "      ~VENDING MACHINE~\n";
    cout << "=========================\n";
    cout << "1 - List products\n";
    cout << "2 - Add products\n";
    cout << "3 - Delete products\n";
    cout << "4 - Buy products\n";
    cout << "5 - Print coins from machine\n";
    cout << "6 - Exit\n";
}

void Ui::listeaza()
{
    try
    {
        for (int i = 0; i < service.getSize(); i++)
        {
            cout << i + 1 << "\n" << service.getAll()[i].tostring() << "\n";
        }
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::addElem()
{
    try
    {
        string input;
        std::string nume;

        cout << "Input code: " << endl;
        getline(cin, input);
        int cod = stoi(input);

        cout << "Input name: " << endl;
        getline(cin, nume);

        cout << "Input price: " << endl;
        getline(cin, input);
        int pret = stoi(input);

        service.addElem(cod, nume, pret);
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::delElem()
{
    string input;
    cout << "Input code: ";
    getline(cin, input);
    int poz = stoi(input);
    try
    {
        service.delElem(poz);
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::showCole()
{
    try
    {
        for (int i = 0; i < service.colSize(); i++)
        {
            cout << "Coin " << service.colgetElem(i) << " in number of " << service.colNroc(service.colgetElem(i)) << endl;
        }
    }
    catch (MyException &ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::buy()
{
    string input;
    cout << "What do you want to buy? ";
    getline(cin, input);
    std::string nume = input;

    Produs produs;
    bool ok = false;

    for (int i = 0; i < service.getSize(); i++)
    {
        if (compare_strings(nume, service.getElem(i).getNume()) == true)
        {
             ok = true;
             produs = service.getElem(i);
             break;
        }
    }

    if (ok == true)
    {
        cout << "Price is: " << produs.getPret() << endl;
        cout << "Input coin: ";
        getline(cin, input);

        int moneda = stoi(input);
        int rest = moneda - produs.getPret();

        try

        {
            if (service.searchcol(rest) == true)
            {
                service.coldDelElem(rest);
                service.colAddElem(moneda);
                service.delElem(service.getPoz(produs));
                cout << "--Product purchased! " << endl;
                cout << "--Change: " << rest << endl;
            }
        }
        catch (MyException& ex)
        {
            cout << ex.what() << endl;
        }
    }
    else if(ok == false)
    {
        cout << "This product does not exist" << endl;
    }
}

void Ui::start()
{
    while (true)
    {
        print_main_menu();

        string input;
        while (true)
        {
            cout << ">";
            getline(cin, input);
            if (check_for_digits(input) == true)
                if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6")
                    break;
            cout << "Invalid option\n";
        }

        int u_input = stoi(input);

        if (u_input == 1)
        {
            listeaza();
        }
        else if (u_input == 2)
        {
            addElem();
        }
        else if (u_input == 3)
        {
            delElem();
        }
        else if (u_input == 4)
        {
            buy();
        }
        else if (u_input == 5)
        {
            showCole();
        }
        else if (u_input == 6)
        {
            break;
        }
    }
}

Ui::~Ui() = default;