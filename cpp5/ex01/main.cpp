#include "Bureaucrat.hpp"

int	main(void)
{

	cout << endl;
	cout << "\033[1m-------------------- SIGN METHOD -------------------\033[0m" << std::endl << endl;

	Bureaucrat	Robot("Bender", 75);
	cout << endl;
	Form		Paper_0("Contrat", 149, 1);
	cout << endl;

	Robot.signForm(Paper_0);
	cout << endl;
	cout << "form : " << Paper_0 << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << endl;


	cout << "\033[1m----------------- OVER-SIGN METHOD -----------------\033[0m" << std::endl << endl;

	Bureaucrat	Over_Sign("Amy", 75);

	try
	{
		Over_Sign.signForm(Paper_0);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout << endl;

	cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << endl;


	cout << "\033[1m--------------- SIGN METHOD | TOO LOW --------------\033[0m" << std::endl << endl;

	Bureaucrat Too_Low("Leela", 150);
	cout << endl;
	Form		Paper_1("Formular", 149, 1);
	cout << endl;

/*#######################################################*/
	try
	{
		Too_Low.signForm(Paper_1);
		cout << endl;
	}
	catch (const std::exception &e)
	{
		cout << e.what() << std::endl << endl;
	}
/*#######################################################*/


	cout << "\033[1m------------------ OVER-GRADE FORM -----------------\033[0m" << std::endl << endl;

/*#######################################################*/
	try
	{
		Form	Too_High_Grade("Tableur", 151, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << endl;
	}
/*#######################################################*/

/*#######################################################*/
	try
	{
		Form	Too_Low_Grade("Certificate", 0, 1);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << std::endl << endl;
	}
/*#######################################################*/

	cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << endl;


	cout << "\033[1m---------------- DEFAULT DESTRUCTOR ----------------\033[0m" << std::endl << endl;
	
	return (0);
}