/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:16:36 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/07 12:43:12 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie ()
{
    std::cout << "the class " << ZombieName << "has created\n";
}

Zombie::~Zombie ()
{
    std::cout << "the class " << ZombieName << "is out of scope\n";
}

void Zombie::announce ()
{
    std::cout << ZombieName << " is present\n";
}

void Zombie::setName (std::string name)
{
    ZombieName = name;
}

