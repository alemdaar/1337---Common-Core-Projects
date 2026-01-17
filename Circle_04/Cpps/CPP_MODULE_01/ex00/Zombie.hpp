/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 18:19:08 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/17 16:25:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string given);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string given);
void    randomChump(std::string given);

#endif