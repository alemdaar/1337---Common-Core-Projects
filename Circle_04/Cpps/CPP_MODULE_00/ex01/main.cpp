/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:19:18 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/30 18:13:50 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phonebook;
    std::string cmd;
    int rt;

    while (1)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\ncouldnt read !"<<std::endl;
            break;
        }
        if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else if (cmd == "EXIT")
            break;
        // else
        //     std::cout << std::endl;
    }

    return 0;
}
