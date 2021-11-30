#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>


void breaker(const std::string& coded_file_path, const std::string& reference_file_path);
double affinity_index(std::unordered_map<unsigned char, int>& frequencies,  int& text_length);

