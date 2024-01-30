#include <iostream>

#include <vector>
#include <list>
#include <deque>

#include "easyfind.hpp"
using std::vector;
using std::list;
using std::deque;
int	main(void)
{
	vector<int>	vect;
	list<int>		list;
	deque<int>		deq;
	int					i = 0;

	cout << endl;
	cout <<  GRAS << "------------------ INITIALISATION ------------------" << RESET << endl << endl;

	for (int i = 0; i < 10; i++) {

		vect.push_back( i );
		list.push_back( i );
		deq.push_back( i );
	}

	for (std::list<int>::const_iterator list_ite = list.begin(); list_ite != list.end() ; list_ite++, i++) {

		cout << PINK << "VECTOR" << RESET << "	n°[ "<< PINK <<"" << i << "" << RESET << " ] : " << PINK << vect[ i ] <<   RESET << endl;
		cout << PINK << "LIST" << RESET << "	n°[ "<< PINK <<"" << i << "" << RESET << " ] : " << PINK << *list_ite <<   RESET << endl;
		cout << PINK << "DEQUE" << RESET << "	n°[ "<< PINK <<"" << i << "" << RESET << " ] : " << PINK << deq[ i ] <<   RESET << endl;
		cout << endl;
	}



	cout << endl;
	cout << GRAS << "---------------------- VECTOR ----------------------"<< RESET << endl << endl;

	cout << GREEN << "[] SUCCESS TEST ]" << RESET << " with value : "<< PINK <<"2" << RESET << endl;
	try
	{
		::easyfind< vector<int> >(vect, 2);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;
	cout << RED << "[ FAILED TEST ]" << RESET << " with value : "<< PINK <<"15" << RESET << "" << RESET << endl;
	try
	{
		::easyfind< std::vector<int> >(vect, 15);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;


	cout << GRAS <<"----------------------- LIST -----------------------"<< RESET << endl << endl;

	cout << GREEN << "[ SUCCESS TEST ]" << RESET << " with value : "<< PINK <<"7" << RESET << endl;
	try
	{
		::easyfind< std::deque<int> >(deq, 7);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;
	cout << RED << "[ FAILED TEST ]" << RESET << " with value : "<< PINK <<"-4" << RESET << "" << RESET << endl;
	try
	{
		::easyfind< std::list<int> >(list, -4);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;


	cout << GRAS <<"----------------------- DEQUE ----------------------"<< RESET << endl << endl;

	cout << GREEN << "[ SUCCESS TEST ]" << RESET << " with value : "<< PINK <<"0" << RESET << endl;
	try
	{
		::easyfind< std::list<int> >(list, 0);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;
	cout << RED << "[ FAILED TEST ]" << RESET << " with value : "<< PINK <<"12" << RESET << "" << RESET << endl;
	try
	{
		::easyfind< std::list<int> >(list, 12);
		cout << ORANGE << "Occurence found" << RESET << endl;
	}
	catch (std::exception const &e)
	{
		cout << e.what() << endl;
	}

	cout << endl;

	return (0);
}