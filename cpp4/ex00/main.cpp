#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\033[1m------------------- ANIMAL CLASS -------------------\033[0m" << std::endl << std::endl;
	const Animal*		Default = new Animal();
	const Animal*		Huski = new Dog();
	const Animal*		Persian = new Cat();

	std::cout << std::endl << std::endl;
	std::cout << "the \033[1m'type'\033[0m of \033[1;32mDefault is [ " << Default->getType() << " ]\033[0m" << std::endl;
	std::cout << "the \033[1m'type'\033[0m of \033[1;35mHuski is [ " << Huski->getType() << " ]\033[0m" << std::endl;
	std::cout << "the \033[1m'type'\033[0m of \033[1;36mPersian is [ " << Persian->getType() << " ]\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "The sound of \033[1;32mDefault\033[0m : ", Default->makeSound(), std::cout << std::endl;
	std::cout << "The sound of \033[1;35mHuski\033[0m : ", Huski->makeSound(), std::cout << std::endl;
	std::cout << "The sound of \033[1;36mPersian\033[0m : ", Persian->makeSound(), std::cout << std::endl;
	std::cout << std::endl;

	delete Default;
	delete Huski;
	delete Persian;

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl;
	std::cout << std::endl << std::endl;


	std::cout << "\033[1m---------------- WRONGANIMAL CLASS -----------------\033[0m" << std::endl << std::endl;
	const WrongAnimal*	WrongDefault = new WrongAnimal();
	const WrongAnimal*	Wrong_Floppa = new WrongCat();

	std::cout << std::endl << std::endl;
	std::cout << "the 'type' of \033[1;32mWrongDefault is [ " << WrongDefault->getType() << " ]\033[0m" << std::endl;
	std::cout << "the 'type' of \033[1;33mWrong_Floppa is [ " << Wrong_Floppa->getType() << " ]\033[0m" << std::endl;
	std::cout << std::endl;

	std::cout << "The sound of \033[1;32mWrongDefault\033[0m : ", WrongDefault->makeSound(), std::cout << std::endl;
	std::cout << "The sound of \033[1;33mWrong_Floppa\033[0m : ", Wrong_Floppa->makeSound(), std::cout << std::endl;
	std::cout << std::endl;

	delete WrongDefault;
	delete Wrong_Floppa;

	std::cout << std::endl;
	std::cout << "\033[1m----------------------------------------------------\033[0m" << std::endl;
	std::cout << std::endl;
    //system("leaks Animal");
	return (0);
}