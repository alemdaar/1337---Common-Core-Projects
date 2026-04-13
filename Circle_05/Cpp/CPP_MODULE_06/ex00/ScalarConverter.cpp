/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:16:49 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/13 21:42:17 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// #include <cstdlib> // for strtod
// #include <climits> // for INT_MAX/MIN
// #include <iomanip> // for setprecision

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {(void)other;}
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string& input)
{
    double d = 0;
    if (input.length() == 1 && !input.isdigit())
    {
        if ((input >= 0 && input <= 31) || input == 127)
            std::err << "" << 
        char c = input;
        std ::cout << c;
    }
}