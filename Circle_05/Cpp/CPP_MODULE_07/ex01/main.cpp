#include <iostream>
#include <string>
#include "iter.hpp"

// non-const reference → can modify
template <typename T>
void print(T& x) {
    std::cout << x << std::endl;
}

// const reference → cannot modify
template <typename T>
void printConst(const T& x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T& x) {
    x++;
}

int main() {
    // test with int
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "--- int array ---" << std::endl;
    iter(arr, 5, print<int>);

    // test increment
    std::cout << "--- after increment ---" << std::endl;
    iter(arr, 5, increment<int>);
    iter(arr, 5, print<int>);

    // test with string
    std::string strs[] = {"hello", "world", "42"};
    std::cout << "--- string array ---" << std::endl;
    iter(strs, 3, print<std::string>);

    // test with const array
    const int constArr[] = {10, 20, 30};
    std::cout << "--- const int array ---" << std::endl;
    iter(constArr, 3, printConst<int>);

    return 0;
}