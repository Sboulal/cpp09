#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

   
    try{ 
        PmergeMe<std::vector<int> > v(argv + 1);

        std::cout << "Before:\t" ;
        v.print();

        v.sort_numbers();

        PmergeMe<std::deque<int> > dq(argv + 1);
        dq.sort_numbers();

        std::cout << "After:\t";
        dq.print();

        v.benchmark();
        dq.benchmark();
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
   

    return 0;
}