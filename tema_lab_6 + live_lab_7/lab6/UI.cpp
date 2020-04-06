#include "UI.h"


void UI::show_menu()
{
    cout << "1. Add flight. " << endl;
    cout << "2. Show all flights. " << endl;
    cout << "3. Modify flight. " << endl;
    cout << "4. Delete flight. " << endl;
    cout << "5. Find flight. " << endl;
    cout << "6. Book flight. " << endl;
    cout << "x. Exit. " << endl;
}

void UI::add()
{
    int num_s, num_f;
    char* name = new char[50];
    cout << "Enter flight number: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);
    this->s.add(f);
    cout << "Flight added successfully!" << endl << endl;
}

void UI::show_all()
{
    list <Flight> res = this->s.get_all();
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop_front();
    }
    cout << endl;
}

void UI::del()
{
    int given_num_s = 0;
    int given_num_f = 0;
    char* name = new char[50];
    cout << "Enter deleted flight number: ";
    cin >> given_num_f;
    cout << "Enter deleted name: ";
    cin >> name;
    cout << "Enter deleted seat number: ";
    cin >> given_num_f;
    Flight f(given_num_f, name, given_num_s);
    this->s.del(f);
    cout << "Entry deleted successfully!" << endl << endl;
}

void UI::modify()
{
    char* new_name = new char[50];
    int new_num_f = 0;
    int given_num_s = 0;
    int new_num_s = 0;

    char* given_name = new char[50];
    int given_num_f = 0;

    cout << "Enter modified flight number: ";
    cin >> given_num_f;
    cout << "Enter modified name: ";
    cin >> given_name;
    cout << "Enter modified seat number: ";
    cin >> given_num_s;
    Flight f(given_num_f, given_name, given_num_s);
    cout << "Enter new flight number: ";
    cin >> new_num_f;
    cout << "Enter new name: ";
    cin >> new_name;
    cout << "Enter new seat number: ";
    cin >> new_num_s;
    Flight f2(new_num_f, new_name, new_num_s);
    this->s.modify(f, f2);
    cout << "Entry modified successfully!" << endl << endl;
    delete[] new_name;
}

void UI::get_elem()
{
    int given_num_s = 0;
    cout << "Enter the seat number of the flight you are searching for: ";
    cin >> given_num_s;
    cout << this->s.get_elem(given_num_s);
    cout << endl << endl;
}

void UI::book_elem()
{
    int given_num_s = 0, given_num_f = 0;
    char* given_name = new char[50];
    cout << "Enter flight number: ";
    cin >> given_num_f;
    cout << "Enter name: ";
    cin >> given_name;
    cout << "Enter seat number: ";
    cin >> given_num_s;
    s.add_to_cart(given_num_f, given_name, given_num_s);
    cout << endl;
}

void UI::show_all_booked()
{
    list<Flight> res = s.get_all_cart();
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop_front();
    }
    cout << endl;
}

void UI::UwU()
{
    char op = ' ';
    while (true)
    {
        this->show_menu();
        cout << "Enter option: ";
        cin >> op;
        cout << endl;
        switch (op)
        {
        case '1': {this->add(); break; }
        case '2': {this->show_all(); break; }
        case '3': {this->modify(); break; }
        case '4': {this->del(); break; }
        case '5': {this->get_elem(); break; }
        case '6': {this->book_elem(); break; }
        case '7': {this->show_all_booked(); break; }
        case 'x': {exit(0); break; }
        }
    }
}