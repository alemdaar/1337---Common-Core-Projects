/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:20:20 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/25 17:20:31 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* _brain;
public:
    Dog();
    virtual ~Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    virtual void makeSound() const;
};

#endif