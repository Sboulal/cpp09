#include "RPN.hpp"

RPN::RPN() {
    this->oper[0].op = "+";
    this->oper[0].f = &RPN::add;
    this->oper[1].op = "-";
    this->oper[1].f = &RPN::sub;
    this->oper[2].op = "*";
    this->oper[2].f = &RPN::mul;
    this->oper[3].op = "/";
    this->oper[3].f = &RPN::div;
}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other)
    {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::run(std::string input)
{
    std::string tmp;
    for (size_t i = 0; i < input.length(); i++)
    {
        if ((std::isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') && input[i - 1] != ' ' && i != 0)
        {
            tmp += " ";
            tmp += input[i];
        }
        else
        {
           tmp += input[i];
        }
    }
    input = tmp;
    std::stringstream ss(input);
    std::string operations[] = {"+", "-", "*", "/"};

    
        while (ss >> input)
        {
            int index = index_of(input, operations, 4);
            if (index != -1)
            {
                 if (this->_stack.size() < 2) // if there is less than two elements in the stack
                 {  
                    std::cout << "Not enough" << std::endl;
                    exit(1);
                }

                 int a = this->_stack.top();
                 this->_stack.pop();
                 int b = this->_stack.top();
                 this->_stack.pop();

                 this->_stack.push((this->*oper[index].f)(b, a));
            }
            else
            {

        this->_stack.push(ft_stoi(ft_all_of(input, &std::isdigit)));
            }
        }

        if (this->_stack.size() != 1) // if there is more than one element in the stack
             {   //   throw std::invalid_argument("Not enough operands");
                    std::cout << "Not enough" << std::endl;
                    exit(1);
                }

        std::cout << this->_stack.top() << std::endl;

    

    ss.clear();
}

int RPN::add(int a, int b)
{
    return a + b;
}

int RPN::sub(int a, int b)
{
    return a - b;
}

int RPN::mul(int a, int b)
{
    return a * b;
}

int RPN::div(int a, int b)
{
    if (b == 0)
   {     
        std::cout << "Error" << std::endl;
        exit(1);}

    return a / b;
}



int RPN::index_of(std::string str, std::string *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (str == arr[i])
            return i;
    }
    return -1;
}

int RPN::ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int result;

    ss >> result;

    if (ss.fail())
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }

    return result;
}

std::string RPN::ft_all_of(const std::string& str, int (*isDigit)(int)) {

    bool valid = true;
    std::string tmp;
    size_t i = 0;

    if (str.length() == 1 && (str[0] == '+' || str[0] == '-'))
        valid = false;

    if (str.length() == 0)
        valid = false;
    if (str[0] == '+' || str[0] == '-')
        i = 1;

    for (; i < str.length(); i++) {
        if (!isDigit(str[i]) )
            valid = false;
    }

    if (!valid) 
    {
        std::cout << "not a number" << std::endl;
        exit(1);
    }

    return str;
}