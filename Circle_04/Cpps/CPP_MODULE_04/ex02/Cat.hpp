/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:20:49 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/25 17:20:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* _brain;

public:
    Cat();
    virtual ~Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    virtual void makeSound() const;
};

#endif