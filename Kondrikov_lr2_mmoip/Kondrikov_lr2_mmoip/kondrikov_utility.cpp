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
            if (int_check == 1) cout << "������� ����� �����" << endl;
            else                cout << "������� ������������ �����" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void input_and_check(std::string& subject, const std::string& name) {

    cout << "������� " << name << endl;
    getline(std::cin, subject);

}

void show_menu()
{
    cout << "�������� ��������: " << endl <<
        "1 - ����������� ����" << endl << "2 - ������������ ���� (�� �����)" << endl << "3 - �������� ����" << endl
        << "0 - �����" << endl << endl;
}

void menu_update()
{
    std::system("pause");
    std::system("cls");
}