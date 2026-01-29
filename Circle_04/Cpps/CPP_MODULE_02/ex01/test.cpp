#include <iostream>
#include <string>



class ex
{
    private:
        int x;
    public:
        ex();
        ex(const ex &other);
        ex &operator=(const ex &other);
        ~ex();
};

ex::ex()
{
    std::out << "copy constractor called \n";
    return ;
}

ex::ex(const ex &other)
{
    this->x = other.x;
    return ;
}
ex &ex::operator=(const ex &other)
{
    
}

ex::~ex()
{
    std::cout << "destructor";
    return ;
}

int main ()
{
    
}