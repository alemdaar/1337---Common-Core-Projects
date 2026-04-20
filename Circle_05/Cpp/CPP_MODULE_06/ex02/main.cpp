/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 20:31:51 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/20 21:39:43 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "functions.hpp"

int main() {
    Base* p = generate();

    identify(p);
    identify(*p);

    delete p;
    return 0;
}