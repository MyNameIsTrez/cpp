#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

void	correct()
{
	std::cout << "-- CORRECT" << std::endl;

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl;
}

void	wrong()
{
	std::cout << "-- WRONG" << std::endl;

	const WrongAnimal* animal = new WrongAnimal();
	const WrongAnimal* cat = new WrongCat();

	std::cout << animal->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	animal->makeSound();
	cat->makeSound();

	delete animal;
	delete cat;

	std::cout << std::endl;
}

void	copy_constructors()
{
	std::cout << "-- COPY CONSTRUCTORS" << std::endl;

	std::cout << "1" << std::endl;
	const Animal* animal1 = new Animal();
	std::cout << "2" << std::endl;
	const Animal* animal2 = new Animal(*animal1);
	std::cout << std::endl;

	std::cout << "3" << std::endl;
	const Dog* dog1 = new Dog();
	std::cout << "4" << std::endl;
	const Dog* dog2 = new Dog(*dog1);
	std::cout << std::endl;

	std::cout << "5" << std::endl;
	const Cat* cat1 = new Cat();
	std::cout << "6" << std::endl;
	const Cat* cat2 = new Cat(*cat1);
	std::cout << std::endl;

	std::cout << "1" << std::endl;
	delete animal1;
	std::cout << "2" << std::endl;
	delete animal2;
	std::cout << "3" << std::endl;
	delete dog1;
	std::cout << "4" << std::endl;
	delete dog2;
	std::cout << "5" << std::endl;
	delete cat1;
	std::cout << "6" << std::endl;
	delete cat2;

	std::cout << std::endl;
}

void	copy_assignment_operators()
{
	std::cout << "-- COPY ASSIGNMENT OPERATORS" << std::endl;

	const Animal* animal1 = new Animal();
	Animal animal2;
	animal2 = *animal1;
	std::cout << std::endl;

	const Dog* dog1 = new Dog();
	Dog dog2;
	dog2 = *dog1;
	std::cout << std::endl;

	Cat* cat1 = new Cat();
	Cat cat2;
	cat2 = *cat1;
	std::cout << std::endl;

	delete animal1;
	delete dog1;
	delete cat1;

	std::cout << std::endl;
}

int	main()
{
	correct();
	wrong();

	copy_constructors();
	copy_assignment_operators();

	system("leaks -q animal");

	return EXIT_SUCCESS;
}
