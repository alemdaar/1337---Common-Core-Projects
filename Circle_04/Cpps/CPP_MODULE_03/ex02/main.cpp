/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:56:37 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/11 16:13:56 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "--- Creating FragTrap ---" << std::endl;
    FragTrap frag("FT-99");

    frag.attack("a random bandit");
    frag.takeDamage(50);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "--- Destructors below ---" << std::endl;
    return 0;
}