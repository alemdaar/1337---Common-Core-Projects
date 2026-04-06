/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:38:51 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/06 20:33:39 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("The Boss", 1);
        Bureaucrat assistant("The Assistant", 45);
        Bureaucrat intern("The Intern", 150);

        std::cout << "--- Initializing Forms ---" << std::endl;
        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n--- Testing Shrubbery (Sign: 145, Exec: 137) ---" << std::endl;
        intern.signForm(shrub);    // Should fail (Intern is 150)
        assistant.signForm(shrub); // Should succeed
        assistant.executeForm(shrub); // Should succeed (Creates Home_shrubbery)

        std::cout << "\n--- Testing Robotomy (Sign: 72, Exec: 45) ---" << std::endl;
        assistant.signForm(robot);   // Should succeed
        assistant.executeForm(robot); // Should succeed/fail (50% chance)
        assistant.executeForm(robot); // Should do the opposite (because of your 'static' logic)

        std::cout << "\n--- Testing Presidential Pardon (Sign: 25, Exec: 5) ---" << std::endl;
        assistant.signForm(pardon); // Should fail (Assistant is 45)
        boss.signForm(pardon);      // Should succeed
        boss.executeForm(pardon);   // Should succeed

        std::cout << "\n--- Testing Execution without Signing ---" << std::endl;
        PresidentialPardonForm unsignedPardon("Criminal");
        boss.executeForm(unsignedPardon); // Should fail (FormNotSignedException)

    } catch (std::exception &e) {
        // This catches any constructor-level grade errors
        std::cerr << "Global Catch: " << e.what() << std::endl;
    }

    return 0;
}