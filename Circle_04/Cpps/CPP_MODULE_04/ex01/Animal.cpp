/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:59:08 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/23 17:26:42 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed." << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed." << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy constractor called." << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Copy assignement operator" << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "* Generic Animal Sound *" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}