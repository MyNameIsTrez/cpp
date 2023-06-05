#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

void example()
{
	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

void a_materia()
{
	std::cout << std::endl << "-- A_MATERIA" << std::endl;

	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	AMateria *a_materia;
	a_materia = src->createMateria("ice");

	AMateria *a_materia2;
	a_materia2 = a_materia->clone();
	assert(a_materia2->getType() == "ice");

	AMateria *a_materia3;
	a_materia3 = src->createMateria("cure");
	assert(a_materia2->getType() == "ice");
	*a_materia2 = *a_materia3;
	*a_materia2 = *a_materia2;
	assert(a_materia2->getType() == "ice");

	ICharacter *me = new Character("me");
	a_materia->use(*me);

	delete src;
	delete a_materia;
	delete a_materia2;
	delete a_materia3;
	delete me;
}

void ice()
{
	std::cout << std::endl << "-- ICE" << std::endl;

	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

	Ice *ice;
	ice = static_cast<Ice *>(src->createMateria("ice"));

	Ice *ice2;
	ice2 = static_cast<Ice *>(src->createMateria("ice"));
	*ice2 = *ice;
	*ice2 = *ice2;
	assert(ice2->getType() == "ice");

	delete src;
	delete ice;
	delete ice2;
}

void cure()
{
	std::cout << std::endl << "-- CURE" << std::endl;

	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Cure());

	Cure *cure;
	cure = static_cast<Cure *>(src->createMateria("cure"));

	Cure *cure2;
	cure2 = static_cast<Cure *>(src->createMateria("cure"));
	*cure2 = *cure;
	*cure2 = *cure2;
	assert(cure2->getType() == "cure");

	delete src;
	delete cure;
	delete cure2;
}

void materia_source()
{
	std::cout << std::endl << "-- MATERIA_SOURCE" << std::endl;

	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	AMateria *not_learnt = new Ice();
	src->learnMateria(not_learnt);
	src->learnMateria(NULL);

	AMateria *nonexistent;
	nonexistent = src->createMateria("nonexistent");
	assert(nonexistent == NULL);

	MateriaSource src2(*src);

	AMateria *a_materia;
	a_materia = src2.createMateria("ice");
	assert(a_materia->getType() == "ice");

	MateriaSource *src3 = new MateriaSource();
	*src3 = *src;
	*src3 = *src;
	*src3 = *src3;

	delete src;
	delete not_learnt;
	delete a_materia;
	delete src3;
}

void character()
{
	MateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

	Character *me = new Character("me");

	me->equip(NULL);

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->equip(tmp);
	AMateria *tmp2;
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);

	me->use(3, *me);

	me->use(-1, *me);
	me->use(4, *me);

	me->unequip(-1);
	me->unequip(0);
	me->unequip(4);

	Character me2(*me);

	Character *me2_ptr = &me2;
	*me2_ptr = *me2_ptr;

	Character no_name;
	assert(no_name.getName() == "No name");

	delete me;
	delete src;
	delete tmp;
}

int main()
{
	example();

	a_materia();
	ice();
	cure();
	materia_source();
	character();

	std::cout << std::endl;
	system("leaks -q interface");

	return EXIT_SUCCESS;
}
