/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:56:37 by oelhasso          #+#    #+#             */
/*   Updated: 2026/02/02 23:51:02 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Animal {
    protected:
        std::string name;
    public:
        void talk(std::string voice);
        void set_name(std::string given_name);
        void say_name();
    };
    
class cat : public Animal {
    private:
        std::string action;
    public:
        void say_im_cat();
        void set_cat_name(std::string cat_name);
        void say_my_name();
};

void Animal::talk (std::string voice)
{
    std::cout << "im saying " << voice << "\n";
}
void Animal::set_name(std::string given_name)
{
    this->name = given_name;   
}
void Animal::say_name()
{
    std::cout << "I am " << this->name << "\n";
}
void cat::say_im_cat()
{
    std::cout << "im a cat\n";
}
void cat::set_cat_name(std::string cat_name)
{
    this->name = cat_name;
}
void cat::say_my_name()
{
    std::cout << this->name << "\n";
}

int main ()
{
    cat sima;
    Animal bigboss;
    bigboss.talk("BIG TALK");
    bigboss.set_name("DA BIG BOSS");
    bigboss.say_name();
    sima.talk("some stuff");
    sima.say_im_cat();
    sima.set_cat_name("cattie");
    sima.say_my_name();
}