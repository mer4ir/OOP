#include "vector_utils.h"
#include <iostream>
#include <random>

using namespace std;

void showMenu(const vector<int>& vec) {
  printVector(vec);
  cout << "\nМеню:\n";
  cout << "1. Изменить количество элементов в векторе\n";
  cout << "2. Ввести все элементы вручную\n";
  cout << "3. Заполнить вектор случайными числами\n";
  cout << "4. Применить алгоритм\n";
  cout << "5. Выход\n";
}

int main() {
  cout << std::format(
    "\n+- Ответ -----------------------------------+\n"
    "│  Группа: {:<13}                    │\n"
    "│   Автор: {:<13}                    │\n"
    "│ Вариант: {:<13}                    │\n"
    "+-------------------------------------------+\n",
    std::string("6111"), std::string("Борисик Мирон"), std::string("2"));

  vector<int> vec;
  int choice;
    
  do {
    showMenu(vec);
    cout << "\nВыберите пункт: ";
    cin >> choice;
        
    switch (choice) {
      case 1: {
        int newSize;
        cout << "\nВведите новый размер вектора: ";
        cin >> newSize;
        vec.resize(newSize, 0);
        break;
        }
        
      case 2: {
        if (vec.empty()) {
          cout << "\nОшибка: вектор пуст. Сначала измените количество элементов.\n";
        } else {
          fillVectorManual(vec);
        }
        break;
        }

        case 3: {
          if (vec.empty()) {
            cout << "\nОшибка: вектор пуст. Сначала измените количество элементов.\n";
          } else {
            int minVal, maxVal;
            unsigned seed;
            cout << "\nВведите min и max: ";
            cin >> minVal >> maxVal;
            cout << "Введите seed (0 для случайного): ";
            cin >> seed;
            if (seed == 0) seed = random_device{}();
            fillVectorRandom(vec, minVal, maxVal, seed);
          }
          break;
      }
          
        case 4:
          applyAlgorithm(vec);
          break;
        
        case 5:
          cout << "\nВыход!\n";
          break;
        default:
          cout << "\nОшибка: неверный пункт меню.\n";
    }
  } while (choice != 5);
    
  return 0;
}