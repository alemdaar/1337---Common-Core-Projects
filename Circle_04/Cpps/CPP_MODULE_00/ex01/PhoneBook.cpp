/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:52:43 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/31 16:40:31 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), count(0) {}

void PhoneBook::addContact()
{
    std::string fn, ln, nn, pn, ds;

    std::cout << "First name: ";
    std::getline(std::cin, fn);
    if (fn == "")
    {
        std::cout << "First name field is empty !" << std::endl;
        return ;
    }
    std::cout << "Last name: ";
    std::getline(std::cin, ln);
    if (ln == "")
    {
        std::cout << "Last name field is empty !" << std::endl;
        return ;
    }
    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    if (nn == "")
    {
        std::cout << "Nickname field is empty !" << std::endl;
        return ;
    }
    std::cout << "Phone number: ";
    std::getline(std::cin, pn);
    if (pn == "")
    {
        std::cout << "Phone number field is empty !" << std::endl;
        return ;
    }
    std::cout << "Darkest secret: ";
    std::getline(std::cin, ds);
    if (ds == "")
    {
        std::cout << "Darkest Secret field is empty !" << std::endl;
        return ;
    }

    contacts[index].setContact(fn, ln, nn, pn, ds);

    index = (index + 1) % 8;
    if (count < 8)
        count++;
    std::cout << "Darkest secret: ";
}

static std::string truncate(std::string s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

void PhoneBook::searchContact() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Index: ";
    int i;
    std::cin >> i;
    std::cin.ignore();

    if (i >= 0 && i < count)
    {
        std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
        std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
        std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
    }
}
