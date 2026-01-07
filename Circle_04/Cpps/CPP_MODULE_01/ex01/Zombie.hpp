/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:46:18 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/07 11:55:16 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie {
    private:
        std::string ZombieName;
    public:
        Zombie();
        void setName(std::string name);
        void announce(void);
        ~Zombie();
};

Zombie* zombieHorde( int N, std::string name );