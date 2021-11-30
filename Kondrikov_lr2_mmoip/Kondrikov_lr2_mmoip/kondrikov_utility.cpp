#include "kondrikov_utility.h"
#include <iostream>

using namespace std;

void input_number(double& subject, const bool& int_check) {
    while (true) {
        subject = 0;
        cin >> subject;
        if (cin.good() && (!(subject - int(subject)) || int_check == 0)) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        else {
            if (int_check == 1) cout << "Введите целое число" << endl;
            else                cout << "Введите вещественное число" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void input_and_check(std::string& subject, const std::string& name) {

    cout << "Введите " << name << endl;
    getline(std::cin, subject);

}

void show_menu()
{
    cout << "Выберете действие: " << endl <<
        "1 - Зашифровать файл" << endl << "2 - Расшифровать файл (по ключу)" << endl << "3 - Взломать файл" << endl
        << "0 - Выйти" << endl << endl;
}

void menu_update()
{
    std::system("pause");
    std::system("cls");
}