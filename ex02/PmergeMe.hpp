#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include<string>
#include<cctype>
#include <ctime>
#include <iomanip>
#include <sstream>

typedef std::vector<int> int_vector;

template<typename Container>
class PmergeMe
{
    public:
        typedef typename Container::value_type T;
        typedef typename Container::size_type size_type;
        typedef std::pair<T, T> type_pair;
        typedef std::vector<type_pair> vector_pair;
    private:
        Container _container; //_container
        T _value; //_value
        double _time;

         int        is_number(const std::string& s);
        vector_pair generate_pairs(Container &container);
        int_vector generate_indexes(size_t size);
        int binary_search(int value);
        void sort_pairs(vector_pair &pairs);
        int ft_stoa(const char *str);
    public:
        PmergeMe();
        explicit PmergeMe(char **argv);
        PmergeMe(const PmergeMe &pmergeMe);
        PmergeMe &operator=(const PmergeMe &pmergeMe);
        ~PmergeMe();
        void print()const;
        void sort_numbers();
        void benchmark()const;
        void Merge_Sorted_halves(vector_pair leftHalf, vector_pair rightHalf, vector_pair &pairs);

        




};




#endif