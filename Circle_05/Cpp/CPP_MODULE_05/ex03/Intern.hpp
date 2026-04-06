/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:46:11 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/06 20:48:32 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const std::string target);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
};

#endif