/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:35:16 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/25 17:47:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = NULL;
    *this = other;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
        if (this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}