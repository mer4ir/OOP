#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

// Загружает слова из файла в вектор слов
std::vector<std::string> load_words_from_file(const std::string& file_path);

// Нормализует слово
std::string normalize_word(const std::string& word);

// Нормализует каждое слово из вектора слов
std::vector<std::string> normalize_words(const std::vector<std::string>& words);

// Считает количество уникальных слов, исключая незначимые
std::size_t count_unique_words(const std::vector<std::string>& words, const std::unordered_set<std::string>& insignificant_words);

// Возвращает n групп слов, которые встречаются чаще всего
std::vector<std::pair<int, std::set<std::string>>> find_top_frequent_words(const std::vector<std::string>& words, const std::unordered_set<std::string>& insignificant_words, std::size_t n);

#endif