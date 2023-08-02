#include "RPN.hpp"

#include <iostream>
#include <sstream>
#include <stack>
#include <iomanip>

int RPN::process(const std::string &expression)
{
	std::stringstream ss(expression);
	ss >> std::noskipws;

	std::stack<int> stack;

	if (expression.empty()) {
		throw std::runtime_error("Expression is empty.");
	}

	while (!ss.eof()) {
		char c;
		ss >> c;

		if (ss.eof()) {
			throw std::runtime_error("Expected digit or operator.");
		}
		if (ss.fail()) {
			throw std::runtime_error("Stream failure.");
		}

		if ('0' <= c && c <= '9') {
			int digit = c - '0';
			stack.push(digit);
		} else {
			if (c != '+' && c != '-' && c != '*' && c != '/') {
				throw std::domain_error("Expected digit or operator.");
			}

			if (stack.size() < 2) {
				throw std::underflow_error("Stack underflow.");
			}

			int top = stack.top(); stack.pop();
			int second_to_top = stack.top(); stack.pop();

			if (c == '+') {
				stack.push(second_to_top + top);
			} else if (c == '-') {
				stack.push(second_to_top - top);
			} else if (c == '*') {
				stack.push(second_to_top * top);
			} else if (c == '/') {
				if (top == 0) {
					throw std::runtime_error("Division by zero.");
				}
				stack.push(second_to_top / top);
			}
		}

		char space;
		ss >> space;
		if (ss.eof()) {
			break;
		}
		if (space != ' ') {
			// "1x2"
			throw std::domain_error("Expected space character.");
		}
	}

	if (stack.size() > 1) {
		throw std::overflow_error("Stack overflow.");
	}

	return stack.top();
}
