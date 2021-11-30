#include "kondrikov_hack.h"
#include "kondrikov_default_vigener.h"
#include "kondrikov_utility.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double choice;
	string key_word;
	string filepath;
	string ref_filepath;

	while (true) {

		show_menu();

		{
			input_number(choice, 1);
			switch (int(choice))
			{
			case 1:
				input_and_check(key_word, "������� �����");
				input_and_check(filepath, "���� � �����, ������� ������ �����������");
				cypher(key_word, filepath);
				break;
			case 2:
				input_and_check(key_word, "������� �����");
				input_and_check(filepath, "���� � �����, ������� ������ ������������");
				cypher(key_word, filepath,1);
				break;
			case 3:
				input_and_check(filepath, "���� � �����, � ������");
				input_and_check(ref_filepath, "���� � ����� � �������� �����");
				breaker(filepath, ref_filepath);
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "������� ����� �� 0 �� 3 ��� ������ ��������" << endl;
				break;
			}

		}
		menu_update();
	}

	return 0;
}