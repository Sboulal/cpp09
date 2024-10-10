#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");
    if(!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit (1);
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        exit (1);
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        exit (1);
    }
    std::string line;
    std::string key;
    std::string value;
    
    std::getline(file,line);
   
        while (std::getline(file, line))
        {
            size_t delim = line.find(',');
            key = trim_space(line.substr(0, delim));
            value = trim_space(line.substr(delim + 1 , line.length()));
            _exchange[key] = value;
        }
        file.close();
 
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

std::string BitcoinExchange::previous_date(const std::string& date)
{
  
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
   
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
   if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
   {
       days_in_month[2] = 29;
   }
    if (day > 0)
        day--;
   
   if (day == 0) {
        month--;

        // Check if month is 0 (December)
        if (month == 0) {
            // month = 12;
            year--;

        }

        day = days_in_month[month];
    }

    // Format the previous date
    std::string newYear = ft_to_string(year);
    std::string newMonth = (month < 10) ? "0" + ft_to_string(month) : ft_to_string(month);
    std::string newDay = (day < 10) ? "0" + ft_to_string(day) : ft_to_string(day);

    return newYear + "-" + newMonth + "-" + newDay;
}

int BitcoinExchange::ValidateDecimalPoint(const std::string& value)
{
    size_t count = 0;
    for(size_t i = 0; i < value.size(); i++)
    {
        if(value[i] < '0' || value[i] > '9')
        {
            if(value[i] == '.' && i != 0 && i != value.size() - 1)
             {  
                 count++;
             if(count > 1)
             {
                 
                 return(1);
             }
    
                continue;
             }
             if(value[i] == '+' && i == 0 && value.size() > 1)
             {
                 continue;
             }
            return 1;

        }
    }
    return(0);
}
void BitcoinExchange::execute(const char *argv)
{
    std::string line;
        
    std::ifstream file(argv);
    if(!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        exit (1);
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        exit (1);
    }
    else if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error: file is empty." << std::endl;
        exit (1);
    }
       else
       { if(std::getline(file, line))
        {
            if(line != "date | value")
            {
                std::cout << "Error: bad input" << std::endl;
                exit (1);
            }
        }
        while(std::getline(file, line))
        {
            std::string date;
            std::string value;
            std::string::size_type pos = line.find('|');
            if(pos == std::string::npos)
            {
                std::cout << "Error: bad input => "<< line << std::endl;
                continue;
            
            }
            date = trim_space(line.substr(0, pos));
            value = trim_space(line.substr(pos + 1));
            if(date.empty() || value.empty())
            {
                std::cout << "Error: bad input => "<< line << std::endl;
                continue;
               
            }
            if(date[4] != '-' || date[7] != '-' || date.size() != 10)
            {
                std::cout << "Error: bad input => "<< line << std::endl;
                continue;
                
            }
            for(size_t i = 0; i < date.size(); i++)
            {
                if(i == 4 || i == 7)
                    continue;
                if(date[i] < '0' || date[i] > '9')
                {
        
                    std::cout << "Error: bad input => "<< line << std::endl;
                    continue;
                  
                }
            }
            std::string year = date.substr(0, 4);
            std::string month = date.substr(5, 2);
            std::string day = date.substr(8, 2);

            if(!std::all_of(year.begin(), year.end(), ::isdigit) || !std::all_of(month.begin(), month.end(), ::isdigit) || !std::all_of(day.begin(), day.end(), ::isdigit))
            {
                std::cout << "Error: bad input => "<< date << std::endl;
                continue;
                
            }

            int yearInt, monthInt, dayInt;

            std::stringstream ssYear(year);
            std::stringstream ssMonth(month);
            std::stringstream ssDay(day);
        
            ssYear >> yearInt;
            ssMonth >> monthInt;
            ssDay >> dayInt;
            if(yearInt < 2009 || yearInt > 2022 || monthInt < 1 || monthInt > 12 || dayInt < 1 || dayInt > 31)
            {
               std::cout << "Error: bad input => "<< date << std::endl;
               continue;
            
            }
            else if (yearInt == 2009 && dayInt < 2)
            {
               std::cout << "Error: bad input => "<< date << std::endl;
               continue;
            
            }
            if(monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)
            {
                if(dayInt == 31)
                {
                    std::cout << "Error: bad input => "<< date << std::endl;
                    continue;
                    
                }
            }
            if(monthInt == 2)
            {
                if(dayInt == 30 || dayInt == 31)
                {
                    std::cout << "Error: bad input => "<< date << std::endl;
                    continue;
                    
                }
                if((yearInt % 4 == 0 && yearInt % 100 != 0) || yearInt % 400 == 0)
                {
                   if(dayInt > 29)
                   {
                       std::cout << "Error: bad input => "<< date << std::endl;
                       continue;
                       
                   }
                    
                }
                else 
                {
                       if(dayInt > 28)
                       {
                         std::cout << "Error: bad input => "<< date << std::endl;
                         continue;
                         
                       }
                }
            }
            if(ValidateDecimalPoint(value))
            {
                std::cout << "Error: bad input => "<< value << std::endl;
                continue;
                
            }    
            //check sign of value + or -
            for(size_t i = 0; i < value.size(); i++)
            {
                if(value[i] == '.')
                {
                    if(i == 0 || i == value.size() - 1)
                    {
                        std::cout << "not a number => " << value[i] << std::endl;
                        continue;
                    }
                }
            }
            double val = ft_stod(value);
            if(val < 0)
            {
                std::cout << "Error: not a positive number." <<std::endl;
                continue;
            }
            if(val > 1000.0)
            {
                std::cout << "Error: too large a number."<< std::endl;
                continue;
                
            }
            std::map<std::string, std::string>::iterator it;

            std::string prev_date = date; 
          
            it = _exchange.find(date);
            while(it == _exchange.end())
            {
                const std::string& current_date = prev_date;
                prev_date = previous_date(current_date);
                it = _exchange.find(prev_date);
            }
            std::cout << date << " => " << value << " = " << ft_stod(it->second) * ft_stod(value)<<std::endl;
        }
        }
        file.close();
}

std::string BitcoinExchange::trim_space(const std::string& str)
{
    size_t start = str.find_first_not_of(' ');
    if(start == std::string::npos)
        return str;
    size_t end = str.find_last_not_of(' ');
    return str.substr(start, (end - start + 1));
}

double BitcoinExchange::ft_stod(const std::string &str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;

    return value;
}

std::string BitcoinExchange::ft_to_string(int value)
{
    std::stringstream ss;

    ss << value;

    return ss.str();
}