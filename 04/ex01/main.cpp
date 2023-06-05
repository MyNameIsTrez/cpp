#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>

void example()
{
	std::cout << std::endl << "-- EXAMPLE" << std::endl;

	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	delete dog;
	delete cat;
}

void array()
{
	std::cout << std::endl << "-- ARRAY" << std::endl;

	Animal *animals[4];

	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}

	for (size_t i = 0; i < 4; i++)
	{
		delete animals[i];
	}
}

void dog_ideas()
{
	std::cout << std::endl << "-- DOG_IDEAS" << std::endl;

	std::cout << std::endl << "DEFAULT CONSTRUCTOR:" << std::endl;

	Dog dog;
	dog.makeSound();
	assert(dog.getType() == "Dog");

	dog.add_idea("fetch stick");
	dog.add_idea("tennis ball");

	assert(dog.get_idea(0) == "fetch stick");
	assert(dog.get_idea(1) == "tennis ball");

	std::cout << std::endl << "COPY CONSTRUCTOR:" << std::endl;
	Dog dog2(dog);
	assert(dog2.get_idea(0) == "fetch stick");
	assert(dog2.get_idea(1) == "tennis ball");

	std::cout << std::endl << "COPY ASSIGNMENT OPERATOR:" << std::endl;
	Dog dog3;
	dog3 = dog;
	assert(dog3.get_idea(0) == "fetch stick");
	assert(dog3.get_idea(1) == "tennis ball");

	std::cout << std::endl << "DESTRUCTORS:" << std::endl;
}

void cat_ideas()
{
	std::cout << std::endl << "-- CAT_IDEAS" << std::endl;

	std::cout << std::endl << "DEFAULT CONSTRUCTOR:" << std::endl;

	Cat cat;
	cat.makeSound();
	assert(cat.getType() == "Cat");

	cat.add_idea("play with yarn");
	cat.add_idea("catch mouse");

	assert(cat.get_idea(0) == "play with yarn");
	assert(cat.get_idea(1) == "catch mouse");

	std::cout << std::endl << "COPY CONSTRUCTOR:" << std::endl;
	Cat cat2(cat);
	assert(cat2.get_idea(0) == "play with yarn");
	assert(cat2.get_idea(1) == "catch mouse");

	std::cout << std::endl << "COPY ASSIGNMENT OPERATOR:" << std::endl;
	Cat cat3;
	cat3 = cat;
	assert(cat3.get_idea(0) == "play with yarn");
	assert(cat3.get_idea(1) == "catch mouse");

	std::cout << std::endl << "DESTRUCTORS:" << std::endl;
}

int main()
{
	example();
	array();
	dog_ideas();
	cat_ideas();

	std::cout << std::endl;
	system("leaks -q brain");

	return EXIT_SUCCESS;
}
