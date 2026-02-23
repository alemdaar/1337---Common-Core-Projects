/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:42:39 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/23 17:02:16 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructed." << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called." << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}