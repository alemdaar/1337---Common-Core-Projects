/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 10:52:27 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/13 21:30:12 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
#include <limits>

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
};

#endif