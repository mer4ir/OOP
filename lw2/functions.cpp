#include "functions.h"
#include <random>
#include <iostream>

using namespace std;

void fillVectorManual(vector<int>& vec, int n) {
  cout << "\nВведите " << n << " чисел: ";
  vec.clear();
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
    int num = 0;
    cin >> num;
    vec.push_back(num);
  }
}

void fillVectorRandom(vector<int>& vec, int n, int min, int max, unsigned seed) {
  mt19937 gen(seed);
  uniform_int_distribution<int> dist(min, max);
  
  vec.clear();
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
      vec.push_back(dist(gen));
  }
}

void printVector(const vector<int>& vec) {
  cout << "\nЭлементы вектора: ";
  for (int num : vec) {
    cout << num << " ";
  }
  cout << '\n';
}

int calculateProduct(const vector<int>& vec) {
  int product = 1;
  for (int num : vec) {
    product *= num;
  }
  return product;
}
