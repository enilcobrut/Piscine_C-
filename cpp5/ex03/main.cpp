#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << std::endl;
	Intern		Random;
	std::cout << std::endl;
	Bureaucrat	Employee("Bender", 1);
	std::cout << std::endl;

	std::cout << "\033[1m--------------------- SHRUBBERY --------------------\033[0m" << std::endl << std::endl;

	try
	{
		Form	*New_Shrubb = Random.makeForm("shrubbery creation", "garden");
		std::cout << std::endl;

		Employee.signForm( *New_Shrubb );
		Employee.executeForm( *New_Shrubb );
		std::cout << std::endl;

		delete New_Shrubb;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << std::endl;


	std::cout << "\033[1m--------------------- ROBOTOMY ---------------------\033[0m" << std::endl << std::endl;

	try
	{
		Form	*New_Rob = Random.makeForm("robotomy request", "R.O.B");
		std::cout << std::endl;

		Employee.signForm( *New_Rob );
		Employee.executeForm( *New_Rob );
		std::cout << std::endl;

		delete New_Rob;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << std::endl;


	std::cout << "\033[1m------------------- PRESIDENTIAL -------------------\033[0m" << std::endl << std::endl;

	try
	{
		Form	*New_Pres = Random.makeForm("presidential pardon", "guilty");
		std::cout << std::endl;

		Employee.signForm( *New_Pres );
		Employee.executeForm( *New_Pres );
		std::cout << std::endl;

		delete New_Pres;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << std::endl;


	std::cout << "\033[1m---------------------- UNKNOWN ---------------------\033[0m" << std::endl << std::endl;

	try
	{
		Form	*New_Unknown = Random.makeForm("unknown", "random");
		std::cout << std::endl;

		Employee.signForm( *New_Unknown );
		Employee.executeForm( *New_Unknown );
		std::cout << std::endl;

		delete New_Unknown;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << std::endl;


	std::cout << "\033[1m---------------- DEFAULT DESTRUCTOR ----------------\033[0m" << std::endl << std::endl;

	return (0);
}