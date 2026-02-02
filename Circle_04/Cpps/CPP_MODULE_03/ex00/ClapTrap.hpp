/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:47:39 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/02 17:56:20 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Parent_class {
    protected:
        int protected_variable;
    public:
        Parent_class();
        ~Parent_class();
        // --
        set_parent(int value);
        get_parent();
        int public_variable;
};

class child : public Parent_class {
    
};