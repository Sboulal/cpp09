#include "RPN.hpp"


RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
        return *this;
    return *this;
}

void RPN::calculate(std::string input)
{
    std::stack<double> stack;
    std::stringstream ss(input);
    std::string token;
    double a;
    double b;

if (input.empty())
    {
        std::cerr << "Error: empty input" << std::endl;
        return;
    }
    if(ss.fail())
    {
       throw std::invalid_argument("Error");
        return;
    }
    while (ss >> token)
    {
        if (token == "+")
        {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(b + a);
        }
        else if (token == "-")
        {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(b - a);
        }
        else if (token == "*")
        {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(b * a);
        }
        else if (token == "/")
        {
            a = stack.top();
            stack.pop();
            b = stack.top();
            stack.pop();
            stack.push(b / a);
        }
        else
        {
            stack.push(std::stod(token));
        }
    }
    _result = stack.top();
}

void RPN::printResult() const
{
    std::cout << _result << std::endl;
}