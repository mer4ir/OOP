#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

// Загружает слова из файла (не нормализованные)
std::vector<std::string> load_words_from_file(const std::string& file_path);

// Нормализует отдельное слово: приводит к нижнему регистру и очистка от лишних символов
std::string normalize_word(const std::string& word);

// Нормализует вектор слов, возвращает только корректные
std::vector<std::string> normalize_words(const std::vector<std::string>& words);

// Считает количество уникальных слов, исключая незначимые
std::size_t count_unique_words(const std::vector<std::string>& words, const std::unordered_set<std::string>& insignificant_words);

// Находит самые часто встречающиеся слова (кроме незначимых)
std::pair<int, std::set<std::string>> find_most_frequent_words(const std::vector<std::string>& words, const std::unordered_set<std::string>& insignificant_words);

#endif