/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:17:42 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/07 12:43:50 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;
    
    // Create the horde
    Zombie* horde = zombieHorde(N, "Soldier");

    // Make them all announce
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    // IMPORTANT: Use delete[] for arrays!
    delete[] horde;
    std::cout << "all classes have been deleted\n";

    return 0;
}