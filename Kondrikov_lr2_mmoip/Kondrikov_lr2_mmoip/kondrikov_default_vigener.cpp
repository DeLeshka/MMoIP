#include <vector>
#include <iostream>
#include "kondrikov_default_vigener.h"
#include "kondrikov_utility.h"

using namespace std;

void cypher(const string& key_string, const string& filepath, const bool& decypher)
{
    vector<unsigned char> key;
    ifstream fin(filepath, ios::binary);
    if (fin.is_open()) {

        for (auto i : key_string) {
            key.emplace_back(i);
        }

        string out_filepath;
        input_and_check(out_filepath, "имя файла для сохранения результата");
        ofstream fout(out_filepath, ios::binary);

        if (fout.is_open()) {
            int i = 0;
            unsigned char iter_char;
            unsigned char alg_char;
            while (fin >> std::noskipws >> iter_char) {
                alg_char = iter_char + (decypher ? -key[i++] : key[i++]);
                if (i >= key.size()) i = 0;
                fout << alg_char;
            }
            fout.close();

            cout << "Файл " << filepath << " успешно " << (decypher ? "дешифрован" : "зашифрован") << endl;

            if (decypher == 1) {
                ifstream fin_2(out_filepath, ios::binary);
                vector<char> save_file_output((istreambuf_iterator<char>(fin_2)), istreambuf_iterator<char>());
            }

        }
        else {
            cout << "Не удалось создать/открыть файл выбранный для сохранения" << endl;
            return;
        }
    }
    else {
        cout << "Не удалось открыть выбранный файл" << endl;
        return;
    }
    fin.close();
}