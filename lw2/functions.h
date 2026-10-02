#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <random>

void fillVectorManual(std::vector<int>& vec, int n);
void fillVectorRandom(std::vector<int>& vec, int n, int min = 1, int max = 100, unsigned seed = std::random_device{}());
void printVector(const std::vector<int>& vec);
int calculateProduct(const std::vector<int>& vec);

#endif