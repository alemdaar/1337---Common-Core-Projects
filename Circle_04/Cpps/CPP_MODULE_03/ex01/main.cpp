/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:56:37 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/06 22:36:42 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Creating ClapTrap ---" << std::endl;
    ClapTrap clap("Basic-Bot");
    
    std::cout << "\n--- Creating ScavTrap ---" << std::endl;
    ScavTrap scav("Sergeant-Scav");

    std::cout << "\n--- Action Tests ---" << std::endl;
    scav.attack("a bandit");
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- Destruction ---" << std::endl;
    return 0;
}