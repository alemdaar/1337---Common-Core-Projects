#include <iostream>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest:  " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
    std::cout << "\n--- overflow test ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- not enough numbers ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- 10000 numbers test ---" << std::endl;
    try {
        Span sp(10000);
        std::vector<int> bigList;
        for (int i = 0; i < 10000; i++)
            bigList.push_back(i * 2);

        sp.addNumber(bigList.begin(), bigList.end());
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest:  " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}