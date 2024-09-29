#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    std::string line;
    std::string key;
    std::string value;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            key = line.substr(0, line.find(":"));
            value = line.substr(line.find(":") + 1);
            _exchange[key] = value;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: exchange.txt could not be opened" << std::endl;
    }
}

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) 
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
    {
        _exchange = other._exchange;
    }
        return *this;
}