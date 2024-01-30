#pragma once
#include <iostream>
#include "Data.h"

using std::cout;
using std::endl;

class Serializer {
    private : 
       Serializer(Serializer const &copy);
       Serializer &operator=(Serializer const &res);
       ~Serializer();
        Serializer();
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};