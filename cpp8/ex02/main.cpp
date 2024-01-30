#include <list>
#include "MutantStack.hpp"
using std::list;
int main(void)
{
	cout << endl;
	cout <<  GRAS << "------------------ STACK TEST ------------------" << RESET << endl << endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	cout << ORANGE << "top : " << mstack.top() << endl;

	mstack.pop();
	cout << ORANGE << "top : " << mstack.top() << endl;
	cout << PINK << "size : " << mstack.size() << endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();

	for (; it != mstack.end(); it++)
	cout 	<< BLUE << "value : " << RESET<< *it << endl;

	cout << endl;
	cout <<  GRAS << "------------------ LIST TEST ------------------" << RESET << endl << endl;

	list<int> list;

	list.push_back(5);
	list.push_back(17);

	cout << ORANGE << "top : " << list.back() << endl;

	list.pop_back();
	cout  << ORANGE <<"top : " << list.back() << endl;
	cout  << PINK<<"size : " << list.size() << endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator l_it = list.begin();

	for (; l_it != list.end(); l_it++)
		cout << BLUE << "value : " << RESET << *l_it << endl;
	cout << endl;

return 0;
}