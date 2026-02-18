/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imple.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:59:08 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/18 15:58:04 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Animal::Animal ()
{
    std::cout << type << "Deafult constractur called\n";
}

Animal::~Animal ()
{
    std::cout  << type << "Destroctur called \n";
}

Animal::Animal (const Animal &other)
{
    std::cout << type  << "copy constructor called !\n";
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << type  << "copy assignemet operator called !\n";    
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

void Animal::makeSound()
{
    std::cout << type  << "Animal is making sound !\n";
}

Dog::Dog ()
{
    std::cout  << type << "default constructor called \n";
}

Dog::~Dog ()
{
    std::cout  << type << "destructor called \n";
}

Dog::Dog (const Dog &other)
{
    std::cout << type << "Copy constructor called\n";
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << type << "copy assignemet operator called\n";
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}


void Animal::makeSound()
{
    std::cout << type  << "Animal is making sound !\n";
}
