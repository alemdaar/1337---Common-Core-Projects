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
#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>

static bool isPseudo(const std::string &s) {
    return s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff";
}

static bool isChar(const std::string &s) {
    if (s.length() == 1 && !std::isdigit(s[0]))
        return true;
    return false;
}

static bool isInt(const std::string &s) {
    size_t pos;
    try {
        std::stoll(s, &pos);
        return pos == s.size();
    } catch (...) { return false; }
}

static bool isFloat(const std::string &s) {
    if (s[s.size() - 1] != 'f')
        return false;
    std::string without_f = s.substr(0, s.size() - 1);
    size_t pos;
    try {
        std::stod(without_f, &pos);
        return pos == without_f.size();
    } catch (...) { return false; }
}

static bool isDouble(const std::string &s) {
    size_t pos;
    try {
        std::stod(s, &pos);
        return pos == s.size();
    } catch (...) { return false; }
}


static void displayChar(double d) {
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void displayInt(double d) {
    if (std::isnan(d) || std::isinf(d)
        || d < static_cast<double>(INT_MIN)
        || d > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void displayFloat(double d) {
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(d))
        std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
    else {
        float f = static_cast<float>(d);
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

static void displayDouble(double d) {
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

static void displayAll(double d) {
    displayChar(d);
    displayInt(d);
    displayFloat(d);
    displayDouble(d);
}

static void displayImpossible() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


void ScalarConverter::convert(const std::string &literal) {
    if (isPseudo(literal)) {
        double d;
        std::string s = literal;
        if (s == "nan" || s == "nanf")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (s == "+inf" || s == "+inff")
            d = std::numeric_limits<double>::infinity();
        else //if (s == "-inf" || s == "-inff")
            d = -std::numeric_limits<double>::infinity();
        std::cout << "d is : " << d << std::endl;
        displayAll(d);
    }
    else if (isChar(literal)) {
        char c = (literal.length() == 1) ? literal[0] : literal[1];
        double d = static_cast<double>(c);
        displayAll(d);
    }
    else if (isInt(literal)) {
        long long n = std::stoll(literal);
        double d = static_cast<double>(n);
        displayAll(d);
    }
    else if (isFloat(literal)) {
        float f = std::stof(literal);
        double d = static_cast<double>(f);
        displayAll(d);
    }
    else if (isDouble(literal)) {
        double d = std::stod(literal);
        displayAll(d);
    }
    else
        displayImpossible();
}