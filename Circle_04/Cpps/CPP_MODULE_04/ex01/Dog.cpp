/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:35:16 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/23 17:05:59 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructed." << std::endl;
    this->type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destroyed." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_brain = NULL;
    *this = other; 
}

Dog& Dog::operator=(const Dog& other) {
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