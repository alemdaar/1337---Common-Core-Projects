/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:38:51 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/08 21:56:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm* rrf;

    std::cout << "--- Test 1: Successful Creation (Robotomy) ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 2: Successful Creation (Shrubbery) ---" << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 3: Successful Creation (Pardon) ---" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Fry");
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test 4: Unknown Form (The Failure Case) ---" << std::endl;
    rrf = someRandomIntern.makeForm("world domination", "Evil Villain");
    if (!rrf) {
        std::cout << "Correct: Intern couldn't create an unknown form." << std::endl;
    }

    return 0;
}