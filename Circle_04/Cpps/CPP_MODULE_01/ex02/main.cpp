/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:34:57 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/18 16:10:48 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "* Addresses *\n";
    std::cout << "Address of string variable:  " << &str << std::endl;
    std::cout << "Address held by stringPTR:   " << stringPTR << std::endl;
    std::cout << "Address held by stringREF:   " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "* Values *\n";
    std::cout << "Value of string variable:    " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}
