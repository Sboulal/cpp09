#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : rate(0), amount(0) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : rate(other.rate), amount(other.amount) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return *this;
    rate = other.rate;
    amount = other.amount;
    return *this;
}

void BitcoinExchange::setRate(double rate)
{
    this->rate = rate;
}

double BitcoinExchange::getRate() const
{
    return rate;
}

void BitcoinExchange::setAmount(double amount)
{
    this->amount = amount;
}

double BitcoinExchange::getAmount() const
{
    return amount;
}


double BitcoinExchange::convertToBitcoin() const
{
    return amount / rate;
}

double BitcoinExchange::convertToUsd() const
{
    return amount * rate;
}

