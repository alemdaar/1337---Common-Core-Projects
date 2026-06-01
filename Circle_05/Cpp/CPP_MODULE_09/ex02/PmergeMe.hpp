#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <iomanip>
# include <sys/time.h>
# include <algorithm>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parse(int argc, char** argv);
    void run();

private:
    std::vector<int> _vec;
    std::deque<int>  _deq;

    void mergeInsertVector(std::vector<int>& v);
    void mergeInsertDeque(std::deque<int>& d);

    double getTime(struct timeval start, struct timeval end);
};

#endif