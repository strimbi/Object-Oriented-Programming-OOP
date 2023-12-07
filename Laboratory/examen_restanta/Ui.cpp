#include "Ui.h"
#include <string>
#include <iostream>

Ui::Ui()
{
}

Ui::~Ui() = default;

void Ui::print_menu()
{
    cout << endl;
    cout << "     LABORATORY     " << endl;
    cout << "======================" << endl;
    cout << "1. Visualization of bacteria in their initial state " << endl;
    cout << "2. Visualization of bacteria by type in the initial state" << endl;
    cout << "3. Visualization of bacteria after a number of time units" << endl;
    cout << "4. View the average age of bacteria at a specific point in time" << endl;
    cout << "5. Close" << endl;

}

/// <summary>
/// functie pentru a verifica daca stringul e numai din cifre
/// </summary>
/// <param name="input"></param>
bool Ui::check_for_digits(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;
    }
    return true;
}

void Ui::afisare_bacterii()
{
    for (int i = 0; i < this->service.getSize(); i++)
    {
        cout << this->service.getBacterie(i).tostring() << endl;
    }
}

void Ui::afisare_dupa_tip()
{
    string input;
    cout << "Input wanted type:";
    getline(cin, input);
    int tip = stoi(input);

    try
    {
        std::vector<Bacterie> bacteriase = this->service.returnare_bacterii_tip(tip);
        for (int i = 0; i < bacteriase.size(); i++)
        {
            cout << bacteriase[i].tostring() << endl;
        }
    }
    catch (MyException& ex)
    {
        cout << ex.what() << endl;
    }
}

void Ui::medie_varsta()
{
    string input;
    cout << "Input wanted time units to calculate the average life:";
    getline(cin, input);
    int timp = stoi(input);

    std::vector<Bacterie> bacteriase = this->service.inmultire(timp);
    int medie = this->service.medie(bacteriase);

    cout << "Average life is: " << medie << endl;
}

void Ui::inmultire()
{
    string input;
    cout << "Input wanted time:";
    getline(cin, input);
    int timp = stoi(input);

    if (timp != 0)
    {

        std::vector<Bacterie> bacteriase = this->service.inmultire(timp);
        for (int i = 0; i < bacteriase.size(); i++)
        {
            cout << bacteriase[i].tostring() << endl;
        }
    }
    else
    {
        this->afisare_bacterii();
    }
}

void Ui::add_bacterii_initiale()
{
    this->service.addBacterie("Homdonc",0, 2);
    this->service.addBacterie("Mnicolo", 0, 1);
    this->service.addBacterie("Koala", 0, 2);
    this->service.addBacterie("Yuliana", 0, 1);
}

void Ui::start()
{
    add_bacterii_initiale();

    while (true)
    {
        print_menu();   ///se afiseaza meniul

        string input;
        while (true)
        {
            cout << ">";
            getline(cin, input);
            if (check_for_digits(input) == true)
                if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5")   //5 cazuri 
                    break;
            cout << "Invalid option\n";         ///daca comanda introdusa la tastatura nu e valida se afiseaza mesajul acesta
        }

        int u_input = stoi(input);  ///transformam inputul de tip string in int

        if (u_input == 1)
        {
            afisare_bacterii();
        }
        else if (u_input == 2)
        {
            afisare_dupa_tip();
        }
        else if (u_input == 3)
        {
            inmultire();
        }
        else if (u_input == 4)
        {
            medie_varsta();
        }
        else if (u_input == 5)
        {
            break;      ///iesim din meniu oprind loopul
        }
    }
}
