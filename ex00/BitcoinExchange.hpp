#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<map>
#include <iostream>
#include<fstream>
#include <sstream>

class BitcoinExchange
{   
    private:
        std::map<std::string, std::string> _exchange;
        std::string previous_date(const std::string& date);
        std::string trim_space(const std::string& str);
        int  ValidateDecimalPoint(const std::string& value);
        std::string ft_to_string(int value);
        double ft_stod(const std::string &str);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void execute(const char *filename);
       
};
#endif