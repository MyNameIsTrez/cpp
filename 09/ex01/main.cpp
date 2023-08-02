#include "RPN.hpp"

#include <iostream>

#ifdef TESTS
static void tests()
{
	{
		try { RPN::process(""); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expression is empty."); }
		try { RPN::process(" "); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected digit or operator."); }
		try { RPN::process("1 "); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected digit or operator."); }
		try { RPN::process("1."); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected space character."); }
		try { RPN::process("-1"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Stack underflow."); }
		try { RPN::process("10"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected space character."); }
		try { RPN::process("1 2"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Stack overflow."); }
		try { RPN::process("1 +"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Stack underflow."); }
		try { RPN::process("1 ."); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected digit or operator."); }
		try { RPN::process("(1 + 1)"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Expected digit or operator."); }
		try { RPN::process("1 0 /"); assert(false); } catch (std::exception &e) { assert(std::string(e.what()) == "Division by zero."); }
	}
	{
		assert(RPN::process("0") == 0);
		assert(RPN::process("9") == 9);
		assert(RPN::process("2 3 +") == 5);
		assert(RPN::process("2 3 -") == -1);
		assert(RPN::process("2 3 *") == 6);
		assert(RPN::process("2 3 /") == 0);
		assert(RPN::process("8 9 * 9 - 9 - 9 - 4 - 1 +") == 42);
		assert(RPN::process("7 7 * 7 -") == 42);
		assert(RPN::process("1 2 * 2 / 2 * 2 4 - +") == 0);
	}
}
#endif

int	main(int argc, char *argv[])
{
	try {
#ifdef TESTS
	(void)argv;

	if (argc > 1) {
		throw std::runtime_error("No argument expected, did you mean to run without TESTS=1?");
	}

	tests();

	std::cout << "✓ All tests passed!" << std::endl << std::endl;
#else
	if (argc < 2) {
		throw std::runtime_error("Expected an expression.");
	}
	if (argc > 2) {
		throw std::runtime_error("Expected only 1 argument.");
	}

	int result = RPN::process(argv[1]);
	std::cout << result << std::endl;
#endif
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
		system("leaks -q RPN");
		return (EXIT_FAILURE);
	}

	system("leaks -q RPN");

	return EXIT_SUCCESS;
}
