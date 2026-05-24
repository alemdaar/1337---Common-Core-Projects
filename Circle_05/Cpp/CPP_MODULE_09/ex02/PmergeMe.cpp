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
        std::stringstream ss(argv[i]);
        int n;
        ss >> n;
        if (ss.fail() || n < 0)
            throw std::runtime_error("Error");
        _vec.push_back(n);
        _deq.push_back(n);
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& v, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= left && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
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
        std::vector<int>::iterator pos = std::lower_bound(v.begin(), v.end(), smaller[i]);
        v.insert(pos, smaller[i]);
    }

    if (hasOdd) {
        std::vector<int>::iterator pos = std::lower_bound(v.begin(), v.end(), oddElement);
        v.insert(pos, oddElement);
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& d, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = d[i];
        int j = i - 1;
        while (j >= left && d[j] > key) {
            d[j + 1] = d[j];
            j--;
        }
        d[j + 1] = key;
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
        std::deque<int>::iterator pos = std::lower_bound(d.begin(), d.end(), smaller[i]);
        d.insert(pos, smaller[i]);
    }

    if (hasOdd) {
        std::deque<int>::iterator pos = std::lower_bound(d.begin(), d.end(), oddElement);
        d.insert(pos, oddElement);
    }
}

void PmergeMe::sort() {
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertVector(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    mergeInsertDeque(_deq);
    clock_t endDeq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}