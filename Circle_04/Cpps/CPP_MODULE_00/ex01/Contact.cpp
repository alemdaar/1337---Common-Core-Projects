/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:52:21 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/31 16:36:57 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    firstName = fn;
    lastName = ln;
    nickname = nn;
    phoneNumber = pn;
    darkestSecret = ds;
}

std::string Contact::getFirstName() const
{
    return firstName;
}
std::string Contact::getLastName() const
{
    return lastName;
}
std::string Contact::getNickname() const
{
    return nickname;
}
std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}
std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}
