#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"[expression]\"" << std::endl;
        return 1;
    }
    RPN rpn;

    rpn.run(argv[1]);
    return 0;
}