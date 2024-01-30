#include "Bureaucrat.hpp"

int	main(void)
{
	cout << endl;
	cout << "\033[1m------------------ IncGrade METHOD ------------------\033[0m" << std::endl << endl;

	Bureaucrat	Robot("Bender", 75);

	cout << endl;
	cout << "The method \e[1;34mIncGrade()\e[0m is used on \e[1;37mBender\e[0m. His actual grade : \e[1;35m" << Robot.getGrade() << "\e[0m." << endl;
	Robot.IncGrade();
	cout << "Now, the new grade of \e[1;37mBender\e[0m is : \e[1;35m" << Robot.getGrade() << "\e[0m. \e[1;32mWow great job for your increase !!!\e[0m" << endl;

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << endl;


	cout << "\033[1m----------------- DecGrade METHOD -----------------\033[0m" << std::endl << endl;

	cout << "The method \e[1;34mDecGrade()\e[0m is used on \e[1;37mBender\e[0m. His actual grade : \e[1;35m" << Robot.getGrade() << "\e[0m." << endl;
	Robot.DecGrade();
	cout << "Now, the new grade of \e[1;37mBender\e[0m is : \e[1;35m" << Robot.getGrade() << "\e[0m. \e[1;31mI'm so sorry for your decrease...\e[0m" << endl;

	cout << endl;
	cout << "\033[1m----------------------------------------------------\033[0m" << std::endl << std::endl << endl;

/*-------------------------------------------------------*/

	cout << "\033[1m----------- OVER-IncGrade EXCEPTION CATCH -----------\033[0m" << std::endl << endl;

	Bureaucrat	High("Leela", 1);

	cout << endl;
	cout << "The method \e[1;34mIncGrade()\e[0m is used on \e[1;37mLeela\e[0m. His actual grade : \e[1;35m" << High.getGrade() << "\e[0m." << endl;
	cout << "[Keywords \e[4;34mtry\e[0m and \e[4;34mcatch\e[0m is used here]" << std::endl << endl;

/*#######################################################*/
	try
	{
		High.IncGrade();
		cout << "Now, the new grade of \e[1;37mLeela\e[0m is : \e[1;35m" << High.getGrade() << "\e[0m. \e[1;32mWow great job for your increase !!!\e[0m" << endl;
	}

	catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}
/*#######################################################*/



	cout << "\033[1m---------- OVER-DecGrade EXCEPTION CATCH ----------\033[0m" << std::endl << endl;

	Bureaucrat	Low("Fry", 150);

	cout << endl;
	cout << "The method \e[1;34mDecGrade()\e[0m is used on \e[1;37mFry\e[0m. His actual grade : \e[1;35m" << Low.getGrade() << "\e[0m." << endl;
	cout << "[Keywords \e[4;34mtry\e[0m and \e[4;34mcatch\e[0m is used here]" << std::endl << endl;

/*#######################################################*/
	try
	{
		Low.DecGrade();
		cout << "Now, the new grade of \e[1;37mFry\e[0m is : \e[1;35m" << Low.getGrade() << "\e[0m. \e[1;31mI'm so sorry for your decrease...\e[0m" << endl;
	}

	catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}
/*#######################################################*/



	cout << "\033[1m--------- OVER-UP/DecGrade EXCEPTION CATCH --------\033[0m" << std::endl << endl;

	Bureaucrat	High_2("Amy", 1);
	Bureaucrat	Low_2("Zoidberg", 150);

	cout << endl;
	cout << "[ FIRST ]	The method \e[1;34mIncGrade()\e[0m is used on \e[1;37mAmy\e[0m. His actual grade : \e[1;35m" << High_2.getGrade() << "\e[0m." << endl;
	cout << "[ SECOND ]	The method \e[1;34mDecGrade()\e[0m is used on \e[1;37mZoidberg\e[0m. His actual grade : \e[1;35m" << Low_2.getGrade() << "\e[0m." << endl;
	cout << "[Keywords \e[4;34mtry\e[0m and \e[4;34mcatch\e[0m is used here]" << std::endl << endl;

/*#######################################################*/
	try
	{
		High_2.IncGrade();
		Low_2.DecGrade();
		cout << "Now, the new grade of \e[1;37mAmy\e[0m is : \e[1;35m" << High_2.getGrade() << "\e[0m. \e[1;32mWow great job for your increase !!!\e[0m" << endl;
		cout << "Now, the new grade of \e[1;37mZoidberg\e[0m is : \e[1;35m" << Low_2.getGrade() << "\e[0m. \e[1;31mI'm so sorry for your decrease...\e[0m" << endl;
	}

	catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}
/*#######################################################*/



	cout << "\033[1m--------------- EXCEPTION CONSTRUCTOR --------------\033[0m" << std::endl << endl;

	cout << "[Keywords \e[4;34mtry\e[0m and \e[4;34mcatch\e[0m is used here]" << std::endl << endl;

/*#######################################################*/
	try
	{
		Bureaucrat	Too_High("Pr.Farnsworth", 0);
		Bureaucrat	Too_Low("Hermes", 151);

		cout << endl;
		cout << "[ FIRST ]	The method \e[1;34mIncGrade()\e[0m is used on \e[1;37mPr.Farnsworth\e[0m. His actual grade : \e[1;35m" << Too_High.getGrade() << "\e[0m." << endl;
		cout << "[ SECOND ]	The method \e[1;34mDecGrade()\e[0m is used on \e[1;37mHermes\e[0m. His actual grade : \e[1;35m" << Too_Low.getGrade() << "\e[0m." << endl;

		Too_High.IncGrade();
		Too_Low.DecGrade();
		cout << "Now, the new grade of \e[1;37mPr.Farnsworth\e[0m is : \e[1;35m" << Too_High.getGrade() << "\e[0m. \e[1;32mWow great job for your increase !!!\e[0m" << endl;
		cout << "Now, the new grade of \e[1;37mHermes\e[0m is : \e[1;35m" << Too_Low.getGrade() << "\e[0m. \e[1;31mI'm so sorry for your decrease...\e[0m" << endl;

	}

	catch (const std::exception &e)
	{
		cout << e.what() << endl;
	}
/*#######################################################*/


	cout << "\033[1m---------------- DEFAULT DESTRUCTOR ----------------\033[0m" << std::endl << endl;
	//system("leaks Bureaucrat");
	return (0);
}