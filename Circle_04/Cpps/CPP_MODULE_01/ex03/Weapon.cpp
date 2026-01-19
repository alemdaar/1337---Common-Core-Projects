/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:53:16 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/19 11:12:17 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string given_type) : type(given_type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
    return this->type;
}

void Weapon::setType(std::string newType) {
    this->type = newType;
}