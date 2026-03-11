/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:29:05 by oelhasso          #+#    #+#             */
/*   Updated: 2026/03/11 17:46:05 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat boss("The Boss", 1);
        Bureaucrat intern("The Intern", 150);
        Form taxForm("Tax-24B", 50, 50);

        std::cout << taxForm << std::endl;

        intern.signForm(taxForm); // Should fail
        boss.signForm(taxForm);   // Should succeed

        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Main catch: " << e.what() << std::endl;
    }
    return 0;
}