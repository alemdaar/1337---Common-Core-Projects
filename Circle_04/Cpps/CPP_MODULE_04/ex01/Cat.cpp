/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:38:32 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/23 17:05:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = NULL;
    *this = other;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}