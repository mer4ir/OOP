#include "functions.h"
#include <iostream>
#include <unordered_set>

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

  // Ввод имени файла
  string file_path;
  cout << "Введите имя файла: ";
  cin >> file_path;

  cout << "Анализ текста из файла:\n\"" << file_path << "\"\n\n";

  // Загрузка и нормализация текста
  auto raw_words = load_words_from_file(file_path);
  auto words = normalize_words(raw_words);

  // Незначимые слова
  unordered_set<string> insignificant_words = {
    "a", "an", "the", "and", "or", "but", "of", "to", "in", "on", "at", 
    "for", "with", "by", "as", "from", "that", "this", "these", "those",
    "i", "you", "he", "she", "it", "we", "they", "my", "your", "his", 
    "her", "its", "our", "their", "me", "him", "us", "them", "is", "are",
    "was", "were", "be", "been", "have", "has", "had", "do", "does", "did",
    "will", "would", "shall", "should", "can", "could", "may", "might", "must"
  };

  // Вывод статистики
  cout << "Общее количество слов в тексте: " << raw_words.size() << ".\n\n";

  cout << "Незначимые слова:\n";
  for (const auto& word : insignificant_words) {
      cout << "\"" << word << "\" ";
  }
  cout << "\n\n";

  // Подсчёт уникальных значимых слов
  size_t unique_word_count = count_unique_words(words, insignificant_words);
  cout << "Количество уникальных слов: " << unique_word_count << "\n\n";

  // Пользователь вводит n
  int n;
  cout << "Сколько самых частых слов вывести? ";
  cin >> n;

  // Получаем и выводим результат
  auto top_words = find_top_frequent_words(words, insignificant_words, n);
  for (const auto& [count, words] : top_words) {
      cout << count << ": ";
      for (const auto& word : words) {
          cout << "\"" << word << "\" ";
      }
      cout << "\n";
  }
}