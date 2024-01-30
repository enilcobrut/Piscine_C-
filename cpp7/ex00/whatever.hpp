#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>

void swap(T &a, T &b) {
    T tp = a;
    a = b;
    b = tp;
}

template<typename T>

T min(T a, T b) {
   return (a < b) ? a : b;
}

template<typename T>

T max(T a, T b) {
    return (a > b) ? a : b;
}