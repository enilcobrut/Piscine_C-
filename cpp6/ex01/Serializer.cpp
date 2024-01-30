#include "Serializer.hpp"


Serializer::Serializer(Serializer const &copy) {
    *this = copy;
}
Serializer &Serializer::operator=(Serializer const &res) {
    (void)res;
    cout << "nothing to assign" << endl;
    return *this;
}
Serializer::~Serializer() {

}
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}


 Serializer::Serializer() {

 }