#ifndef STACK_ARRAY_EXCEPTIONS_H
#define STACK_ARRAY_EXCEPTIONS_H

#include <stdexcept>

class StackOverFlowException final: public std::exception {
public:
	const char* what() const noexcept override {
		return "StackOverFlow error.\n";
	}
};

class StackUnderFlowException final: public std::exception {
public:
	const char* what() const noexcept override {
		return "StackUnderFlow error.\n";
	}
};

#endif //STACK_ARRAY_EXCEPTIONS_H
