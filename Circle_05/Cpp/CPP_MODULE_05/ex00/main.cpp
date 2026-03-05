/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:29:05 by oelhasso          #+#    #+#             */
/*   Updated: 2026/03/05 01:30:26 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        
        bob.incrementGrade();
        std::cout << bob << std::endl;
        
        bob.incrementGrade();
        std::cout << "This line will never print." << std::endl;
    }
    catch (std::exception & e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat badGuy("Villain", 160);
    }
    catch (std::exception & e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
