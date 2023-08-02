#include "BitcoinExchange.hpp"
#include "Date.hpp"

#include <fstream>
#include <iostream>

#ifdef TESTS
static void date_tests()
{
	{
		{ Date d("-2011-01-03"); }
	}
	{
		// Month tests
		try { Date d("2011-00-03"); assert(false); } catch (std::exception) {}
		{ Date d("2011-01-03"); }
		{ Date d("2011-12-03"); }
		try { Date d("2011-13-03"); assert(false); } catch (std::exception) {}
	}
	{
		// Day tests
		try { Date d("2011-00-03"); assert(false); } catch (std::exception) {}
		{ Date d("2011-01-03"); }
		{ Date d("2011-12-03"); }
		try { Date d("2011-13-03"); assert(false); } catch (std::exception) {}
	}
	{
		// February
		{ Date d("2023-02-28"); }
		try { Date d("2023-02-29"); assert(false); } catch (std::exception) {}
		{ Date d("2024-02-29"); }
		try { Date d("2024-02-30"); assert(false); } catch (std::exception) {}
		{ Date d("2100-02-28"); }
		try { Date d("2100-02-29"); assert(false); } catch (std::exception) {}
		{ Date d("2000-02-29"); }
		try { Date d("2000-02-30"); assert(false); } catch (std::exception) {}

		// April
		{ Date d("2011-04-30"); }
		try { Date d("2011-04-31"); assert(false); } catch (std::exception) {}

		// July
		{ Date d("2011-07-31"); }
		try { Date d("2011-07-32"); assert(false); } catch (std::exception) {}

		// August
		{ Date d("2011-08-31"); }
		try { Date d("2011-08-32"); assert(false); } catch (std::exception) {}
	}
	{
		try { Date d(""); assert(false); } catch (std::exception) {}
		try { Date d("2011-01-03 "); assert(false); } catch (std::exception) {}
		try { Date d("2011-01 03"); assert(false); } catch (std::exception) {}
		try { Date d("2011-01"); assert(false); } catch (std::exception) {}
		try { Date d("-01-03"); assert(false); } catch (std::exception) {}
		try { Date d("--"); assert(false); } catch (std::exception) {}
		try { Date d("2011-01-"); assert(false); } catch (std::exception) {}
	}
	{
		Date d1("2011-10-1");
		Date d2(d1);
		Date d3("1-1-1");
		d2 = d2;
		d3 = d2;
		assert(d1 == d1);
		assert(d1 == d2);
		assert(d1 == d3);
	}
	{
		Date d1("2011-10-1");
		Date d2("2012-1-1");
		assert(d1 < d2);

		Date d3("2011-1-1");
		Date d4("2010-10-1");
		assert(!(d3 < d4));
	}
}

static void bitcoin_exchange_data_tests()
{
	{
		std::ifstream data("data.csv");
		if (!data.is_open()) {
			throw std::runtime_error("Couldn't open data file.");
		}
		BitcoinExchange btc(data);
	}
	{
		std::stringstream data("foo");
		try { BitcoinExchange btc(data); assert(false); } catch (std::exception) {}
	}
	{
		std::stringstream data("date,exchange_rate\n2009-01-02 0");
		try { BitcoinExchange btc(data); assert(false); } catch (std::exception) {}
	}
	{
		std::stringstream data("date,exchange_rate\n2009-01-02,a");
		try { BitcoinExchange btc(data); assert(false); } catch (std::exception) {}
	}
}

static void bitcoin_exchange_ocf_tests(std::stringstream &cout_buf, std::stringstream &cerr_buf)
{
	{
		// Test copy constructor

		std::ifstream data("data.csv");
		if (!data.is_open()) {
			throw std::runtime_error("Couldn't open data file.");
		}

		BitcoinExchange btc_original(data);
		BitcoinExchange btc(btc_original);

		std::stringstream input("date | value\n2011-01-03 | 3");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2011-01-03 => 3 = 0.9\n");
		assert(cerr_buf.str() == "");
	}
	{
		// Test copy assignment operator

		std::ifstream data("data.csv");
		if (!data.is_open()) {
			throw std::runtime_error("Couldn't open data file.");
		}

		std::stringstream other_data("date,exchange_rate\n1234-01-03,5");

		BitcoinExchange btc_original(data);
		BitcoinExchange btc(other_data);
		btc = btc;
		btc = btc_original;

		std::stringstream input("date | value\n2011-01-03 | 3");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2011-01-03 => 3 = 0.9\n");
		assert(cerr_buf.str() == "");
	}
}

