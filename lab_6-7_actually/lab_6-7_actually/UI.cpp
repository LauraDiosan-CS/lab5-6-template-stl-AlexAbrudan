#include "UI.h"


void UI::menu()
{
    cout << "1. Add" << endl;
    cout << "2. Modify. " << endl;
    cout << "3. Delete. " << endl;
    cout << "4. Show all. " << endl;
    cout << "5. Add to cart. " << endl;
    cout << "6. Show all from cart. " << endl;
    cout << "7. Update booking. " << endl;
    cout << "x. Exit" << endl;
}

void UI::add()
{
    int num_f = 0, num_s = 0;
    char* name = new char[50];
    cout << "Enter flight num: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);
    this->s.add(f);
    this->s.save_to_file();
    cout << endl;
    cout << "Added successfully! " << endl << endl;
}

void UI::update()
{
    int num_f = 0, new_num_f = 0, num_s = 0, new_num_s = 0;
    char* name = new char[50];
    char* new_name = new char[50];
    cout << "Enter flight num: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);

    cout << "Enter new flight num: ";
    cin >> new_num_f;
    cout << "Enter new name: ";
    cin >> new_name;
    cout << "Enter new seat num: ";
    cin >> new_num_s;

    this->s.update(f, new_num_f, new_name, new_num_s);
    this->s.save_to_file();
    cout << endl;
    cout << "Updated successfully! " << endl << endl;
}

void UI::del()
{
    int num_f = 0, num_s = 0;
    char* name = new char[50];
    cout << "Enter flight num: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);
    this->s.del(f);
    this->s.save_to_file();
    cout << "Deleted successfully! " << endl << endl;
}

void UI::all()
{
    list <Flight> res = this->s.get_all();
    cout << endl;
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop_front();
    }
    cout << endl;
}

void UI::add_to_cart()
{
    int num_f = 0, num_s = 0;
    char* name = new char[50];
    cout << "Enter flight num: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);
    this->s.add_to_cart(f);
    cout << endl << endl;
}

void UI::all_cart()
{
    list <Flight> res = this->s.get_all_cart();
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop_front();
    }
    cout << endl;
}

void UI::update_booking()
{
    int num_f = 0, new_num_f = 0, num_s = 0, new_num_s = 0;
    char* name = new char[50];
    cout << "Enter flight num: ";
    cin >> num_f;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter seat number: ";
    cin >> num_s;
    Flight f(num_f, name, num_s);

    cout << "Enter new seat number: ";
    cin >> new_num_s;
    if (this->s.update_booking(f, new_num_s) == 0)
        cout << "Booking updated successfully!" << endl;
    if (this->s.update_booking(f, new_num_s) == -1)
        cout << "Rezervarea nu exista!" << endl;
    if (this->s.update_booking(f, new_num_s) == -2)
        cout << "Locul introdus este ocupat" << endl;
    if (this->s.update_booking(f, new_num_s) == -3)
        cout << "Locul nu exista! " << endl;
}

void UI::uwu()
{
    char op = ' ';
    while (true)
    {
        this->menu();
        cout << "Op: ";
        cin >> op;
        switch (op)
        {
        case '1': {this->add(); break; }
        case '2': {this->update(); break; }
        case '3': {this->del(); break; }
        case '4': {this->all(); break; }
        case '5': {this->add_to_cart(); break; }
        case'6': {this->all_cart(); break; }
        case '7': {this->update_booking(); break; }
        case 'x': {exit(0); break; }
        }
    }
}