/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:53:22 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/06 18:00:23 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead and can't attack!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }

    this->_energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0 || this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " can't repair itself (dead or no energy)!" << std::endl;
        return;
    }

    this->_energyPoints -= 1;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " points! Health is now " << _hitPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed! Stop hitting it!" << std::endl;
        return;
    }

    if (amount >= (unsigned int)this->_hitPoints) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }

    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " points of damage! Current HP: " << _hitPoints << std::endl;

    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has died!" << std::endl;
    }
}
