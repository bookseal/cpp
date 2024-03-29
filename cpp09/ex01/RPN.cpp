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
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int a = stack->top();
	stack->pop();
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int b = stack->top();
	stack->pop();
	int sum = a + b;
	if (sum - b != a || sum - a != b)
		throw std::runtime_error("Error: Overflow");
	stack->push(a + b);
}

void RPN::sub() {
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int a = stack->top();
	stack->pop();
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int b = stack->top();
	stack->pop();
	int diff = b - a;
	if (diff + a != b || diff - b != -a)
		throw std::runtime_error("Error: Overflow");
	stack->push(b - a);
}

void RPN::mul() {
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int a = stack->top();
	stack->pop();
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int b = stack->top();
	stack->pop();
	int mul = a * b;
	if (a != 0 && mul / a != b)
		throw std::runtime_error("Error: Overflow");
	if (b != 0 && mul / b != a)
		throw std::runtime_error("Error: Overflow");
	stack->push(a * b);
}

void RPN::div() {
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int a = stack->top();
	stack->pop();
	if (stack->empty())
		throw std::runtime_error("Error: Stack is empty");
	int b = stack->top();
	stack->pop();
	if (a == 0)
		throw std::runtime_error("Error: Division by zero");
	int div = b / a;
	if (a != 0 && div * a != b)
		throw std::runtime_error("Error: Overflow");
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
