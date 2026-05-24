#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <ctime>
# include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parse(int argc, char** argv);
    void sort();

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    void mergeInsertVector(std::vector<int>& v);
    void insertionSortVector(std::vector<int>& v, int left, int right);

    void mergeInsertDeque(std::deque<int>& d);
    void insertionSortDeque(std::deque<int>& d, int left, int right);
};

#endif