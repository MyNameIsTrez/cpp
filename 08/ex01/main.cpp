#include "Span.hpp"

#include <iostream>
#include <vector>

static void tests()
{
	{
		Span span(5);

		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

		assert(span.shortestSpan() == 2);
		assert(span.longestSpan() == 14);
	}
	{
		Span span1(2);
		span1.addNumber(1);
		span1.addNumber(2);

		span1 = span1;

		Span span2(1);
		span2 = span1;

		assert(span2.shortestSpan() == 1);
	}
	{
		Span span1(2);
		span1.addNumber(1);
		span1.addNumber(2);

		Span span2(span1);
		assert(span2.shortestSpan() == 1);
	}
	{
		std::vector<int> vector;
		vector.push_back(1);
		vector.push_back(2);

		Span span(vector.begin(), vector.end());
		assert(span.shortestSpan() == 1);
	}
	{
		Span span(0);

		try { span.addNumber(42); assert(false); } catch (std::exception) {};
		try { (void)span.shortestSpan(); assert(false); } catch (std::exception) {};
		try { (void)span.longestSpan(); assert(false); } catch (std::exception) {};
	}
	{
		Span span(2);

		try { (void)span.shortestSpan(); assert(false); } catch (std::exception) {};
		try { (void)span.longestSpan(); assert(false); } catch (std::exception) {};

		span.addNumber(1);

		try { (void)span.shortestSpan(); assert(false); } catch (std::exception) {};
		try { (void)span.longestSpan(); assert(false); } catch (std::exception) {};

		span.addNumber(2);

		assert(span.shortestSpan() == 1);
		assert(span.longestSpan() == 1);
	}
	{
		Span span(10000);

		for (size_t i = 0; i < 10000; i++)
		{
			span.addNumber(42);
		}

		try { span.addNumber(42); assert(false); } catch (std::exception) {};

		assert(span.shortestSpan() == 0);
		assert(span.longestSpan() == 0);
	}
	{
		std::vector<int> vector(10000, 42);

		for (size_t i = 0; i < 10000; i += 2000)
		{
			std::cout << "vector[" << i << "] = " << vector[0] << std::endl;
		}

		Span span(vector.begin(), vector.end());

		try { span.addNumber(42); assert(false); } catch (std::exception) {};

		assert(span.shortestSpan() == 0);
		assert(span.longestSpan() == 0);
	}
}

int	main()
{
	tests();

	system("leaks -q span");

	std::cout << "✓ All tests passed!" << std::endl;

	return EXIT_SUCCESS;
}
