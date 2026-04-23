#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "--- empty array ---" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n--- array of 5 ints ---" << std::endl;
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << std::endl;

    std::cout << "\n--- deep copy ---" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "original arr[0]: " << arr[0] << std::endl;  // should be 0
    std::cout << "copy arr[0]:     " << copy[0] << std::endl; // should be 999

    std::cout << "\n--- assignment operator ---" << std::endl;
    Array<int> assigned;
    assigned = arr;
    assigned[0] = 888;
    std::cout << "original arr[0]:  " << arr[0] << std::endl;      // should be 0
    std::cout << "assigned arr[0]:  " << assigned[0] << std::endl;  // should be 888

    std::cout << "\n--- out of bounds ---" << std::endl;
    try {
        arr[99];
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- string array ---" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    return 0;
}