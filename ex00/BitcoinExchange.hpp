#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<map>
#include <iostream>
#include<fstream>

class BitcoinExchange
{   
    private:
        std::map<std::string, std::string> _exchange;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

       
};
#endif