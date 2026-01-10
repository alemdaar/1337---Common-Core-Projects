#include "header.hpp"

int main (int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "the number of arguments isnt 4\n";
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (filename == "" || s1 == "" || s2 == "")
    {
        std::cerr << "one of the arguments is empty\n";
        return 1;
    }
}