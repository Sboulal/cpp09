/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saboulal <saboulal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:05:56 by saboulal          #+#    #+#             */
/*   Updated: 2024/10/04 14:17:00 by saboulal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc,char **argv)
{
    BitcoinExchange exchange;
    if(argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
 try
 {
    exchange.execute(argv[1]);
    
 }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
  
    return 0;
} 

