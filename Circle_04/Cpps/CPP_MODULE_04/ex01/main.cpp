/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:59:06 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/23 17:06:29 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "--- SUBJECT BASIC TEST ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

    std::cout << "\n--- ARRAY TEST (Half Dogs, Half Cats) ---" << std::endl;
    const int count = 4;
    Animal* animals[count];

    for (int k = 0; k < count; k++) {
        if (k < count / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    for (int k = 0; k < count; k++) {
        delete animals[k];
    }

    std::cout << "\n--- DEEP COPY TEST ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }

    std::cout << "Basic is still alive and has its brain!" << std::endl;

    return 0;
}
