/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:09:14 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/02 18:47:57 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : {};
void Zombie::nameZombie(std::string given)
{
    name = given;
}

void Zombie::announce(void)
{
    std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie* z = new Zombie();
    z->nameZombie(name);
    return z;
}

void randomChump(std::string name)
{
    Zombie z;
    z.nameZombie(name);
    z.announce();
}
