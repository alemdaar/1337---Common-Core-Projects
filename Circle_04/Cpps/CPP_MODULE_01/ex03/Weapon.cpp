/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:53:16 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/07 20:18:09 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
    return this->_type;
}

void Weapon::setType(std::string newType) {
    this->_type = newType;
}