//
// Created by lee gichan on 2/9/24.
//

#ifndef CPP_RPN_H
#define CPP_RPN_H

#include <stack>
#include <iostream>

class RPN {
private:
    std::stack<int> *stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN &rpn);
    RPN &operator=(const RPN &rpn);
    void push(int n);
    void pop();
    int top() const;
    bool empty() const;
    int size() const;
    void add();
    void sub();
    void mul();
    void div();
    void print() const;

    bool hasTokenBracket(std::string token);
    bool hasTokenDicimalNumbers(std::string token);
};


#endif //CPP_RPN_H
