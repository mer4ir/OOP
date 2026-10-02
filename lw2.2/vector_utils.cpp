#include "vector_utils.h"
#include <iostream>
#include <random>

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "\nТекущий вектор: ";
    for (int num : vec) cout << num << " ";
    cout << "\n";
}

void fillVectorManual(vector<int>& vec) {
    cout << "\nВведите " << vec.size() << " элементов: ";
    for (int& num : vec) cin >> num;
}

void fillVectorRandom(vector<int>& vec, int minVal, int maxVal, unsigned seed) {
    mt19937 gen(seed);
    uniform_int_distribution<int> dist(minVal, maxVal);
    for (int& num : vec) num = dist(gen);
}

void applyAlgorithm(vector<int>& vec) {
    if (vec.empty()) {
        cout << "\nВектор пуст. Алгоритм не применим.\n";
        return;
    }
    int product = 1;
    for (int num : vec) product *= num;
    cout << "\nПроизведение элементов: " << product << "\n";
}