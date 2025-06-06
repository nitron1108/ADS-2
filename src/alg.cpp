// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  if (n == 0) return 1.0;
  double res = value;
  for (uint16_t i = 1; i < n; i++) {
    res *= value;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 0) return 1;
  uint64_t res = 1;
  for (uint16_t i = 2; i <= n; i++) {
    res *= i;
  }
  return res;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
  double res = 1.0; 
  for (uint16_t i = 1; i <= count; i++) { 
    res += calcItem(x, i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    res += pown(-1, i) * calcItem(x, 2 * i + 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0.0;
  for (uint16_t i = 0; i < count; i++) {
    res += pown(-1, i) * calcItem(x, 2 * i);
  }
  return res;
}
