/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboulal <saboulal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:05:56 by saboulal          #+#    #+#             */
/*   Updated: 2024/09/29 15:50:54 by saboulal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include<fstream>

std::string trim_space(std::string str)
{
    std::string::size_type start = str.find_first_not_of(" ");
    std::string::size_type end = str.find_last_not_of(" ");
    if(start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}
int main(int argc,char **argv)
{
    if(argc != 2)
    {
        std::cout << "Error: could not open file.*****" << std::endl;
        return 1;
    }

    // BitcoinExchange exchange;

    std::ifstream file(argv[1]);
    if(!file.is_open())
    {
        std::cout << "Error: could not open file.++++" << std::endl;
        return 1;
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        return 1;
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        return 1;
    }
    else
    {
        std::string line;
        
        
        if(std::getline(file, line))
        {
            if(line != "date | value")
            {
                std::cout << "Error: Not Valid" << std::endl;
                return 1;
            }
        }
        while(std::getline(file, line))
        {
            std::string date;
            std::string value;
            std::string::size_type pos = line.find('|');
            if(pos == std::string::npos)
            {
                std::cout << "Error: Not Valid" << std::endl;
                return 1;
            }
            date = trim_space(line.substr(0, pos));
            value = trim_space(line.substr(pos + 1));
            if(date.empty() || value.empty())
            {
                std::cout << "Error: Not Valid" << std::endl;
                return 1;
            }
            std::cout << "date: " << date << " value: " << value << std::endl;
            

            
            
            
        }
    }
} 
