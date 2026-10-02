#include "functions.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Загружает слова из файла
vector<string> load_words_from_file(const string& file_path) {
  ifstream file(file_path);
  vector<string> raw_words;
  string word;

  // Добавляем в вектор слов
  while (file >> word) {
    raw_words.push_back(word);
  }

  return raw_words;
}

// Нормализует слово
string normalize_word(const string& word) {
  string result;

  // Находим позицию первого значимого символа
  size_t start = 0;
  while (start < word.size() && !isalpha(word[start]) && word[start] != '-') {
    ++start;
  }

  // Находим позицию последнего значимого символа
  size_t end = word.size();
  while (end > start && !isalpha(word[end - 1]) && word[end - 1] != '-') {
    --end;
  }

  // Собираем "чистое" слово
  for (size_t i = start; i < end; ++i) {
    char ch = static_cast<char>(tolower(word[i]));
    if (isalpha(ch) || ch == '-') {
      result += ch;
    }
  }

  // Убираем двойные дефисы
  if (result.find("--") != string::npos) {
    return "";
  }

  return result;
}

// Применяет нормализацию ко всем словам и удаляет пустые строки
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

// Находит n наиболее частых слов, исключая незначимые
vector<pair<int, set<string>>> find_top_frequent_words(const vector<string>& words, const unordered_set<string>& insignificant_words, size_t n) {
  unordered_map<string, int> freq;

  // Подсчёт частот для всех значимых слов
  for (const auto& word : words) {
    if (insignificant_words.find(word) == insignificant_words.end()) {
      ++freq[word];
    }
  }

  // Сохраняем уникальные уровни частоты по убыванию
  set<int, greater<int>> freq_levels;
  for (const auto& [_, count] : freq) {
    freq_levels.insert(count);
  }

  // Выбираем первые n уровней и добавляем к ним слова
  vector<pair<int, set<string>>> result;
  size_t count = 0;

  for (int level : freq_levels) {
    if (count >= n) break;

    set<string> group;
    for (const auto& [word, word_freq] : freq) {
      if (word_freq == level) {
        group.insert(word);
      }
    }

    result.emplace_back(level, std::move(group));
    ++count;
  }

  return result;
}