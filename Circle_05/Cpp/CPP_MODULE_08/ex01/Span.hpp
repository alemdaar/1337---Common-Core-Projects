#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end);

    int shortestSpan() const;
    int longestSpan() const;

private:
    Span();

    std::vector<int> _numbers;
    unsigned int     _maxSize;
};

template <typename Iterator>
void Span::addNumber(Iterator begin, Iterator end) {
    if (_numbers.size() + std::distance(begin, end) > _maxSize)
        throw std::out_of_range("not enough space");
    _numbers.insert(_numbers.end(), begin, end);
}

#endif