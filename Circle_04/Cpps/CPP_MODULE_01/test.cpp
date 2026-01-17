#include <iostream>
#include <string>

class a{
    private:
        std::string str1;
    public:
        void set_s1(std::string given);
};

void a::set_s1(std::string given)
{
    str1 = given;
    return ;
}
int main ()
{
    a cl;
    cl.set_s1("hi");
    a *p = NULL;
    delete p;
    return 0;
}
