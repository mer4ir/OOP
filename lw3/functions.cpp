#include "functions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Читает слова из файла в вектор (без нормализации)
vector<string> load_words_from_file(const string& file_path) {
  ifstream file(file_path);
  vector<string> raw_words;
  string word;

  // Последовательно читаем слова, разделённые пробелами
  while (file >> word) {
    raw_words.push_back(word);
  }

  return raw_words;
}

// Нормализует слово: убирает знаки препинания, приводит к нижнему регистру
string normalize_word(const string& word) {
  string result;

  // Удаление нежелательных символов с начала
  size_t start = 0;
  while (start < word.size() && !isalpha(word[start]) && word[start] != '-') {
    ++start;
  }

  // Удаление нежелательных символов с конца
  size_t end = word.size();
  while (end > start && !isalpha(word[end - 1]) && word[end - 1] != '-') {
    --end;
  }

  // Приведение к нижнему регистру, фильтрация
  for (size_t i = start; i < end; ++i) {
    char ch = static_cast<char>(tolower(word[i]));
    if (isalpha(ch) || ch == '-') {
      result += ch;
    }
  }

  // Удаляем слова с двумя подряд дефисами
  if (result.find("--") != string::npos) {
    return "";
  }

  return result;
}

// Нормализует весь набор слов, удаляет пустые
vector<string> normalize_words(const vector<string>& words) {
  vector<string> normalized;
  for (const auto& word : words) {
    string norm = normalize_word(word);
    if (!norm.empty()) {
      normalized.push_back(norm);
    }
  }
  return normalized;
}

// Считает количество уникальных слов, исключая незначимые
size_t count_unique_words(const vector<string>& words, const unordered_set<string>& insignificant_words) {
  unordered_set<string> unique;

  for (const auto& word : words) {
    if (insignificant_words.find(word) == insignificant_words.end()) {
      unique.insert(word);
    }
  }

  return unique.size();
}

// Ищет самое популярное слово или слова, исключая незначимые
pair<int, set<string>> find_most_frequent_words(const vector<string>& words, const unordered_set<string>& insignificant_words) {
  unordered_map<string, int> freq;
  int max_count = 0;

  // Подсчёт количества вхождений
  for (const auto& word : words) {
    if (insignificant_words.find(word) == insignificant_words.end()) {
      ++freq[word];
      if (freq[word] > max_count) {
        max_count = freq[word];
      }
    }
  }

  // Сбор всех слов с максимальной частотой
  set<string> most_frequent;
  for (const auto& [word, count] : freq) {
    if (count == max_count) {
      most_frequent.insert(word);
    }
  }

  return { max_count, most_frequent };
}