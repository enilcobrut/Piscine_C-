#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>



Base * generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        default :
            return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL)
        cout << "A" << endl;
    else if (dynamic_cast<B*>(p) != NULL)
        cout << "B" << endl;
    else if (dynamic_cast<C*>(p) != NULL)
        cout << "C" << endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        cout << "A" << endl;
        return;
    }
    catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        cout << "B" << endl;
        return;
    }
    catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        cout << "C" << endl;
        return;
    }
    catch (...) {}
}

int	main(void)
{
	Base	*a = generate();

	identify(a);
	identify(*a);

	delete a;

	return (0);
}