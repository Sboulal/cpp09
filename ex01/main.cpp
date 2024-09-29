#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"[expression]\"" << std::endl;
        return 1;
    }
   try{ 
    RPN rpn;
    rpn.calculate(argv[1]);
    rpn.printResult();}
    catch(std::exception &e)
    {
        std::cerr << "Error" << std::endl;
    }
    return 0;
}