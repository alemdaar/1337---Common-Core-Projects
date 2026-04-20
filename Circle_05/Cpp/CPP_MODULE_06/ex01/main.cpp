/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:06:22 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/20 20:21:43 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.name = "hasso";
    data.age  = 21;

    std::cout << "original pointer:  " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "serialized:        " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "deserialized:      " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "\nSUCCESS: pointers are equal!" << std::endl;
    else
        std::cout << "\nFAIL: pointers are not equal!" << std::endl;
    return 0;
}