#pragma once

#include <iostream>

using std::endl;
using std::cout;

template<typename T>
void iter(T* array, size_t len, void (*f)(const T&)) {
    for (size_t i = 0; i < len; ++i) {
        f(array[i]);
    }
}

