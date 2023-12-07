#include "Ui.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Ui::Ui()
{
}

Ui::~Ui() = default;

void Ui::afisare()
{
    for (int i = 0; i < this->service.getSize(); i++)
    {
        cout << this->service.getRochie(i).tostring() << endl;
    }
}

void Ui::top_3()
{
    try
    {
        std::vector<Rochie> rochite = this->service.top3();
        for (int i = 0; i < rochite.size(); i++)
        {
            cout << rochite[i].tostring() << endl;
        }
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::afisare_criterii()
{
    string marime;
    string person;
    cout << "Input wanted size: ";
    getline(cin, marime);

    cout << "Should it by customizable: ";
    getline(cin, person);

    try
    {
        std::vector<Rochie> rochite = this->service.criterii(marime, person);
        for (int i = 0; i < rochite.size(); i++)
        {
            cout << rochite[i].tostring() << endl;
        }
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

/// <summary>
/// fuhcir de cumparare
/// </summary>
void Ui::cumparare()
{
    string input;
    cout << "Input id of dress which you want to buy: ";
    getline(cin, input);

    int id = stoi(input);

    try
    {
        this->service.cumparare(id);
        cout << service.getRochie(id - 1).tostring();
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

/// <summary>
/// afisam meniul
/// </summary>
void Ui::print_menu()
{
    cout << endl;
    cout << "     DRESS STORE      " << endl;
    cout << "======================" << endl;
    cout << "1. Dresses in store" << endl;
    cout << "2. Print dresses by size and personalization" << endl;
    cout << "3. Buy dress" << endl;
    cout << "4. Top 3 dresses by price" << endl;
    cout << "5. Exit" << endl;
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

void Ui::start()
{
    while (true)
    {
        print_menu();   //se afiseaza meniul

        string input;
        while (true)
        {
            cout << ">";
            getline(cin, input);
            if (check_for_digits(input) == true)
                if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5")   //5 cazuri 
                    break;
            cout << "Invalid option\n";         //daca comanda introdusa la tastatura nu e valida se afiseaza mesajul acesta
        }

        int u_input = stoi(input);  //transformam inputul de tip string in int

        if (u_input == 1)
        {
            afisare();
        }
        else if (u_input == 2)
        {
            afisare_criterii();
        }
        else if (u_input == 3)
        {
            cumparare();
        }
        else if (u_input == 4)
        {
            top_3();
        }
        else if (u_input == 5)
        {
            break;      //iesim din meniu oprind loopul
        }
    }
}