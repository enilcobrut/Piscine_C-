#include "Array.hpp"


int	main(void)
{
	cout << endl;
	cout << "\033[1m------------------ DEFAULT ARRAY -------------------\033[0m" << endl << endl;

	Array<int>	tab_default;

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;

	cout << "\033[1m-------------------- INIT ARRAY --------------------\033[0m" << endl << endl;

	Array<int>	tab_init( 10 );

	for (size_t i = 0; i < tab_init.size(); i++) {

		tab_init[ i ] = i;
		cout << "tab_init [ \e[1;37m" << i << "\e[0m ] : \e[1;35m" << tab_init[ i ] << "\e[0m" << endl;
	}

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;

	cout << "\033[1m-------------------- COPY ARRAY --------------------\033[0m" << endl << endl;

	Array<int>	tab_copy(tab_init);

	for (size_t i = 0; i < tab_copy.size(); i++) {

		tab_copy[ i ] = i;
		cout << "tab_copy [ \e[1;37m" << i << "\e[0m ] : \e[1;35m" << tab_copy[ i ] << "\e[0m" << endl;
	}

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;


	cout << "\033[1m-------------------- VALID INDEX -------------------\033[0m" << endl << endl;

	try
	{
		cout << "The element of \e[1;37mtab_init\e[0m at the \e[1;35mINDEX 5\e[0m : " << tab_init[ 5 ] << endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << endl;
	}

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;


	cout << "\033[1m------------------ INVALID INDEX + -----------------\033[0m" << endl << endl;

	try
	{
		cout << "The element of \e[1;37mtab_init\e[0m at the \e[1;35mINDEX 12\e[0m : " << tab_init[ 12 ] << endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << endl;
	}

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;


	cout << "\033[1m------------------ INVALID INDEX - -----------------\033[0m" << endl << endl;

	try
	{
		cout << "The element of \e[1;37mtab_init\e[0m at the \e[1;35mINDEX -12\e[0m : " << tab_init[ -12 ] << endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << endl;
	}

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;


	cout << "\033[1m----------------------- LEAKS ----------------------\033[0m" << endl << endl;

	//system("leaks array");

	cout << "\033[1m----------------------------------------------------\033[0m" << endl << endl << endl;


	cout << "\033[1m----------------- DEFAULT DESTRUCTOR ---------------\033[0m" << endl << endl;

	return (0);
}