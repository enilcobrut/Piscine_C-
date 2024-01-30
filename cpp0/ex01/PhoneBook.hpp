#include "Contact.hpp"
#include <iostream>

using std::ostream;

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void add();
        void search();
        void loop();
        int getIndex() const;
        int getSize() const;
        const Contact* getRepertoire() const;
    private:
        Contact repertoire[8];
        int index;
        int size;
};
