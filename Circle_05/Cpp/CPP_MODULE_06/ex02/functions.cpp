/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 21:39:24 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/20 22:05:01 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    int r = time(NULL) % 3;

    std::cout << "r : " << r << std::endl;
    if (r == 0)
    {
        std::cout << "generated: A" << std::endl;
        return new A();
    }
    else if (r == 1)
    {
        std::cout << "generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "identified(ptr): A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "identified(ptr): B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "identified(ptr): C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "identified(ref): A" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "identified(ref): B" << std::endl;
        return;
    } catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "identified(ref): C" << std::endl;
        return;
    } catch (...) {}
}