#include "RPN.hpp"

RPN::RPN() {
	stack = new std::stack<int>;
}

RPN::~RPN() {
	delete stack;
}

RPN::RPN(const RPN &rpn) {
	stack = new std::stack<int>(*rpn.stack);
}

RPN &RPN::operator=(const RPN &rpn) {
	if (this != &rpn) {
		delete stack;
		stack = new std::stack<int>(*rpn.stack);
	}
	return *this;
}

void RPN::push(int n) {
	stack->push(n);
}

void RPN::pop() {
	stack->pop();
}

int RPN::top() const {
	return stack->top();
}

bool RPN::empty() const {
	return stack->empty();
}

int RPN::size() const {
	return stack->size();
}

void RPN::add() {
	int a = stack->top();
	stack->pop();
	int b = stack->top();
	stack->pop();
	stack->push(a + b);
}

void RPN::sub() {
	int a = stack->top();
	stack->pop();
	int b = stack->top();
	stack->pop();
	stack->push(b - a);
}

void RPN::mul() {
	int a = stack->top();
	stack->pop();
	int b = stack->top();
	stack->pop();
	stack->push(a * b);
}

void RPN::div() {
	int a = stack->top();
	if (a == 0)
		throw std::runtime_error("Error: Division by zero");
	stack->pop();
	int b = stack->top();
	stack->pop();
	stack->push(b / a);
}

void RPN::print() const {
	std::stack<int> temp = *stack;
	if (temp.empty())
		return;
	else if (temp.size() != 1) {
		throw std::runtime_error("Error");
	}
	std::cout << temp.top() << std::endl;
}

bool RPN::hasTokenBracket(std::string token) {
	return token.find("(") != std::string::npos || token.find(")") != std::string::npos;
}

bool RPN::hasTokenDicimalNumbers(std::string token) {
	return token.find(".") != std::string::npos;
}