static void bitcoin_exchange_input_error_tests(std::stringstream &cerr_buf)
{
	std::ifstream data("data.csv");
	if (!data.is_open()) {
		throw std::runtime_error("Couldn't open data file.");
	}
	BitcoinExchange btc(data);

	{
		std::ifstream input("input.txt");
		if (!input.is_open()) {
			throw std::runtime_error("Couldn't open input file.");
		}

		btc.processInputFile(input);
	}
	{
		std::stringstream input("foo");

		try { btc.processInputFile(input); assert(false); } catch (std::exception) {}
	}
	{
		std::stringstream input("date | value\n2011-01-03 , 3");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "Error: Line didn't contain the separator.\n");
	}
	{
		std::stringstream input("date | value\n2011-01-03 | a");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "Error: Expected double.\n");
	}
}

static void bitcoin_exchange_input_bounds_tests(std::stringstream &cerr_buf)
{
	std::ifstream data("data.csv");
	if (!data.is_open()) {
		throw std::runtime_error("Couldn't open data file.");
	}
	BitcoinExchange btc(data);

	{
		std::stringstream input("date | value\n2011-01-03 | -0.5");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "Error: Value was smaller than 0.\n");
	}
	{
		std::stringstream input("date | value\n2011-01-03 | 0");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "");
	}
	{
		std::stringstream input("date | value\n2011-01-03 | 1000");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "");
	}
	{
		std::stringstream input("date | value\n2011-01-03 | 1000.5");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "Error: Value was bigger than 1000.\n");
	}
}

static void bitcoin_exchange_input_tests(std::stringstream &cout_buf, std::stringstream &cerr_buf)
{
	std::ifstream data("data.csv");
	if (!data.is_open()) {
		throw std::runtime_error("Couldn't open data file.");
	}
	BitcoinExchange btc(data);

	{
		std::stringstream input("date | value\n2011-01-03 | 3");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2011-01-03 => 3 = 0.9\n");
		assert(cerr_buf.str() == "");
	}
}

static void bitcoin_exchange_date_bounds_tests(std::stringstream &cout_buf, std::stringstream &cerr_buf)
{
	std::ifstream data("data.csv");
	if (!data.is_open()) {
		throw std::runtime_error("Couldn't open data file.");
	}
	BitcoinExchange btc(data);

	{
		std::stringstream input("date | value\n1-01-03 | 0");

		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cerr_buf.str() == "Error: Date was before the earliest known date.\n");
	}
	{
		std::stringstream input("date | value\n2009-01-02 | 0");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2009-01-02 => 0 = 0\n");
		assert(cerr_buf.str() == "");
	}
	{
		std::stringstream input("date | value\n2011-01-03 | 1.2");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2011-01-03 => 1.2 = 0.36\n");
		assert(cerr_buf.str() == "");
	}
	{
		std::stringstream input("date | value\n2022-03-29 | 1");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2022-03-29 => 1 = 47115.9\n");
		assert(cerr_buf.str() == "");
	}
	{
		std::stringstream input("date | value\n2022-03-30 | 1");

		std::stringstream().swap(cout_buf);
		std::stringstream().swap(cerr_buf);
		btc.processInputFile(input);
		assert(cout_buf.str() == "2022-03-30 => 1 = 47115.9\n");
		assert(cerr_buf.str() == "");
	}
}
#endif

int	main(int argc, char *argv[])
{
	try {
#ifdef TESTS
	(void)argv;

	// Redirect anything written to std::cerr to this cout_buf
	std::stringstream cout_buf;
	std::streambuf *old_cout = std::cout.rdbuf(cout_buf.rdbuf());

	// Redirect anything written to std::cerr to this cerr_buf
	std::stringstream cerr_buf;
	std::streambuf *old_cerr = std::cerr.rdbuf(cerr_buf.rdbuf());

	if (argc > 1) {
		throw std::runtime_error("No argument expected, did you mean to run without TESTS=1?");
	}
	date_tests();
	bitcoin_exchange_data_tests();
	bitcoin_exchange_ocf_tests(cout_buf, cerr_buf);
	bitcoin_exchange_input_error_tests(cerr_buf);
	bitcoin_exchange_input_bounds_tests(cerr_buf);
	bitcoin_exchange_input_tests(cout_buf, cerr_buf);
	bitcoin_exchange_date_bounds_tests(cout_buf, cerr_buf);

	// Redirect std::cout back to the real std::cout
	std::cout.rdbuf(old_cout);

	// Redirect std::cerr back to the real std::cerr
	std::cerr.rdbuf(old_cerr);

	std::cout << "✓ All tests passed!" << std::endl << std::endl;
#else
	if (argc < 2) {
		throw std::runtime_error("Expected an input filepath.");
	}
	if (argc > 2) {
		throw std::runtime_error("Expected only 1 argument.");
	}

	std::ifstream data("data.csv");
	if (!data.is_open()) {
		throw std::runtime_error("Couldn't open data file.");
	}

	BitcoinExchange btc(data);

	std::ifstream input(argv[1]);
	if (!input.is_open()) {
		throw std::runtime_error("Couldn't open input file.");
	}

	btc.processInputFile(input);
#endif
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl << std::endl;
		system("leaks -q btc");
		return (EXIT_FAILURE);
	}

	system("leaks -q btc");

	return EXIT_SUCCESS;
}
