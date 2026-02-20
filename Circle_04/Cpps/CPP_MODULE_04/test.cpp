/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:53:22 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/20 17:29:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class base {
    private:
        int var;
    public:
        base();
        void set_value (int given);
        int get_value ();
};

class child : public base {};

base::base ()
{
    // std::cout << "the var is : \'" << var << "\' \n";
}
void base::set_value (int given)
{
    var = given;
}

int base::get_value ()
{
    return var;    
}


int main ()
{
    child c;
    base b;
    b.set_value(1);
    int x = b.get_value();
    c.set_value(2);
    int y = c.get_value();
    std::cout << "the base var is : \'" << x << "\' \n";
    std::cout << "the child var is : \'" << y << "\' \n";
}