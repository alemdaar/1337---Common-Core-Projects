/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:14:27 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/08 21:56:11 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) {(void)other;}
Intern& Intern::operator=(const Intern& other) {(void)other; return *this;}
Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* forms[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    AForm* result = NULL;
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            result = forms[i];
        } else {
            delete forms[i];
        }
    }

    if (!result)
        std::cout << "Error: Intern cannot create " << name << " because it doesn't exist." << std::endl;
    
    return result;
}