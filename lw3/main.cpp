#include "functions.h"
#include <iostream>
#include <format>

using namespace std;

int main() {
  // Метаинформация
  cout << format(
    "\n+- ЛР №3 -----------------------------------+\n"
    "│  Группа: {:<13}                    │\n"
    "│   Автор: {:<13}                    │\n"
    "│ Вариант: {:<13}                    │\n"
    "+-------------------------------------------+\n\n\n",
    string("6111"), string("Борисик Мирон"), string("17")
  );

  // Имя анализируемого файла
  string file_path;
  cout << "Введите имя файла: ";
  cin >> file_path;

  cout << "Анализ текста из файла:\n\"" << file_path << "\"\n\n";

  // Загрузка и нормализация текста
  auto raw_words = load_words_from_file(file_path);
  auto words = normalize_words(raw_words);

  // Множество незначимых слов
  unordered_set<string> insignificant_words = {
    "a", "an", "the", "and", "or", "but", "of", "to", "in", "on", "at", 
    "for", "with", "by", "as", "from", "that", "this", "these", "those",
    "i", "you", "he", "she", "it", "we", "they", "my", "your", "his", 
    "her", "its", "our", "their", "me", "him", "us", "them", "is", "are",
    "was", "were", "be", "been", "have", "has", "had", "do", "does", "did",
    "will", "would", "shall", "should", "can", "could", "may", "might", "must"

  };

  cout << "Общее количество слов в тексте: " << raw_words.size() << ".\n\n";

  cout << "Незначимые слова:\n";
  for (const auto& word : insignificant_words) {
    cout << "\"" << word << "\" ";
  }
  cout << "\n\n";

  // Подсчёт уникальных слов, исключая незначимые
  size_t unique_word_count = count_unique_words(words, insignificant_words);
  cout << "Количество уникальных слов: " << unique_word_count << "\n\n";

  // Поиск самых частых слов
  auto [max_count, frequent_words] = find_most_frequent_words(words, insignificant_words);
  cout << "Количество вхождений самого популярного слова: " << max_count << "\n\n";
  cout << "Самые популярные слова:\n";
  for (const auto& word : frequent_words) {
    cout << "\"" << word << "\"\n";
  }

  return 0;
}