#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this == &other)
        return *this;
    _vec = other._vec;
    _deq = other._deq;
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg.empty())
            throw std::runtime_error("Error");

        for (size_t j = 0; j < arg.size(); j++) {
            if (!std::isdigit(arg[j]))
                throw std::runtime_error("Error");
        }

        std::stringstream ss(arg);
        long n;
        ss >> n;
        if (ss.fail() || n < 0 || n > 2147483647)
            throw std::runtime_error("Error");

        _vec.push_back(static_cast<int>(n));
        _deq.push_back(static_cast<int>(n));
    }
}

void PmergeMe::mergeInsertVector(std::vector<int>& v) {
    if (v.size() <= 1)
        return;

    std::vector<int> larger;
    std::vector<int> smaller;

    for (size_t i = 0; i + 1 < v.size(); i += 2) {
        if (v[i] > v[i + 1]) {
            larger.push_back(v[i]);
            smaller.push_back(v[i + 1]);
        } else {
            larger.push_back(v[i + 1]);
            smaller.push_back(v[i]);
        }
    }

    bool hasOdd = v.size() % 2 != 0;
    int oddElement = 0;
    if (hasOdd)
        oddElement = v[v.size() - 1];

    mergeInsertVector(larger);

    v = larger;

    for (size_t i = 0; i < smaller.size(); i++) {
        std::vector<int>::iterator pos =
            std::lower_bound(v.begin(), v.end(), smaller[i]);
        v.insert(pos, smaller[i]);
    }

    if (hasOdd) {
        std::vector<int>::iterator pos =
            std::lower_bound(v.begin(), v.end(), oddElement);
        v.insert(pos, oddElement);
    }
}

void PmergeMe::mergeInsertDeque(std::deque<int>& d) {
    if (d.size() <= 1)
        return;

    std::deque<int> larger;
    std::deque<int> smaller;

    for (size_t i = 0; i + 1 < d.size(); i += 2) {
        if (d[i] > d[i + 1]) {
            larger.push_back(d[i]);
            smaller.push_back(d[i + 1]);
        } else {
            larger.push_back(d[i + 1]);
            smaller.push_back(d[i]);
        }
    }

    bool hasOdd = d.size() % 2 != 0;
    int oddElement = 0;
    if (hasOdd)
        oddElement = d[d.size() - 1];

    mergeInsertDeque(larger);

    d = larger;

    for (size_t i = 0; i < smaller.size(); i++) {
        std::deque<int>::iterator pos =
            std::lower_bound(d.begin(), d.end(), smaller[i]);
        d.insert(pos, smaller[i]);
    }

    if (hasOdd) {
        std::deque<int>::iterator pos =
            std::lower_bound(d.begin(), d.end(), oddElement);
        d.insert(pos, oddElement);
    }
}

double PmergeMe::getTime(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000.0
         + (end.tv_usec - start.tv_usec);
}

void PmergeMe::run() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);
    mergeInsertVector(_vec);
    gettimeofday(&endVec, NULL);

    struct timeval startDeq, endDeq;
    gettimeofday(&startDeq, NULL);
    mergeInsertDeque(_deq);
    gettimeofday(&endDeq, NULL);

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : "
              << getTime(startVec, endVec) << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : "
              << getTime(startDeq, endDeq) << " us" << std::endl;
}