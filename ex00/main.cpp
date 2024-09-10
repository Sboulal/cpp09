/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboulal <saboulal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:05:56 by saboulal          #+#    #+#             */
/*   Updated: 2024/09/10 12:49:02 by saboulal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include " BitcoinExchange.hpp"
#include <iostream>
#include<fstream>

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
        while(std::getline(file, line))
        {
           if(line == "data | value")
                break;
           std::cout << line << std::endl;
        }
    }
}