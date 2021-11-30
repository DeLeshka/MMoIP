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
				input_and_check(key_word, "кодовое слово");
				input_and_check(filepath, "путь к файлу, который хотите зашифровать");
				cypher(key_word, filepath);
				break;
			case 2:
				input_and_check(key_word, "кодовое слово");
				input_and_check(filepath, "путь к файлу, который хотите расшифровать");
				cypher(key_word, filepath,1);
				break;
			case 3:
				input_and_check(filepath, "путь к файлу, с шифром");
				input_and_check(ref_filepath, "путь к файлу с эталоном языка");
				breaker(filepath, ref_filepath);
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "введите цифру от 0 до 3 для выбора действия" << endl;
				break;
			}

		}
		menu_update();
	}

	return 0;
}