#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout << "--- vector ---" << std::endl;
    try {
        std::cout << "found: " << easyfind(v, 3) << std::endl;
        std::cout << "found: " << easyfind(v, 99) << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    std::cout << "--- list ---" << std::endl;
    try {
        std::cout << "found: " << easyfind(l, 20) << std::endl;
        std::cout << "found: " << easyfind(l, 99) << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    std::cout << "--- deque ---" << std::endl;
    try {
        std::cout << "found: " << easyfind(d, 200) << std::endl;
        std::cout << "found: " << easyfind(d, 99) << std::endl;
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}