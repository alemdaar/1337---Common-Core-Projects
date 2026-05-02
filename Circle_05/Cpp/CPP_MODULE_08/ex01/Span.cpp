#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    _numbers = other._numbers;
    _maxSize = other._maxSize;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("not enough numbers to compute span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = INT_MAX;
    for (unsigned int i = 1; i < sorted.size(); i++) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("not enough numbers to compute span");
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    return max - min;
}