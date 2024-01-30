#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;


template<typename T>

class Array {
    public:
        Array(): size_array(0) {
                this->array = NULL;
        };
        Array(unsigned int n):   array(new T[n]) ,size_array(n){
            for (unsigned int i = 0; i < n; i++)
                this->array[i] = T();
            };
        Array(Array const &copy):  array(new T[copy.size_array]), size_array(copy.size_array){
            for (unsigned int i = 0; i < size_array; i++)
                this->array[i] = copy.array[i];
        };
        Array &operator=(Array const &res)  {
            if (this != &res) {
                T* newData = new T[res.size_array];
                for (unsigned int i = 0; i < res.size_array; ++i) {
                    newData[i] = res.array[i];
                }
                delete[] array;
                size_array = res.size_array;
                array = newData;
            }
            return *this;
        }
        T& operator[](unsigned int i)  {
            if (i >= this->size_array)
                throw std::out_of_range("index out of range");
            return array[i];
        }
        size_t size() {
            return this->size_array;
        }
        ~Array() {
            delete[] this->array;
        }
    private:
        T *array;
        unsigned int size_array;

};
