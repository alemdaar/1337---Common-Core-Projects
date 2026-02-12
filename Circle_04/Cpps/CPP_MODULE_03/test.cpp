#include <iostream>
#include <string>

class head {
    protected:
        int priv_var;
    public:
        head();
        int pub_var;
        void    set_priv_var(int value);
        int     get_priv_var(void);
        ~head();
};

class child : public head {
    // public:
    //     child();
    //     ~child();

};

head::head()
{
    std::cout << "Calling head!\n";
}
head::~head()
{
    // size_t i = 0;
    // while (i < 3999999999)
    // {
    //     i++;
    // }
    std::cout << "ending head!\n";
}
// child::child()
// {
//     std::cout << "calling child!\n";
// }
// child::~child()
// {
//     std::cout << "ending child!\n";
// }
void    head::set_priv_var(int value)
{
    std::cout << "setting private var to : " << value << "\n";
    priv_var = value;
}
int     head::get_priv_var(void)
{
    std::cout << "getting private var\n";
    return priv_var;
}

int main ()
{
    head a;
    child c;
    {
        a.pub_var = 8;
        std::cout << "the public var is : " << a.pub_var << "\n";
        a.set_priv_var(15);
        int x = a.get_priv_var();
        std::cout << "the number we got is : " << x << "\n";
        std::cout << "-------------------\n";
        c.pub_var = 1;
        std::cout << "the public var is : " << c.pub_var << "\n";
        c.set_priv_var(5);
        x = c.get_priv_var();
        std::cout << "the number we got is : " << x << "\n";
    } // 
    std::cout << "tested \n";
}



// public in inherited class
// 