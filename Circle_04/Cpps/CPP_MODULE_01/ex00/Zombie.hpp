/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:19:08 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/02 18:47:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string name;
public:
    Zombie();
    void announce(void);
    void nameZombie(std::string name);
    ~Zombie();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
