#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>


class RPN
{
public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    void calculate(std::string input);
    void printResult() const;

private:
    double _result;
};

#endif