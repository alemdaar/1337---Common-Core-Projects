/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:17:42 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/17 20:48:22 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 0;
    
    Zombie* horde = zombieHorde(N, "Soldier");
    if (horde == NULL)
        return 1;
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete[] horde;
    std::cout << "all classes have been deleted\n";
    return 0;
}