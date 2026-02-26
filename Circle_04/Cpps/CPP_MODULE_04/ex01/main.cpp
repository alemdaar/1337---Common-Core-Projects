/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:59:06 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/25 20:24:05 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;

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
        std::cout << "Tmp dog created and about to go out of scope." << std::endl;
    }

    std::cout << "Basic is still alive and has its brain!" << std::endl;

    return 0;
}
