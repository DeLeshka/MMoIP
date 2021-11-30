#include "kondrikov_hack.h"
#include "kondrikov_utility.h";
#include "kondrikov_default_vigener.h"


using namespace std;

void breaker(const std::string& coded_file_path, const std::string& reference_file_path)
{
    ifstream fin_1(coded_file_path, ios::binary);
    vector<unsigned char> code_file((istreambuf_iterator<char>(fin_1)), istreambuf_iterator<char>());

    ifstream fin_2(reference_file_path, ios::binary);
    vector<unsigned char> ref_file((istreambuf_iterator<char>(fin_2)), istreambuf_iterator<char>());
   
    vector<double> table;
    table.resize(20);

    cout << "Индексы соответсвия:" << endl;

    for (int group_count = 1; group_count <= 20; group_count++) {
        int current_group = 0;

        vector<unordered_map<unsigned char, int>> group_frequencies;
        group_frequencies.resize(group_count);

        vector<double> indexes;
        indexes.resize(group_count);

        vector<int> group_length(group_count, 0);

        for (auto i: code_file) {
            if (current_group == group_count) current_group = 0;
            auto has_been_found = group_frequencies[current_group].find(i);
            if (has_been_found == group_frequencies[current_group].end()) {
                group_frequencies[current_group].emplace(i, 1);
            }
            else {
                group_frequencies[current_group][i]++;
            }
            group_length[current_group]++;
            current_group++;
        }

        for (int j = 0; j < group_frequencies.size(); j++) {
            indexes[j] = affinity_index(group_frequencies[j], group_length[j]);
        }

        table[group_count - 1] = *max_element(indexes.begin(), indexes.end());
    }
    
    for (int j = 0; j < table.size(); j++) {
        cout << j + 1 << "\t" << " : " << "\t" << table[j]<<endl;
    }

    cout << "На основании данных представленной таблицы введите предполагаемую длину кодового слова:" << endl;

    string keyword;
    double keyword_length;
    input_number(keyword_length, 1);

    unordered_map<unsigned char, int> reference_frequencies;
    for (auto i : ref_file) {
        auto has_been_found = reference_frequencies.find(i);
        if (has_been_found == reference_frequencies.end()) {
            reference_frequencies.emplace(i, 1);
        }
        else {
            reference_frequencies[i]++;
        }
    }

    auto ref_most_common_letter = std::max_element(reference_frequencies.begin(), reference_frequencies.end(),
        [](const pair<unsigned char, int>& p1, const pair<unsigned char, int>& p2) {
            return p1.second < p2.second; });

    int current_group = 0;

    vector<unordered_map<unsigned char, int>> group_frequencies;
    group_frequencies.resize(keyword_length);
    vector<int> group_length(keyword_length, 0);

    for (auto i : code_file) {
        if (current_group == keyword_length) current_group = 0;
        auto has_beean_found = group_frequencies[current_group].find(i);
        if (has_beean_found == group_frequencies[current_group].end()) {
            group_frequencies[current_group].emplace(i, 1);
        }
        else {
            group_frequencies[current_group][i]++;
        }
        group_length[current_group]++;
        current_group++;
    }


    for (auto j : group_frequencies) {
        auto group_most_common_letter = std::max_element(j.begin(), j.end(),
            [](const pair<unsigned char, int>& p1, const pair<unsigned char, int>& p2) {
                return p1.second < p2.second; });
        keyword.push_back(group_most_common_letter->first - ref_most_common_letter->first);
    }

    cout << "Найденное на основании референсного текста кодовое слово: " << endl;
    cout << keyword << endl;



    cypher(keyword, coded_file_path, 1);
}

double affinity_index(unordered_map<unsigned char, int>& frequencies, int& text_length)
{
    double znam = 0;
    for (auto i : frequencies) {
        znam += double(i.second * (i.second - 1));
    }
    return znam / double(text_length * (text_length - 1));
}


