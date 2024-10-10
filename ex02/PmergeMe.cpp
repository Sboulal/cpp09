#include"PmergeMe.hpp"

//getter of this class

// 


template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> >() {
    return "vector<int>";
}

template <>
std::string getContainerName<std::deque<int> >() {
    return "deque<int>";
}

template<typename Container>
PmergeMe<Container>::PmergeMe() : _container(), _value(-1), _time(0) {}


template <typename Container>
PmergeMe<Container>::PmergeMe(char **data) : _container() {

    _time = 0;
    _value = -1;

    for(size_t i = 0; data[i]; i++) {
        if (is_number(data[i]) != 0) {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        _container.push_back(ft_stoa(data[i]));
    }
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
    _container = other._container;
}

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) {
    if (this != &other) {
        _container = other._container;
        _value = other._value;
        _time = other._time;
    }
    return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}


template <typename Container>
void PmergeMe<Container>::sort_numbers() {

    std::clock_t start = std::clock();

    vector_pair pairs = generate_pairs(_container);
    int_vector insertionIndexes = generate_indexes(_container.size());

    // If the input is empty, we just need to push the last element
    if (pairs.size() == 0) {
        _container.push_back(_value);
        _time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return;
    }

    sort_pairs(pairs);

    _container.clear();

    _container.push_back(pairs[0].second);

    for (size_type i = 0; i < pairs.size(); i++) {
        _container.push_back(pairs[i].first);
    }
    
    for (size_t i = 0; i < insertionIndexes.size(); i++)
    {
        if (size_t(insertionIndexes[i] - 1) >= pairs.size()) {
            continue;
        }

        int index = binary_search(pairs[insertionIndexes[i] - 1].second);
        _container.insert(_container.begin() + index, pairs[insertionIndexes[i] - 1].second);
    }

    if (_value != -1) {
        int index = binary_search(_value);
        _container.insert(_container.begin() + index, _value);
    }

    _time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <typename Container>
typename PmergeMe<Container>::vector_pair PmergeMe<Container>::generate_pairs(Container &data) {
    vector_pair pairs;

    // If the size of the data is odd, we need to store the last element
    if (data.size() % 2 != 0) {
        _value = data.back();
        data.pop_back();
    }

size_type i = 0;
    while(i < data.size())
    {
        if (data[i] < data[i + 1]) {
            std::swap(data[i], data[i + 1]);
        }

        pairs.push_back(std::make_pair(data[i], data[i + 1]));
        i += 2;
    }
    return pairs;
}

template <typename Container>
void PmergeMe<Container>::sort_pairs(vector_pair &pairs) {
    if (pairs.size() <= 1) {
        return; // Base case: Nothing to sort
    }

    // Divide the vector into two halves
    size_type middle = pairs.size() / 2;
    vector_pair left(pairs.begin(), pairs.begin() + middle);
    vector_pair right(pairs.begin() + middle, pairs.end());

    // Recursively sort the two halves
    sort_pairs(left);
    sort_pairs(right);

   // Merge the sorted halves
    Merge_Sorted_halves(left, right, pairs);
}

template <typename Container>
void   PmergeMe<Container>::Merge_Sorted_halves( vector_pair leftHalf, vector_pair rightHalf, vector_pair &pairs)
{
    size_type leftIdx = 0;
    size_type rightIdx = 0;
    size_type idx = 0;

    while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size()) {
        pairs[idx++] = leftHalf[leftIdx].first < rightHalf[rightIdx].first ? leftHalf[leftIdx++] : rightHalf[rightIdx++];
    }

    while (leftIdx < leftHalf.size()) {
        pairs[idx++] = leftHalf[leftIdx++];
    }

    while (rightIdx < rightHalf.size()) {
        pairs[idx++] = rightHalf[rightIdx++];
    }
}
template <typename Container>
int PmergeMe<Container>::binary_search(int target) {
    int left = 0;
    int right = _container.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (_container[middle] == target) {
            return middle;
        } else if (_container[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return left;
}

template <typename Container>
int_vector PmergeMe<Container>::generate_indexes(size_t size) {
    int_vector indexes;
    int jacobsthalSequence[size + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;

    for (size_t i = 2; indexes.size() < size; i++)
    {
        // Generate the next Jacobsthal number
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        if(i != 2)
        {
            indexes.push_back(jacobsthalSequence[i]);

        }

        // Push back the indexes between the last Jacobsthal number and the current one
        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            indexes.push_back(j);

        // Update the last Jacobsthal number
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return (indexes);
}

template<typename Container>
void PmergeMe<Container>::print() const {
    for (size_t i = 0; i < _container.size(); i++) {
        std::cout << _container[i] << " ";
    }
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::benchmark() const {
    std::cout
            <<	"Time to process a range of " << _container.size()
            << " elements with std::" << getContainerName< Container >()
            << " : " << std::fixed << std::setprecision(5) << _time << " us"
            << std::endl;
}

template<typename Container>
int PmergeMe<Container>::ft_stoa(const char *str) {
    std::istringstream  ss(str);
    int                 number;

    ss >> number; // Convert the string

    return (number);
}

template<typename Container>
int PmergeMe<Container>::is_number(const std::string& s)
{
    if (s.empty() || s[0] == '-') {
        return (1);
    }

    size_t i = 0;

    if (s[0] == '+' && s.length() == 1) {
        return (1);
    } else if (s[0] == '+') {
        i++;
    }

    for (; i < s.length(); i++) {
        if (!std::isdigit(s[i])) {
            return (1);
        }
    }

    return (0);
}

// Explicit instantiation: https://stackoverflow.com/a/495021/10372819
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;