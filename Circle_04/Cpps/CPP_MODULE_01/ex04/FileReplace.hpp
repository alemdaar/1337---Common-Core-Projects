/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:29:50 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/15 20:49:15 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILEREPLACE_HPP
#define FILEREPLACE_HPP

#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2);

#endif