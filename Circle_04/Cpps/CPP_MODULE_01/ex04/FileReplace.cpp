/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:02:41 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/19 13:13:46 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplace.hpp"
#include <iostream>
#include <fstream>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()){
        std::cerr << "Error: Cannot open " << filename << std::endl;
        return;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        inputFile.close();
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        size_t foundPos;
        while ((foundPos = line.find(s1, pos)) != std::string::npos) {
            outputFile << line.substr(pos, foundPos - pos) << s2;
            pos = foundPos + s1.length();
        }
        outputFile << line.substr(pos);
        if (!inputFile.eof())
            outputFile << std::endl;
    }
    inputFile.close();
    outputFile.close();
}
