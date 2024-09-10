#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include<map>
#include <iostream>
#include<fstream>

class BitcoinExchange
{   
    private:
        std::map<std::string, double> exchangeRate;
        double rate;
        double amount;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void setRate(double rate);
        double getRate() const;
        void setAmount(double amount);
        double getAmount() const;
        double convertToBitcoin() const;
        double convertToUsd() const;


};
#endif