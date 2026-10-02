#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <vector>
#include <random>

void printVector(const std::vector<int>& vec);
void fillVectorManual(std::vector<int>& vec);
void fillVectorRandom(std::vector<int>& vec, int minVal, int maxVal, unsigned seed = std::random_device{}());
void applyAlgorithm(std::vector<int>& vec);

#endif