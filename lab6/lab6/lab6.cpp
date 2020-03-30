// lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Flight.h"
#include "Repo.h"
#include "tests.h"


using namespace std;

int main()
{
    all_tests();
    Repo r;
    char op = ' ';
    while (true)
    {
        cout << "1. Add flight." << endl;
        cout << "2. Show all flights. " << endl;
        cout << "x. Exit. " << endl;
        cout << "Insert option: ";
        cin >> op;
        cout << endl;
        switch (op)
        {
            case '1':
            {
                int num_s, num_f;
                char* name = new char[50];
                cout << "Introduceti numarul zborului: ";
                cin >> num_f;
                cout << "Introduceti numele: ";
                cin >> name;
                cout << "Introduceti numarul locului: ";
                cin >> num_s;
                Flight f(num_f, name, num_s);
                r.add(f);
                cout << "Flight added successfully!" << endl;
                cout << endl;
                break;
            }
            case '2':
            {
                list<Flight> res = r.get_all();
                while (!res.empty())
                {
                    cout << res.front() << endl;
                    res.pop_front();
                }
                cout << endl<<endl;
                break;
            }
            case 'x':
            {
                exit(0);
                break;
            }
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
